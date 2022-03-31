#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
// #include <set>

using namespace std;

int rows, cols, pivotCnt;
vector<tuple<int, int>> pivots;
vector<int> pathCnt;

void dfs(int y, int x, int cost, int lastPivot)
{
    if (y > rows || x > cols)
        return;

    int index = find(pivots.begin(), pivots.end(), make_tuple(y, x)) - pivots.begin();

    // 이곳은 오락실이다.
    if (index != pivotCnt)
    {
        // 이전에 방문했던 오락실보다 번호가 작은 오락실이면 방문 불가
        if (index < lastPivot)
            return;
        // 아니면 방문 가능
        cost++;
        lastPivot = index;
    }

    if (y == rows && x == cols)
    {
        // printf("isEnd! cost: %d\n", cost);
        pathCnt[cost]++;
        pathCnt[cost] %= 1'000'007;
    }

    dfs(y + 1, x, cost, lastPivot); // 아래로..
    dfs(y, x + 1, cost, lastPivot); // 옆으로..
}

int main(int argc, char const *argv[])
{

    scanf("%d %d %d", &rows, &cols, &pivotCnt);
    // printf("%d %d %d\n", rows, cols, pivotCnt);

    pathCnt = vector<int>(pivotCnt + 1, 0);
    for (int i = 0; i < pivotCnt; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        // printf("%d %d\n", y, x);
        pivots.push_back(make_tuple(y, x));
    }

    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = 1; j <= cols; j++)
    //     {
    //         printf("(%d %d)", i, j);

    //         auto it = pivots.find(make_tuple(i, j));

    //         if (it == pivots.end())
    //             printf("%c ", 'O');
    //         else
    //             printf("%c ", 'X');
    //     }
    //     printf("\n");
    // }

    // 위치 : (1, 1)
    // Cost : 0
    // lastPivot : -1
    dfs(1, 1, 0, -1);

    for (int i = 0; i <= pivotCnt; i++)
    {
        printf("%d ", pathCnt[i]);
    }

    return 0;
}