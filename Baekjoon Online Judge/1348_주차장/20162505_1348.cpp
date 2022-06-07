#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define MAX_DIST 2501

using namespace std;
typedef pair<int, int> int2;

int rows, cols;

vector<vector<char>> matrix; // matrix[rows][cols]

int num_cars = 0, num_parks = 0;
vector<int2> cars, parks;
vector<vector<int>> park_index;

vector<vector<int>> edge; // edge[car][park] : car에서 park 까지의 비용
vector<bool> visited;
vector<int> match;

bool bipartitie_matching(int car, int cost)
{
    if (visited[car])
        return false;

    visited[car] = true;

    for (int park = 0; park < num_parks; park++)
    {
        if (edge[car][park] > cost)
            continue;
        if (match[park] == -1 || bipartitie_matching(match[park], cost))
        {
            match[park] = car;
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &rows, &cols);

    matrix = vector<vector<char>>(rows, vector<char>(cols, ' '));
    park_index = vector<vector<int>>(rows, vector<int>(cols, -1));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%c", &matrix[i][j]);
            if (matrix[i][j] == 'C')
            {
                num_cars++;
                cars.push_back({i, j});
            }
            else if (matrix[i][j] == 'P')
            {
                num_parks++;
                parks.push_back({i, j});
            }
        }
        scanf("\n");
    }

    if (num_cars == 0)
    {
        printf("0");
        exit(0);
    }

    for (int i = 0; i < parks.size(); i++)
    {
        int2 park = parks[i];
        park_index[park.first][park.second] = i;
    }

    edge = vector<vector<int>>(num_cars, vector<int>(num_parks + 1, MAX_DIST));

    int2 directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < num_cars; i++)
    {
        vector<int2> queue = {cars[i]};
        vector<int2> frontier = {};
        vector<vector<bool>> queued(rows, vector<bool>(cols, false));

        queued[cars[i].first][cars[i].second] = true;
        int distance = 0;

        // 더이상 갈수있는 점이 없을때까지 반복한다.
        while (!queue.empty())
        {
            for (int j = 0; j < queue.size(); j++)
            {
                int2 position = queue[j];

                if (matrix[position.first][position.second] == 'P')
                    edge[i][park_index[position.first][position.second]] = distance;

                for (int k = 0; k < 4; k++)
                {
                    int2 direction = directions[k];
                    int2 temp = {position.first + direction.first, position.second + direction.second};

                    if (temp.first < 0 || temp.first >= rows ||
                        temp.second < 0 || temp.second >= cols ||
                        queued[temp.first][temp.second] ||
                        matrix[temp.first][temp.second] == 'X')
                        continue;
                    else
                    {
                        queued[temp.first][temp.second] = true;
                        frontier.push_back(temp);
                    }
                }
            }

            distance++;
            queue = frontier;
            frontier.clear();
        }
    }

    // for (int i = 0; i < edge.size(); i++)
    // {
    //     for (int j = 0; j < edge[i].size(); j++)
    //     {
    //         printf("%d ", edge[i][j]);
    //     }
    //     printf("\n");
    // }

#pragma region 이분 탐색
    int left = edge[0][0];
    int right = edge[0][0];

    for (int i = 0; i < num_cars; i++)
        for (int j = 0; j < num_parks; j++)
        {
            left = min(left, edge[i][j]);
            right = max(right, edge[i][j]);
        }

    while (left < right)
    {
        int pivot = (left + right) / 2;

        match = vector<int>(num_parks, -1);
        int possible = 0;

        for (int i = 0; i < num_cars; i++)
        {
            visited = vector<bool>(num_cars, false);
            if (bipartitie_matching(i, pivot))
                possible++;
        }

        // 가능하다면 최소 코스트를 찾는다.
        if (possible == num_cars)
            right = pivot;
        // 불가능하다면 더 높은 코스트에서 찾는다.
        else
            left = pivot + 1;
    }
    
#pragma endregion

    match = vector<int>(num_parks, -1);
    int possible = 0;
    for (int i = 0; i < num_cars; i++)
    {
        visited = vector<bool>(num_cars, false);
        if (bipartitie_matching(i, right))
            possible++;
    }

    printf("%d", right != MAX_DIST && possible == num_cars ? right : -1);

    return 0;
}