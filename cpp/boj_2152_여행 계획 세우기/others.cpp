#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<vector<int>> arr;
vector<vector<int>> scc_arr;
int discover[10001], scc[10001], country[10001], res[10001];
int cnt, scc_cnt = 1, start, target, n, m, s, t;
stack<int> st;
queue<int> q;

int dfs(int now)
{
    st.push(now);
    discover[now] = cnt++;
    int parent = discover[now];
    for (int i = 0; i < arr[now].size(); i++)
    {
        int next = arr[now][i];
        if (discover[next] == -1)
            parent = min(parent, dfs(next));
        else if (scc[next] == -1)
            parent = min(parent, discover[next]);
    }
    if (parent == discover[now])
    {
        while (true)
        {
            int here = st.top();
            st.pop();
            if (s == here)
                start = scc_cnt;
            if (t == here)
                target = scc_cnt;
            scc[here] = scc_cnt;
            country[scc_cnt] += 1;
            if (here == now)
                break;
        }
        scc_cnt++;
    }
    return parent;
}

void bfs()
{
    q.push(start);
    res[start] = country[start];
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < scc_arr[now].size(); i++)
        {
            int next = scc_arr[now][i];
            if (res[next] < res[now] + country[next])
            {
                res[next] = res[now] + country[next];
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s >> t;
    arr.resize(n + 1);
    scc_arr.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    fill(discover, discover + 10001, -1);
    fill(scc, scc + 10001, -1);
    for (int i = 1; i <= n; i++)
    {
        if (discover[i] == -1)
            dfs(i);
    }
    for (int now = 1; now <= n; now++)
    {
        for (int i = 0; i < arr[now].size(); i++)
        {
            int next = scc[arr[now][i]];
            if (scc[now] != next)
                scc_arr[scc[now]].push_back(next);
        }
    }
    if (start == target)
    {
        cout << country[start];
        return 0;
    }
    bfs();
    cout << res[target];
    return 0;
}