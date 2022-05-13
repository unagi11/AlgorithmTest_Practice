#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, m, s, t, num = 1;
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<int> graph[MAX];
vector<vector<int>> scc;
stack<int> stk;
int dp[MAX] = { 0 };
bool visit[MAX] = { false };

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];

	for (int nxt : graph[node]) {
		if (id[nxt] == 0) res = min(res, dfs(nxt));
		else if (!sccIdx[nxt]) res = min(res, id[nxt]);
	}

	if (res == id[node]) {
		vector<int> temp;
		int idx = scc.size() + 1;
		while (1) {
			int top = stk.top();
			stk.pop();
			sccIdx[top] = idx;
			temp.push_back(top);
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

void createScc() {
	for (int i = 1; i <= n; i++) {
		if (id[i] == 0) dfs(i);
	}
}

void countMaxVisitCity(int node, int curSccIdx) {
	visit[node] = true;
	for (auto nxt : graph[node]) {
		int nxtSccIdx = sccIdx[nxt] - 1;
		if (curSccIdx == nxtSccIdx) {
			if (visit[nxt]) continue;
			countMaxVisitCity(nxt, curSccIdx);
		}
		else {
			int nxtSccCnt = scc[nxtSccIdx].size();
			int nxtCnt = dp[curSccIdx] + nxtSccCnt;
			if (nxtCnt > dp[nxtSccIdx]) {
				dp[nxtSccIdx] = nxtCnt;
				countMaxVisitCity(nxt, nxtSccIdx);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> s >> t;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	createScc();

	int sIdx = sccIdx[s] - 1;
	dp[sIdx] = scc[sIdx].size();
	countMaxVisitCity(s, sIdx);

	int tIdx = sccIdx[t] - 1;
	cout << dp[tIdx];
}