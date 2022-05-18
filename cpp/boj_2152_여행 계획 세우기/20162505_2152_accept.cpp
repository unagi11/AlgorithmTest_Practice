#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int vtxCnt; // vertex count
int edgCnt; // edge count
int strVtx; // start vertex
int endVtx; // end vertex

vector<vector<bool>> edge_matrix; // edge adjacency metrix
vector<pair<int, int>> edge_list; // edge adjacency list

vector<char> color; // 방문 기록용 색깔
int time;           // 시간 기록용 timer

vector<int> stack;              // scc 계산용 위상정렬 stack
vector<int> scc;                // Strongly Connected Components
vector<int> sscc;               // Size of SCC
vector<set<int>> scc_edge_list; // SCC edge list
vector<int> dp;                 // 시작지점에서 n번째 scc까지의 최대도시개수

void DFS_visit(int u)
{
    color[u] = 'G'; // Gray
    for (int v = 1; v <= vtxCnt; v++)
        if (edge_matrix[u][v] == true && color[v] == 'W')
            DFS_visit(v);

    color[u] = 'B'; // Black
    stack.push_back(u);
}

void DFS_invert_visit(int u)
{
    color[u] = 'G'; // Gray
    scc[u] = time;
    sscc[time]++;

    for (int v = 1; v <= vtxCnt; v++)
        if (edge_matrix[v][u] == true && color[v] == 'W')
            DFS_invert_visit(v);

    color[u] = 'B'; // Black
}

void calculateDP(int u)
{
    color[u] = 'B';
    for (int v : scc_edge_list[u])
    {
        if (v == u)
            continue;
        else
        {
            int temp = dp[u] + sscc[v];
            if (temp > dp[v])
            {
                dp[v] = temp;
                calculateDP(v);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
#pragma region 입력부
    scanf("%d %d %d %d\n", &vtxCnt, &edgCnt, &strVtx, &endVtx);
    edge_matrix = vector<vector<bool>>(vtxCnt + 1, vector<bool>(vtxCnt + 1, false));

    for (int i = 0; i < edgCnt; i++)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        edge_matrix[a][b] = true;
        edge_list.push_back({a, b});
    }
#pragma endregion

#pragma region 깊이우선탐색으로 순방향 DFS 스텍 계산
    time = 0;
    color = vector<char>(vtxCnt + 1, 'W'); // White

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

#pragma region 반전트리를 이용하여 SCC 계산후 그룹화 'Kosaraju Algorithm'..
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

    scc_edge_list = vector<set<int>>(sscc.size(), set<int>());
    for (pair<int, int> p : edge_list)
        scc_edge_list[scc[p.first]].insert(scc[p.second]);
#pragma endregion

#pragma region 'DP'를 이용하여 최대 도시개수 산출
    color = vector<char>(sscc.size(), 'W'); // White
    dp = vector<int>(sscc.size(), 0);
    dp[scc[strVtx]] = sscc[scc[strVtx]];
    calculateDP(scc[strVtx]);
    printf("%d", dp[scc[endVtx]]);
#pragma endregion

    return 0;
}
