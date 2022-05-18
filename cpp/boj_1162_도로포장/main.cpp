// Priority Queue 이용한 Dijkstra + DP 연습

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define FAST()                         \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL)

#define MAX_CITYS 10'001
#define MAX_PATHS 50'001
#define MAX_PAVED 21

using namespace std;

int N; // count of citys (1 <= N <= 10,000)
int M; // count of paths (1 <= M <= 50,000)
int K; // count of paved (1 <= K <= 20)

vector<pair<int, int>> edgelist[MAX_CITYS]; // edgelist[i] > vi 와 연결되 있는 edge와 비용

// dp[i][j] : j번의 포장을 했을때 v1에서 vi에 도달하는데 필요한 최소비용
long long length[MAX_CITYS][MAX_PAVED];

struct compare
{
    bool operator()(pair<pair<int, int>, long long> a, pair<pair<int, int>, long long> b)
    {
        return a.second > b.second;
    }
};

// nearest edge, cost
priority_queue<pair<pair<int, int>, long long>, compare()> nearest_pq;

long long dijkstraFunc()
{
    fill_n(*length, sizeof(long long) * MAX_CITYS * MAX_PAVED, -1);
    length[1][0] = 0;
}

int main(int argc, char const *argv[])
{
    FAST();

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;

        if (city1 > city2)
            swap(city1, city2);

        edgelist[city1].push_back({city2, cost}); // 순방향
    }

    return 0;
}
