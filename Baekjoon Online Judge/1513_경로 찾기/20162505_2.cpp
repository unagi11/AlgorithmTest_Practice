#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
// #include <set>

using namespace std;

int rows, cols, pivotCnt;
vector<tuple<int, int>> pivots;
vector<vector<vector<int>>> pathCnts; // pathCnt[y][x][i] : (0,0) > (y,x) 이동중에 오락실 i회 경유 횟수

vector<int> getPathCnt(int y, int x)
{
    if (y <= 0 || x <= 0)
        return vector<int>(pivotCnt + 1, 0);

    if (pathCnts[y][x][0] != -1)
        return pathCnts[y][x];

    vector<int> down = getPathCnt(y - 1, x);
    vector<int> right = getPathCnt(y, x - 1);

    for (int i = 0; i <= pivotCnt; i++)
        pathCnts[y][x][i] = down[i] + right[i];

    int index = find(pivots.begin(), pivots.end(), make_tuple(y, x)) - pivots.begin();
    if (index != pivotCnt)
    {
        for (int i = pivotCnt; i > 0; i--)
            pathCnts[y][x][i] = pathCnts[y][x][i - 1];
        pathCnts[y][x][0] = 0;
    }

    return pathCnts[y][x];
}

int main(int argc, char const *argv[])
{

    scanf("%d %d %d", &rows, &cols, &pivotCnt);
    // printf("%d %d %d\n", rows, cols, pivotCnt);

    pathCnts = vector<vector<vector<int>>>(rows + 1, vector<vector<int>>(cols + 1, vector<int>(pivotCnt + 1, -1)));

    vector<int>(pivotCnt + 1, 0);
    for (int i = 0; i < pivotCnt; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        // printf("%d %d\n", y, x);
        pivots.push_back(make_tuple(y, x));
    }

    vector<int> pathCnt = getPathCnt(rows, cols);

    for (int i = 0; i < pathCnt.size(); i++)
    {
        printf("%d ", pathCnt[i]);
    }

    printf("\n");
    printf("\n");
    for (int y = 0; y < pathCnts.size(); y++)
    {
        for (int x = 0; x < pathCnts[y].size(); x++)
        {
            printf("(");
            for (int i = 0; i < pathCnts[y][x].size(); i++)
            {
                printf("%2d ", pathCnts[y][x][i]);
            }
            printf(") ");
        }
        printf("\n");
    }

    return 0;
}