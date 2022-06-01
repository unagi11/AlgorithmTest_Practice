#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int vtxCnt; // vertex count
int edgCnt; // edge count
int strVtx; // start vertex
int endVtx; // end vertex

vector<vector<bool>> edge_matrix;
vector<pair<int, int>> edge_list;

vector<char> color; // 방문 기록용 색깔
vector<int> dt;     // discovery time
vector<int> ft;     // finishing time

int time;

vector<int> stack;
vector<int> scc;                      // Strongly Connected Components
vector<int> sscc;                     // Size of SCC
vector<vector<bool>> scc_edge_matrix; // SCC edge list
vector<vector<int>> scc_group;

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

int maximum_cost = 0;

// ccs_gourp을 BFS 순회하면서 최대비용경로를 찾는다.
void BFS_visit(int u, int cost, vector<char> _color)
{
    // printf("%d %d\n", u, cost);
    cost += sscc[u];
    _color[u] = 'B'; // Black

    if (u == scc[endVtx])
        maximum_cost = max(cost, maximum_cost);
    else
        for (int i = 1; i < scc_edge_matrix[u].size(); i++)
            if (scc_edge_matrix[u][i] == true && _color[i] == 'W')
                BFS_visit(i, cost, _color);
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d\n", &vtxCnt, &edgCnt, &strVtx, &endVtx);

    edge_matrix = vector<vector<bool>>(vtxCnt + 1, vector<bool>(vtxCnt + 1, false));

    for (int i = 0; i < edgCnt; i++)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        edge_matrix[a][b] = true;
        edge_list.push_back({a, b});
    }

#pragma region 깊이우선탐색으로 '발견시간', '종료시간' 계산
    time = 0;
    color = vector<char>(vtxCnt + 1, 'W'); // White
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

    scc_group = vector<vector<int>>(sscc.size(), vector<int>());
    for (int i = 1; i < scc.size(); i++)
        scc_group[scc[i]].push_back(i);

    scc_edge_matrix = vector<vector<bool>>(sscc.size(), vector<bool>(sscc.size(), false));
    for (int i = 0; i < edge_list.size(); i++)
        scc_edge_matrix[scc[edge_list[i].first]][scc[edge_list[i].second]] = true;

#pragma endregion

    // for (int i = 1; i <= vtxCnt; i++)
    // {
    //     printf("%d %d\n", i, scc[i]);
    // }

    // for (int i = 0; i < sscc.size(); i++)
    // {
    //     printf("sscc %d %d\n", i, sscc[i]);
    // }

    // for (int i = 0; i < scc_group.size(); i++)
    // {
    //     printf("%d : ", i);
    //     for (int j = 0; j < scc_group[i].size(); j++)
    //     {
    //         printf("%d ", scc_group[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 1; i < scc_edge_matrix.size(); i++)
    // {
    //     printf("i%d : ", i);
    //     for (int j = 1; j < scc_edge_matrix[i].size(); j++)
    //     {
    //         printf("%d ", scc_edge_matrix[i][j] == true);
    //     }
    //     printf("\n");
    // }

    color = vector<char>(sscc.size(), 'W'); // White
    BFS_visit(scc[strVtx], 0, color);

    printf("%d", maximum_cost);

    return 0;
}
