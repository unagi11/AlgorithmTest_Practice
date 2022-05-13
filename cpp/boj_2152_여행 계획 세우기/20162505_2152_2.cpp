#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int vtxCnt; // vertex count
int edgCnt; // edge count
int strVtx; // start vertex
int endVtx; // end vertex

vector<set<int>> edge_adj_list;
vector<set<int>> edge_adj_list_INVERT;
// vector<pair<int, int>> edge_pair_list;

vector<char> color; // 방문 기록용 색깔
vector<int> pred;   // 이전 노드
vector<int> dt;     // discovery time
vector<int> ft;     // finishing time

int time;
int maximum_cost = 0;

vector<int> stack;
vector<int> scc;  // Strongly Connected Components
vector<int> sscc; // Size of SCC
// vector<set<int>> scc_adj_list;

vector<int> dp;
vector<bool> visited;

void DFS_visit(int u)
{
    color[u] = 'G'; // Gray
    dt[u] = ++time;

    for (int v : edge_adj_list[u])
        if (color[v] == 'W')
            DFS_visit(v);

    color[u] = 'B'; // Black
    ft[u] = ++time;
    stack.push_back(u);
}

void DFS_invert_visit(int u)
{
    color[u] = 'G'; // Gray
    scc[u] = time;
    sscc[time]++;

    for (int v : edge_adj_list_INVERT[u])
        if (color[v] == 'W')
            DFS_invert_visit(v);

    color[u] = 'B'; // Black
}

// void DFS_scc_visit(int u, int cost, vector<char> _color)
// {
//     cost += sscc[u];
//     _color[u] = 'B'; // Black

//     if (u == scc[endVtx])
//         maximum_cost = max(cost, maximum_cost);
//     else
//         for (int v : scc_adj_list[u])
//             if (_color[v] == 'W')
//                 DFS_scc_visit(v, cost, _color);
// }

// int GetDP(int a, int b)
// {
//     // printf("%d %d\n", a, b);
//     if (dp[a][b] == 0)
//     {
//         int temp = -1;
//         for (int v : scc_adj_list[a])
//         {
//             if (v != b)
//                 temp = max(temp, GetDP(a, v) + GetDP(v, b));
//         }
//         dp[a][b] = max(dp[a][b], temp);
//     }
//     if (scc_adj_list[a].find(b) != scc_adj_list[a].end())
//     {
//         dp[a][b] = max(dp[a][b], sscc[a]);
//     }
//     return dp[a][b];
// }

void calDP(int cur)
{
    // printf("%d\n", cur);

    visited[cur] = true;
    // 인접한 점들을 순회.
    for (int nxt : edge_adj_list[cur])
    {
        // 연결된 곳이 같은 scc라면
        if (scc[cur] == scc[nxt])
        {
            // 방문한곳은 세지 않는다.
            if (visited[nxt])
                continue;
            // 방문하지 않은곳은 체크한다.
            else
                calDP(nxt);
        }
        // 연결된 곳이 다른 scc라면 이전에 계산한 dp보다 큰값이라면 갱신해준다.
        else
        {
            int temp = dp[scc[cur]] + sscc[scc[nxt]];
            if (temp > dp[scc[nxt]])
            {
                // printf("%d %d", scc[nxt], temp);
                dp[scc[nxt]] = temp;
                calDP(nxt);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d\n", &vtxCnt, &edgCnt, &strVtx, &endVtx);

    edge_adj_list = vector<set<int>>(vtxCnt + 1, set<int>());
    edge_adj_list_INVERT = vector<set<int>>(vtxCnt + 1, set<int>());

    for (int i = 0; i < edgCnt; i++)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        edge_adj_list[a].insert(b);
        edge_adj_list_INVERT[b].insert(a);
        // edge_pair_list.push_back({a, b});
    }

#pragma region 깊이우선탐색으로 '발견시간', '종료시간' 계산
    time = 0;
    color = vector<char>(vtxCnt + 1, 'W'); // White
    pred = vector<int>(vtxCnt + 1, -1);
    dt = vector<int>(vtxCnt + 1, -1);
    ft = vector<int>(vtxCnt + 1, -1);

    // 목적지에 도달 가능여부 검사
    DFS_visit(strVtx);
    if (color[endVtx] == 'W')
    {
        printf("0");
        return 0;
    }
    // 나머지 위치 DFS 검사
    for (int u = 1; u <= vtxCnt; u++)
        if (color[u] == 'W')
            DFS_visit(u);
#pragma endregion

#pragma region 반전트리를 이용하여 SCC 계산후 그룹화
    time = 0;
    color = vector<char>(vtxCnt + 1, 'W'); // White
    scc = vector<int>(vtxCnt + 1, -1);
    sscc.push_back(0);
    while (!stack.empty())
    {
        int u = stack.back();
        if (color[u] == 'W')
        {
            time++;
            sscc.push_back(0);
            DFS_invert_visit(u);
        }
        stack.erase(stack.end() - 1);
    }

    // scc_adj_list = vector<set<int>>(sscc.size(), set<int>());

    // for (pair<int, int> p : edge_pair_list)
    //     if (scc[p.first] != scc[p.second])
    //         scc_adj_list[scc[p.first]].insert(scc[p.second]);

#pragma endregion

    // color = vector<char>(sscc.size(), 'W'); // White
    // dp = vector<vector<int>>(sscc.size(), vector<int>(sscc.size(), 0));
    // DFS_scc_visit(scc[strVtx], 0, color);

    dp = vector<int>(sscc.size(), 0);
    visited = vector<bool>(sscc.size(), false);
    // for (int i = 0; i < sscc.size(); i++)
    // {
    //     printf("dp%d\n", dp[i]);
    // }

    dp[scc[strVtx]] = sscc[scc[strVtx]];
    calDP(strVtx);

    // for (int i = 0; i < sscc.size(); i++)
    // {
    //     printf("dp%d\n", dp[i]);
    // }

    printf("%d", dp[scc[endVtx]]);

    return 0;
}
