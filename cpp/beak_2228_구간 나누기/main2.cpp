// chained matrix
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> numbers;
vector<int> sums;

int numberCount, divideCount;

const int MIN = -9999999;

int max(int a, int b) { return a < b ? b : a; }

// dp[numCnt][dvdCnt] - (numCnt+1)개(0 ~ numCnt)의 원소를 (dvdCnt+1)개 덩어리로 분할했을때 최대값.
// ex.) dp[0][0] - 1개 원소를 1개 덩어리로 분할
// ex.) dp[2][1] - 3개 원소를 2개 덩어리로 분할
int getDP(int numCnt, int dvdCnt)
{
    if (dvdCnt == -1)
        return 0;
    if (numCnt < 0 || numCnt + 1 < dvdCnt * 2 + 1)
        return MIN;
    if (dp[numCnt][dvdCnt] != MIN)
        return dp[numCnt][dvdCnt];

    // 점화식 : dp[0 ~ i][j] = max( dp[0 ~ i-1][j] , max( dp[0 ~ k-2][j-1] + sum[k ~ i] ) )
    // { k : 0 <= k <= numCnt }
    // 1) i번째 숫자를 포함하지 않고 최대를 만든다.
    // 2) i번째 숫자를 포함하고 최대를 만든다.  + sum[i~k] (뒷뭉탱이에 포함)
    int dpn = getDP(numCnt - 1, dvdCnt);
    for (int k = numCnt; k >= 0; k--)
        dpn = max(dpn, getDP(k - 2, dvdCnt - 1) + sums[numCnt + 1] - sums[k]);
    dp[numCnt][dvdCnt] = dpn;

    return dpn;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &numberCount, &divideCount);

    numbers = vector<int>(numberCount, 0);  // 입력한 숫자들
    sums = vector<int>(numberCount + 1, 0); // i번째 숫자까지 더한 합

    sums[0] = 0;
    for (int i = 0; i < numberCount; i++)
    {
        scanf("%d", &numbers[i]);
        sums[i + 1] = sums[i] + numbers[i];
    }

    dp = vector<vector<int>>(numberCount, vector<int>(divideCount, MIN));

    printf("%d", getDP(numberCount - 1, divideCount - 1));

    // printf("\n");
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[i].size(); j++)
    //     {
    //         printf("%08d          ", getDP(i, j));
    //     }
    //     printf("\n");
    // }

    return 0;
}
