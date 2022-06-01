// chained matrix
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> numbers;
vector<int> sums;

int numberCount, divideCount;

const int MIN = -99999;

int max(int a, int b) { return a < b ? b : a; }

// dp[numCnt][dvdCnt] - (numCnt+1)개(0 ~ numCnt)의 원소를 (dvdCnt+1)개 덩어리로 분할했을때 최대값.
// ex.) dp[0][0] - 1개 원소를 1개 덩어리로 분할
// ex.) dp[2][1] - 3개 원소를 2개 덩어리로 분할
int getDP(int numCnt, int dvdCnt)
{
    int dpn = MIN;
    // 범위 넘어가면 존재하지 않음.
    if (numCnt < 0 || numCnt >= numberCount || dvdCnt < 0 || dvdCnt >= divideCount || numCnt + 1 < dvdCnt * 2 + 1)
    {
        return dpn;
        // printf("rangeOut (%d, %d : %d)\n", numCnt, dvdCnt, dpn);
    }
    // 이미 한번 계산한적 있다면, 그대로 값을 리턴.
    else if (dp[numCnt][dvdCnt] != MIN)
    {
        dpn = dp[numCnt][dvdCnt];
        // printf("calculated (%d, %d : %d)\n", numCnt, dvdCnt, dpn);
    }
    else if (dvdCnt == 0)
    {
        for (int k = max(0, 2 * dvdCnt - 3); k <= numCnt; k++)
        {
            // printf("%d ?\n", dpn);
            dpn = max(dpn, sums[numCnt + 1] - sums[k]);
        }
        dp[numCnt][dvdCnt] = max(dp[numCnt][dvdCnt], dpn);
        // printf("dvdCnt == 0(%d, %d : %d)\n", numCnt, dvdCnt, dpn);
    }
    else
    {
        dpn = getDP(numCnt - 1, dvdCnt);
        for (int k = max(2, 2 * dvdCnt - 3); k <= numCnt; k++)
        {
            int temp = getDP(k - 2, dvdCnt - 1);
            temp = temp == MIN ? 0 : temp;

            // printf("(%d %d) %d + %d - %d\n", numCnt, dvdCnt, temp, sums[numCnt + 1], sums[k]);

            dpn = max(dpn, temp + sums[numCnt + 1] - sums[k]);
        }
        dp[numCnt][dvdCnt] = max(dp[numCnt][dvdCnt], dpn);
        // printf("calculate (%d, %d : %d)\n", numCnt, dvdCnt, dpn);
    }

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

    printf("\n");
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            printf("%06d          ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
