#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_VERTEX 101
#define MAX_EDGE 20'001

struct Edge
{
    char u, v;
    int w;
};

int NODES, EDGES;     // the number of nodes and edges
Edge edges[MAX_EDGE]; // input graph edges
int dist[MAX_VERTEX]; // dist[i] : the minimum distance from source s to node i
int pred[MAX_VERTEX]; // pred[i] : the index of the parent of node i in

void BallmanFord(int src)
{
    for (int i = 0; i <= NODES; i++)
    {
        dist[i] = __INT32_MAX__; // INFINITY
        pred[i] = -1;            // NULL
    }
    dist[src] = 0;

    // NODES-1 번 반복합니다.
    for (int i = 0; i < NODES - 1; i++)
        // 모든 EDGES들을 순회합니다.
        for (int j = 0; j < EDGES; j++)
            // start에서 u까지 거리 + edge weight < start에서 v까지 거리
            if (dist[edges[j].u] + edges[j].w < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
                pred[edges[j].v] = edges[j].u;
            }

    // ONLY WHEN you want to check to for negative cycles
    for (int j = 0; j < EDGES; j++)
        // start에서 u까지 거리 + edge weight < start에서 v까지 거리
        if (dist[edges[j].u] + edges[j].w < dist[edges[j].v])
        {
            printf("-1");
            exit(0);
        }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &NODES, &EDGES);

    for (int i = 0; i < EDGES; i++)
    {
        int u, v, w;

        scanf("%d %d %d\n", &u, &v, &w);

        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = -w; // 최대비용을 구하기위해.. 값을 반전시켰다.
    }

    int a = 0;

    BallmanFord(1);

    stack<char> s;

    int index = NODES;
    while (index != -1)
    {
        s.push(index);
        index = pred[index];
    }

    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}
