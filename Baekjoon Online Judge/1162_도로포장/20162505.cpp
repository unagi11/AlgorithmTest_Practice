#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define FAST
#define MAX_CITYS 10'001
#define MAX_PATHS 50'001
#define MAX_PAVED 21
#define MAX_COST 1'000'001

typedef pair<long long, pair<long long, long long>> pp;

struct comparator
{
    bool operator()(const pp &l, const pp &r) const
    {
        return l.first > r.first;
    }
};

long long N_citys, M_edges, K_paves;                 // 도시개수, 도로개수, 포장가능개수
vector<pair<long long, long long>> edges[MAX_CITYS]; // edges[i] : 도시i의 {도로, 비용} 리스트
long long dp[MAX_CITYS][MAX_PAVED];                  // dp[i][j] : j번 포장하여 도시i에 도달하는 최소비용
priority_queue<pp, vector<pp>, comparator> pq;       // 다익스트라용 우선순위큐. 계산할 가까운 도시를 찾는다.

int main(int argc, char const *argv[])
{

#pragma region 입력부

    scanf("%d %d %d\n", &N_citys, &M_edges, &K_paves);

    for (long long i = 0; i < M_edges; i++)
    {
        long long city1, city2;
        long long cost;
        scanf("%d %d %lld\n", &city1, &city2, &cost);
        edges[city1].push_back({city2, cost});
        edges[city2].push_back({city1, cost});
    }

#pragma endregion

#pragma region 다익스트라

    for (long long i = 0; i < MAX_CITYS; i++)
        for (long long j = 0; j < MAX_PAVED; j++)
            dp[i][j] = __INT64_MAX__;

    pq.push({0, {1, 0}});
    dp[1][0] = 0;

    while (!pq.empty())
    {
        long long cur_cos = pq.top().first;
        long long cur_pos = pq.top().second.first;
        long long cur_pav = pq.top().second.second;
        pq.pop();

        // 현재 기록보다 더 안좋은 경우라면 무시한다.
        if (dp[cur_pos][cur_pav] < cur_cos)
            continue;

        for (long long i = 0; i < edges[cur_pos].size(); i++)
        {
            long long nxt_cos = cur_cos + edges[cur_pos][i].second;
            long long nxt_pos = edges[cur_pos][i].first;

            // 포장하지 않고 나아지는 경우
            if (nxt_cos < dp[nxt_pos][cur_pav])
            {
                dp[nxt_pos][cur_pav] = nxt_cos;
                pq.push({nxt_cos, {nxt_pos, cur_pav}});
            }

            // 포장횟수가 남아있고, 포장하고 나아지는 경우
            if (cur_pav < K_paves && cur_cos < dp[nxt_pos][cur_pav + 1])
            {
                dp[nxt_pos][cur_pav + 1] = cur_cos;
                pq.push({cur_cos, {nxt_pos, cur_pav + 1}});
            }
        }
    }

#pragma endregion

#pragma region 최소값 출력부

    long long answer = dp[N_citys][0];
    for (long long i = 1; i <= K_paves; i++)
        answer = min(answer, dp[N_citys][i]);
    printf("%lld", answer);

#pragma endregion

    return 0;
}
