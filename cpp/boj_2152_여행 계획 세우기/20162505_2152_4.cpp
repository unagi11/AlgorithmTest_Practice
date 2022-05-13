#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <memory.h>

#define MAX_CITY 10'000
#define MAX_EDGE 100'000

using namespace std;

int count_city; // 10,000
int count_edge; // 100,0000
int start_city;
int end_city;

vector<int> edges[MAX_CITY];        // edge[from_city] = {to_citys}
vector<int> edges_invert[MAX_CITY]; // 100,000 * 4bytes > 400KB

bool isVisited[MAX_CITY] = {false}; // 10KB
int timer = 0;
stack<int> topology_stack;

int scc[MAX_CITY] = {0};
int sscc[MAX_CITY] = {0};
int dp[MAX_CITY] = {0};

void DFS_visit(int u)
{
    isVisited[u] = true;

    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        if (isVisited[v] == false)
            DFS_visit(v);
    }

    topology_stack.push(u);
}

void DFS_visit_invert(int u)
{
    isVisited[u] = true;
    scc[u] = timer;
    sscc[timer]++;

    for (int i = 0; i < edges_invert[u].size(); i++)
    {
        int v = edges_invert[u][i];
        if (isVisited[v] == false)
            DFS_visit_invert(v);
    }
}

void calculateDP(int u)
{
    isVisited[u] = true;

    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        if (scc[u] == scc[v])
        {
            if (isVisited[v])
                continue;
            else
                calculateDP(v);
        }
        else
        {
            int temp = dp[scc[u]] + sscc[scc[v]];
            if (temp > dp[scc[v]])
            {
                dp[scc[v]] = temp;
                calculateDP(v);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d\n", &count_city, &count_edge, &start_city, &end_city);

    for (int i = 0; i < count_edge; i++)
    {
        int from, to;
        scanf("%d %d\n", &from, &to);
        edges[from].push_back(to);
        edges_invert[to].push_back(from);
    }

    timer = 0;
    fill(isVisited, isVisited + MAX_CITY, false);
    DFS_visit(start_city);
    if (isVisited[end_city] == false)
    {
        printf("0");
        return 0;
    }
    for (int u = 1; u <= count_city; u++)
        if (isVisited[u] == false)
            DFS_visit(u);

    timer = 0;
    fill(isVisited, isVisited + MAX_CITY, false);
    while (!topology_stack.empty())
    {
        int u = topology_stack.top();
        // printf("%d\n", u);
        if (isVisited[u] == false)
        {
            timer++;
            DFS_visit_invert(u);
        }
        topology_stack.pop();
    }

    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%d %d\n", scc[i], sscc[i]);
    // }

    fill(isVisited, isVisited + MAX_CITY, false);
    dp[scc[start_city]] = sscc[scc[start_city]];

    calculateDP(start_city);

    printf("%d", dp[scc[end_city]]);

    return 0;
}
