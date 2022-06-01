#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_COST 9'999'999

int n_citys;
vector<vector<int>> cost;

// DP[i][j] : i를 방문하고 현재 j 도시에 있을때 남은 순회비용
// i : 방문했던 도시들 [(0) ~ (2^16-1)]
// j : 현재 있는 도시  [0 ~ 15]
vector<vector<int>> DP;

int getDP(unsigned int visited, int cur_city)
{
    visited |= (1 << cur_city);

    // 모든 도시를 지남.
    if (visited == (1 << n_citys) - 1)
        // 출발도시로 돌아가는 길 존재시
        if (cost[cur_city][0] > 0)
            return cost[cur_city][0]; // 마지막 순회 비용 반환
        // 길이 없는 경로는 최고비용
        else
            return MAX_COST;

    int &dp = DP[visited][cur_city];

    if (dp > 0) // memoization. 했던 연산은 또하지 않는다.
        return dp;
    else
        dp = MAX_COST;

    for (int i = 0; i < n_citys; i++)
        // cur_city -> i 로 가는 길이 있고
        // 이전에 방문하지 않았던 도시 i라면,
        if (cost[cur_city][i] > 0 && (visited >> i & 1) == 0)
        {
            // i로 가는 비용을 갱신한다.
            int temp = getDP(visited, i) + cost[cur_city][i];
            dp = min(temp, dp);
        }

    return dp;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n_citys);

    cost = vector<vector<int>>(n_citys, vector<int>(n_citys));

    for (int i = 0; i < n_citys; i++)
        for (int j = 0; j < n_citys; j++)
            scanf("%d", &cost[i][j]);

    DP = vector<vector<int>>(1 << n_citys, vector<int>(n_citys, 0));

    // 도시 0에서 시작하여 순회하는데 필요한 총 비용
    int temp = getDP(0, 0);
    printf("%d", temp);

    return 0;
}
