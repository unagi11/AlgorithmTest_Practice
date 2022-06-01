#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{

#pragma region 입력부분
    int rows, cols;
    scanf("%d %d\n", &rows, &cols);

    vector<vector<int>> apples(rows + 2, vector<int>(cols + 1, 0));
    vector<vector<int>> bananas(rows + 2, vector<int>(cols + 1, 0));

    char c;
    int n;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            scanf("%c%d ", &c, &n);

            if (c == 'A')
                apples[i][j] = n;
            if (c == 'B')
                bananas[i][j] = n;
        }
    }

    // printf("apples\n");
    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = 1; j <= cols; j++)
    //         printf("%d ", apples[i][j]);
    //     printf("\n");
    // }
    // printf("\n");

    // printf("bananas\n");
    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = 1; j <= cols; j++)
    //         printf("%d ", bananas[i][j]);
    //     printf("\n");
    // }
    // printf("\n");

#pragma endregion

#pragma region 합계 계산
    // 미리좀 계산해놓기
    vector<vector<int>> sum_a(rows + 2, vector<int>(cols + 1, 0));
    vector<vector<int>> sum_b(rows + 2, vector<int>(cols + 1, 0));

    for (int x = 1; x <= cols; x++)
    {
        for (int y = 1; y <= rows; y++)
            sum_b[y][x] = sum_b[y - 1][x] + bananas[y - 1][x];

        for (int y = rows; y >= 1; y--)
            sum_a[y][x] = sum_a[y + 1][x] + apples[y + 1][x];
    }

    // printf("apples sum\n");
    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = 1; j <= cols; j++)
    //     {
    //         printf("%d ", sum_a[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // printf("babanas sum\n");
    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = 1; j <= cols; j++)
    //     {
    //         printf("%d ", sum_b[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

#pragma endregion

#pragma region 점화식
    vector<vector<int>> dp(rows + 2, vector<int>(cols + 1, 0));

    // 첫번째 열 : 위에서 내려온다.
    for (int y = 1; y <= rows; y++)
        dp[y][1] = sum_a[y][1];

    // 첫번째 행 : 옆에서 온다.
    for (int x = 1; x <= cols; x++)
        dp[1][x] = dp[1][x - 1] + sum_a[1][x];

    // printf("dp1\n");
    // for (int y = 1; y <= rows; y++)
    // {
    //     for (int x = 1; x <= cols; x++)
    //     {
    //         printf("%d ", dp[y][x]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for (int y = 2; y <= rows; y++)
    {
        for (int x = 2; x <= cols; x++)
        {
            // 위에서 내려온다.
            if (dp[y][x] < dp[y - 1][x] - apples[y][x])
                dp[y][x] = dp[y - 1][x] - apples[y][x];

            // 대각선에서 온다.
            if (dp[y][x] < dp[y - 1][x - 1] + sum_a[y][x] + sum_b[y][x])
                dp[y][x] = dp[y - 1][x - 1] + sum_a[y][x] + sum_b[y][x];

            // 옆에서 온다.
            if (dp[y][x] < dp[y][x - 1] + sum_a[y][x] + sum_b[y][x])
                dp[y][x] = dp[y][x - 1] + sum_a[y][x] + sum_b[y][x];
        }
    }

    // printf("dp2\n");
    // for (int y = 1; y <= rows; y++)
    // {
    //     for (int x = 1; x <= cols; x++)
    //     {
    //         printf("%d ", dp[y][x]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

#pragma endregion

#pragma region 출력부분
    printf("%d", dp[rows][cols]);
#pragma endregion

    return 0;
}