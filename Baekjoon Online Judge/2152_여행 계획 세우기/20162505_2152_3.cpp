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

vector<vector<bool>> edge_matrix;
vector<vector<int>> edge_adj_list;
vector<vector<int>> edge_adj_list_INVERT;

vector<char> color; // 방문 기록용 색깔
vector<int> pred;   // 이전 노드
vector<int> dt;     // discovery time
vector<int> ft;     // finishing time

int time;

vector<int> stack;
vector<int> scc;  // Strongly Connected Components
vector<int> sscc; // Size of SCC

vector<int> dp;
vector<bool> visited;

void DFS_visit(int u)
{
    color[u] = 'G'; // Gray
    dt[u] = ++time;

    for (int v = 1; v <= vtxCnt; v++)
        if (edge_matrix[u][v] == true && color[v] == 'W')
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

    for (int v = 1; v <= vtxCnt; v++)
        if (edge_matrix[v][u] == true && color[v] == 'W')
            DFS_invert_visit(v);

    color[u] = 'B'; // Black
}

void calDP(int cur)
{
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

    edge_adj_list = vector<vector<int>>(vtxCnt + 1, vector<int>());
    edge_adj_list_INVERT = vector<vector<int>>(vtxCnt + 1, vector<int>());
    edge_matrix = vector<vector<bool>>(vtxCnt + 1, vector<bool>(vtxCnt + 1, false));

    for (int i = 0; i < edgCnt; i++)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        edge_adj_list[a].push_back(b);
        edge_adj_list_INVERT[b].push_back(a);
        edge_matrix[a][b] = true;
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


#pragma endregion

    dp = vector<int>(sscc.size(), 0);
    visited = vector<bool>(sscc.size(), false);
    dp[scc[strVtx]] = sscc[scc[strVtx]];
    calDP(strVtx);

    printf("%d", dp[scc[endVtx]]);

    return 0;
}
