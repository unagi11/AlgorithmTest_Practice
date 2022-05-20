// 왜 메모리 초과???

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_VERTEX 101
#define MAX_EDGE 20001

int NODES, EDGES;                            // the number of nodes and edges
pair<pair<char, char>, int> edges[MAX_EDGE]; // input graph edges
int dist[MAX_VERTEX];                        // dist[i] : the minimum distance from source s to node i
int pred[MAX_VERTEX];                        // pred[i] : the index of the parent of node i in
set<pair<char, char>> way;
vector<char> stack;

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &NODES, &EDGES);

    for (int i = 0; i < EDGES; i++)
    {
        int u, v, w;
        scanf("%d %d %d\n", &u, &v, &w);
        edges[i] = {{u, v}, -w}; // 최대비용을 구하기위해 값을 반전시켰다.
    }

    for (int i = 0; i <= NODES; i++)
    {
        dist[i] = 999999999; // INFINITY
        pred[i] = -1;        // NULL
    }
    dist[1] = 0;

    // NODES-1 번 반복합니다.
    for (int i = 0; i < NODES - 1; i++)
        // 모든 EDGES들을 순회합니다.
        for (int j = 0; j < EDGES; j++)
            // start에서 u까지 거리 + edge weight < start에서 v까지 거리
            if (dist[edges[j].first.first] + edges[j].second < dist[edges[j].first.second])
            {
                dist[edges[j].first.second] = dist[edges[j].first.first] + edges[j].second;
                pred[edges[j].first.second] = edges[j].first.first;
            }

    int index = NODES;
    while (index != -1)
    {
        stack.push_back(index);
        way.insert({pred[index], index});
        index = pred[index];
    }

    // ONLY WHEN you want to check to for negative cycles
    for (int j = 0; j < EDGES; j++)
        // start에서 u까지 거리 + edge weight < start에서 v까지 거리
        if (dist[edges[j].first.first] + edges[j].second < dist[edges[j].first.second] 
        && way.find({edges[j].first.first, edges[j].first.second}) != way.end())
        {
            printf("-1");
            exit(0);
        }

    for (int i = stack.size() - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
