#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int rows, cols;

vector<vector<char>> matrix;  // 초기 행렬구조
vector<vector<bool>> visited; // cc 생성 기록
vector<vector<int>> cc;       // connected component
vector<int> cc_size;          // cc 크기기록

void initializer()
{
    matrix = vector<vector<char>>(rows, vector<char>(cols));
    visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
    cc = vector<vector<int>>(rows, vector<int>(cols, 0));
    cc_size = vector<int>(1, 0);
}

// (y, x)부터 bfs순회하여 이어진 모든 점을 n으로 바꾼다.
void bfs(int y, int x, int n)
{
    // 범위를 벗어나면 cc_size를 늘리거나 bfs를 진행하지 않는다.
    if (y < 0 || y >= rows || x < 0 || x >= cols)
        return;

    // 이미 방문한, 혹은 벽인 노드라면 순회하지 않는다.
    if (visited[y][x] == true || matrix[y][x] == 1)
        return;

    // 공백이라면, 해당 n번째 공백 덩어리의 cc_size를 늘리고 한번더 bfs 순회확장한다.
    visited[y][x] = true;
    cc[y][x] = n;
    cc_size[n]++;

    // 상하좌우 탐색.
    bfs(y - 1, x, n);
    bfs(y + 1, x, n);
    bfs(y, x - 1, n);
    bfs(y, x + 1, n);
}

// 모든 매트릭스공간을 순회하며, connected component 처리를 해준다.
void initCC()
{
    int cc_index = 1;

    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            if (visited[y][x] == false && matrix[y][x] == 0)
            {
                cc_size.push_back(0);
                bfs(y, x, cc_index);
                cc_index++;
            }
}

// 범위를 넘어가는 cc를 0으로 받는 함수.
int getCC(int y, int x)
{
    if (y < 0 || y >= rows || x < 0 || x >= cols)
        return 0;
    else
        return cc[y][x];
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &rows, &cols);

    initializer();

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            scanf("%c", &matrix[y][x]);
            matrix[y][x] = matrix[y][x] - '0';
        }
        scanf("\n");
    }

    initCC();

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (matrix[y][x] == 0)
                printf("%d", 0);
            else
            {
                set<int> s;
                s.insert(getCC(y - 1, x));
                s.insert(getCC(y + 1, x));
                s.insert(getCC(y, x - 1));
                s.insert(getCC(y, x + 1));

                int temp = 1;
                set<int>::iterator iter;
                for (iter = s.begin(); iter != s.end(); iter++)
                    temp += cc_size[*iter];

                printf("%d", temp % 10);
            }
        }
        printf("\n");
    }

    return 0;
}
