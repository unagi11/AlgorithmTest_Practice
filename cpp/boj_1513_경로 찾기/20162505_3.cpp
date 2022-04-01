#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#define MAX 51
#define MOD 1'000'007

using namespace std;

int rows, cols, pivotCnt;
vector<tuple<int, int>> pivots;

// pathCnts[y][x][i][j] :
// 오락실을 j 번 들리고
// 마지막으로 도달했던 오락실이 i번째이며
// (y,x)에 도달하는 횟수
int pathCnts[MAX][MAX][MAX][MAX] = {0};
// 기록 되었는가?
bool isRecorded[MAX][MAX][MAX][MAX] = {false};

int getPathCnt(int y, int x, int i, int j)
{
    if (isRecorded[y][x][i][j] == true)
        return pathCnts[y][x][i][j];
    if (y < 1 || x < 1 || y > rows || x > cols)
        return 0;

    int temp = 0;
    int index = find(pivots.begin(), pivots.end(), make_tuple(y, x)) - pivots.begin();

    // (y, x)가 오락실이라면?
    if (index != pivots.size())
    {
        // 현재 마지막으로 방문한 오락실이 i 이고, 그게 현재 위치와 일치하지 않을경우 모순이므로 0.
        if (index == i)
        {
            for (int n = j - 1; n < index; n++)
            {
                temp += (getPathCnt(y, x - 1, n, j - 1) + getPathCnt(y - 1, x, n, j - 1)) % MOD;
            }
        }
    }
    // (y, x)가 오락실이 아니라면
    else
        temp = (getPathCnt(y, x - 1, i, j) + getPathCnt(y - 1, x, i, j)) % MOD;

    pathCnts[y][x][i][j] = temp;
    isRecorded[y][x][i][j] = true;
    return pathCnts[y][x][i][j];
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &rows, &cols, &pivotCnt);

    vector<int>(pivotCnt + 1, 0);

    pivots.push_back(make_tuple(-1, -1));
    for (int i = 0; i < pivotCnt; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        pivots.push_back(make_tuple(y, x));
    }

    int lastIdx = 0;
    int count = 0;
    for (int y = 1; y <= rows; y++)
    {
        int index = find(pivots.begin(), pivots.end(), make_tuple(y, 1)) - pivots.begin();

        if (index != pivots.size())
        {
            count++;
            lastIdx = index;
            pathCnts[y][1][lastIdx][count] = 1;
            isRecorded[y][1][lastIdx][count] = true;
        }
        else
        {
            pathCnts[y][1][lastIdx][count] = 1;
            isRecorded[y][1][lastIdx][count] = true;
        }
    }

    lastIdx = 0;
    count = 0;
    for (int x = 1; x <= cols; x++)
    {
        int index = find(pivots.begin(), pivots.end(), make_tuple(1, x)) - pivots.begin();

        if (index != pivots.size())
        {
            count++;
            lastIdx = index;
            pathCnts[1][x][lastIdx][count] = 1;
            isRecorded[1][x][lastIdx][count] = true;
        }
        else
        {
            pathCnts[1][x][lastIdx][count] = 1;
            isRecorded[1][x][lastIdx][count] = true;
        }
    }

    // printf("\n");
    // for (int y = 1; y <= rows; y++)
    // {
    //     for (int x = 1; x <= cols; x++)
    //     {
    //         for (int j = 0; j <= pivotCnt; j++)
    //         {
    //             printf("j%d:", j);
    //             for (int i = j; i <= pivotCnt; i++)
    //             {
    //                 printf("%d ", pathCnts[y][x][i][j]);
    //             }
    //             printf(" ");
    //         }
    //         printf("|  ");
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // for (int y = 1; y <= rows; y++)
    // {
    //     for (int x = 1; x <= cols; x++)
    //     {
    //         for (int j = 0; j <= pivotCnt; j++)
    //         {
    //             printf("j%d:", j);
    //             for (int i = j; i <= pivotCnt; i++)
    //             {
    //                 printf("%d ", getPathCnt(y, x, i, j));
    //             }
    //             printf(" ");
    //         }
    //         printf("|  ");
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    for (int j = 0; j <= pivotCnt; j++)
    {
        int temp = 0;
        for (int i = j; i <= pivotCnt; i++)
        {
            // printf("%d %d %d %d + ", rows, cols, i, j);
            temp = (temp + getPathCnt(rows, cols, i, j)) % MOD;
        }
        printf("%d ", temp);
        // printf("\n");
    }

    // pathCnts[3][2][2][1] = 1;

    return 0;
}