#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_VERTEX 101
#define MAX_EDGE 20'001

struct Edge
{
    char u, v;
    int w;
};

int NODES, EDGES;           // the number of nodes and edges
Edge edges[MAX_EDGE];       // input graph edges
long long dist[MAX_VERTEX]; // dist[i] : the minimum distance from source s to node i
int pred[MAX_VERTEX];       // pred[i] : the index of the parent of node i in
set<pair<char, char>> way;
stack<char> s;

void BallmanFord(int src)
{
    for (int i = 0; i <= NODES; i++)
    {
        dist[i] = __INT32_MAX__; // INFINITY
        pred[i] = -1;            // NULL
    }
    dist[src] = 0;

    // NODES-1 번 반복합니다.
    for (int i = 0; i < 1000; i++)
        // 모든 EDGES들을 순회합니다.
        for (int j = 0; j < EDGES; j++)
            // start에서 u까지 거리 + edge weight < start에서 v까지 거리
            if (dist[edges[j].u] + edges[j].w < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
                pred[edges[j].v] = edges[j].u;
            }

    int count = 0;
    int index = NODES;
    while (index != -1)
    {
        count++;
        s.push(index);
        way.insert({pred[index], index});
        index = pred[index];

        if (count > MAX_EDGE)
        {
            printf("-1");
            exit(0);
        }
    }

    // ONLY WHEN you want to check to for negative cycles
    for (int j = 0; j < EDGES; j++)
        // start에서 u까지 거리 + edge weight < start에서 v까지 거리
        if (dist[edges[j].u] + edges[j].w < dist[edges[j].v] && way.find({edges[j].u, edges[j].v}) != way.end())
        {
            printf("-1");
            exit(0);
        }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &NODES, &EDGES);

    int u, v, w;
    for (int i = 0; i < EDGES; i++)
    {
        scanf("%d %d %d\n", &u, &v, &w);

        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = -w; // 최대비용을 구하기위해.. 값을 반전시켰다.
    }

    BallmanFord(1);

    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}
