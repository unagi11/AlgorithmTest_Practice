#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <stdint.h>

using namespace std;

int num_edges;

int capacity[INT8_MAX][INT8_MAX] = {0};
int flow[INT8_MAX][INT8_MAX] = {0};

int main(int argc, char const *argv[])
{
    scanf("%d\n", &num_edges);

    for (int i = 0; i < num_edges; i++)
    {
        char from, to;
        int cost;
        scanf("%c %c %d\n", &from, &to, &cost);

        if (from == to)
            continue;

        capacity[from][to] += cost;
        capacity[to][from] += cost;
    }

    int answer = 0;
    bool isNoAugmentPath = false;

    while (!isNoAugmentPath)
    {
        deque<char> queue = {'A'};
        int parent[INT8_MAX] = {0};
        bool isVisited[INT8_MAX] = {false};
        isVisited['A'] = true;
        isNoAugmentPath = true;

        // DFS로 augmenting path 찾기
        while (!queue.empty())
        {
            char u = queue.front();
            queue.pop_front();

            // 목적지 Z가 아니라면
            if (u != 'Z')
            {
                for (int v = 0; v < INT8_MAX; v++)
                {
                    if (capacity[u][v] - flow[u][v] > 0 && isVisited[v] == false)
                    {
                        queue.push_back(v);
                        parent[v] = u;
                        isVisited[v] = true;
                    }
                }
            }
            // 목적지 Z에 도달했다면
            else
            {
                isNoAugmentPath = false;

                // min augment를 찾는다.
                int min_augment = INT32_MAX;
                char index = 'Z';
                while (index != 'A')
                {
                    int pred = parent[index];
                    min_augment = min(min_augment, capacity[pred][index] - flow[pred][index]);

                    index = pred;
                }
                answer += min_augment;

                index = 'Z';
                while (index != 'A')
                {
                    int pred = parent[index];
                    flow[pred][index] = flow[pred][index] + min_augment;
                    flow[index][pred] = flow[index][pred] - min_augment;
                    index = pred;
                }
                break;
            }
        }
    }

    printf("%d", answer);

    return 0;
}
