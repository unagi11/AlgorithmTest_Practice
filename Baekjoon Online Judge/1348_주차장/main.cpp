#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <stdint.h>

using namespace std;
typedef pair<int, int> int2;

int rows, cols;

vector<vector<char>> matrix;

int num_cars = 0, num_parks = 0;
vector<int2> cars, parks;
map<int2, int> park_index;

vector<vector<int>> edge; // edge[car][park] : car에서 park 까지의 비용
vector<bool> visited;
vector<int> match;

bool bipartitie_matching(int car, int cost)
{
    if (visited[car])
        return false;

    visited[car] = true;

    for (int park = 0; park < edge[car].size(); park++)
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
                park_index.insert({{i, j}, num_parks});
                num_parks++;
                parks.push_back({i, j});
            }
        }
        scanf("\n");
    }

    edge = vector<vector<int>>(num_cars, vector<int>(num_parks, INT32_MAX));

    int2 directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < num_cars; i++)
    {
        vector<int2> queue = {cars[i]};
        vector<int2> frontier = {};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int distance = 0;

        // 더이상 갈수있는 점이 없을때까지 반복한다.
        while (!queue.empty())
        {
            for (auto position : queue)
            {
                visited[position.first][position.second] = true;

                if (matrix[position.first][position.second] == 'P')
                    edge[i][park_index.find(position)->second] = distance;

                for (int2 direction : directions)
                {
                    int2 temp = {position.first + direction.first, position.second + direction.second};

                    // 맵 범위 초과 혹은
                    // 방문한 곳 혹은
                    // X인곳 이면
                    // frontier에 넣지 않는다.
                    if (temp.first < 0 || temp.first >= rows ||
                        temp.second < 0 || temp.second >= cols ||
                        visited[temp.first][temp.second] ||
                        matrix[temp.first][temp.second] == 'X')
                        continue;
                    else
                    {
                        visited[temp.first][temp.second] = true;
                        frontier.push_back(temp);
                    }
                }
            }

            distance++;
            queue = frontier;
            frontier.clear();
        }
    }

    int left = edge[0][0];
    int right = edge[0][0];
    bool valid = false;

    for (int i = 0; i < edge.size(); i++)
        for (int j = 0; j < edge[i].size(); j++)
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
        {
            right = pivot;
            valid = true;
        }
        // 불가능하다면 더 높은 코스트에서 찾는다.
        else
            left = pivot + 1;
    }

    printf("%d", valid ? right : -1);

    return 0;
}
