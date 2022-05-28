#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include <deque>

#define MAX_EDGES 700

using namespace std;

int num_edges;

int capacity[INT8_MAX][INT8_MAX] = {0};
int flow[INT8_MAX][INT8_MAX] = {0};
int residual[INT8_MAX][INT8_MAX] = {0};

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

    // for (int i = 'A'; i <= 'Z'; i++)
    // {
    //     for (int j = 'A'; j <= 'Z'; j++)
    //     {
    //         printf("%d ", capacity[i][j]);
    //     }
    //     printf("\n");
    // }

    int answer = 0;
    bool isNoAugmentPath = false;

    while (!isNoAugmentPath)
    {
        deque<char> queue = {'A'};
        int parent[INT8_MAX] = {0};
        bool isVisited[INT8_MAX] = {false};
        isVisited['A'] = true;
        isNoAugmentPath = true;

        // DFS로 augment path 찾기
        while (!queue.empty())
        {

            for (char i : queue)
                printf("%c ", i);
            printf("\n");

            char u = queue.front();
            queue.pop_front();
            printf("hello %c\n", u);

            // 목적지 Z가 아니라면
            if (u != 'Z')
            {
                for (int v = 0; v < INT8_MAX; v++)
                {
                    if (capacity[u][v] - flow[u][v] > 0 && isVisited[v] == false)
                    {
                        // printf("?%c ", v);
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
                    // printf("%c ", index);
                    int pred = parent[index];
                    printf("(%c,%c) c%d f%d\n", pred, index, capacity[pred][index], flow[pred][index]);
                    min_augment = min(min_augment, capacity[pred][index] - flow[pred][index]);

                    index = pred;
                }
                printf("\n");
                answer += min_augment;
                printf("min augment %d\n", min_augment);

                index = 'Z';
                while (index != 'A')
                {
                    printf("%c ", index);
                    int pred = parent[index];
                    flow[pred][index] = flow[pred][index] + min_augment;
                    flow[index][pred] = flow[index][pred] - min_augment;
                    index = pred;
                }
                printf("\n");

                break;
            }
        }
    }

    printf("answer %d", answer);

    return 0;
}
