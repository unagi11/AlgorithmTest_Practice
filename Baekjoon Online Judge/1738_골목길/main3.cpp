#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

#define MAX_VERTEX 101
#define MAX_EDGE 20'001

struct Edge
{
    char u, v;
    int w;
    bool visited;
};

int NODES, EDGES;     // the number of nodes and edges
Edge edges[MAX_EDGE]; // input graph edges
int dist[MAX_VERTEX]; // dist[i] : the minimum distance from source s to node i
int pred[MAX_VERTEX]; // pred[i] : the index of the parent of node i in
set<pair<char, char>> way;
deque<char> stack;
deque<char> queue;

void BallmanFord(int src)
{
    for (int i = 0; i <= NODES; i++)
    {
        dist[i] = __INT32_MAX__; // INFINITY
        pred[i] = -1;            // NULL
    }
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty())
    {
        char u = queue.front();
        queue.pop_front();

        for (int j = 0; j < EDGES; j++)
        {
            if (edges[j].u == u && dist[edges[j].u] + edges[j].w < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
                pred[edges[j].v] = edges[j].u;
                if (find(queue.begin(), queue.end(), edges[j].v) != queue.end())
                    queue.push_back(edges[j].v);
            }
        }
    }

    int count = 0;
    int index = NODES;
    while (index != -1)
    {
        count++;
        stack.push_back(index);
        way.insert({pred[index], index});
        index = pred[index];
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

    while (!stack.empty())
    {
        printf("%d ", stack.back());
        stack.pop_back();
    }

    return 0;
}
