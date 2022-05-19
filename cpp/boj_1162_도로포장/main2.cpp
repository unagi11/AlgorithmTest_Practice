// Priority Queue 이용한 Dijkstra + DP 연습

// #include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

// #define FAST()                         \
//     ios_base ::sync_with_stdio(false); \
//     cin.tie(NULL);                     \
//     cout.tie(NULL)

#define MAX_CITYS 10'001
#define MAX_PATHS 50'001
#define MAX_PAVED 21
#define MAX_COST 1'000'001

using namespace std;

int N; // count of citys (1 <= N <= 10,000)
int M; // count of paths (1 <= M <= 50,000)
int K; // count of paved (1 <= K <= 20)

vector<pair<int, int>> edgelist[MAX_CITYS]; // edgelist[i] > vi 와 연결되 있는 edge와 비용
long long dp_length[MAX_CITYS][MAX_PAVED];  // dp[i][j] : j번의 포장을 했을때 v1에서 vi에 도달하는데 필요한 최소비용

// cost, nearest y position, paved number
priority_queue<pair<long long, pair<int, int>>> nearest_pq;

long long dijkstra()
{
    // fill_n(&dp_length[0][0], MAX_CITYS * MAX_PAVED, MAX_COST);

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp_length[i][j] = MAX_COST;

    dp_length[1][0] = 0;
    nearest_pq.push({-0, {1, 0}});

    while (!nearest_pq.empty())
    {
        long long cur_cost = -nearest_pq.top().first;
        int cur_pos = nearest_pq.top().second.first;
        int cur_pav = nearest_pq.top().second.second;
        nearest_pq.pop();
        // printf("hel %lld %d %d\n", cur_cost, cur_pos, cur_pav);

        // 현재 dp보다 더 나은 경우라면, 갱신이 필요하다.
        if (dp_length[cur_pos][cur_pav] >= cur_cost)
        {
            for (int i = 0; i < edgelist[cur_pos].size(); i++)
            {
                long long nxt_cost = cur_cost + edgelist[cur_pos][i].second;
                int nxt_pos = edgelist[cur_pos][i].first;

                // 포장할수 있고 더 나은경우
                if (cur_pav < K && dp_length[nxt_pos][cur_pav + 1] > cur_cost)
                {
                    dp_length[nxt_pos][cur_pav + 1] = cur_cost;
                    nearest_pq.push({-cur_cost, {nxt_pos, cur_pav + 1}});
                    // printf("push %d %d %d\n", cur_cost, nxt_pos, cur_pav + 1);
                }

                // 포장하지 않고 더 나은경우
                if (dp_length[nxt_pos][cur_pav] > nxt_cost)
                {
                    dp_length[nxt_pos][cur_pav] = nxt_cost;
                    nearest_pq.push({-nxt_cost, {nxt_pos, cur_pav}});
                    // printf("push %d %d %d\n", nxt_cost, nxt_pos, cur_pav);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // FAST();

    scanf("%d %d %d\n", &N, &M, &K);
    // cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int city1, city2, cost;
        scanf("%d %d %d\n", &city1, &city2, &cost);
        // cin >> city1 >> city2 >> cost;

        edgelist[city1].push_back({city2, cost}); // 순방향
        edgelist[city2].push_back({city1, cost}); // 역방향
    }

    dijkstra();

    long long answer = dp_length[N][0];
    for (int i = 1; i <= K; i++)
        answer = min(answer, dp_length[N][i]);
    // cout << answer;
    printf("%lld", answer);

    return 0;
}
