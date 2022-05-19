#include <bits/stdc++.h>
using namespace std;

void Validate(int n, int m, int k, const vector<tuple<int, int, int>> &edges)
{
    assert(1 <= n && n <= 10'000);
    assert(1 <= m && m <= 50'000);
    assert(1 <= k && k <= 20);
    assert(edges.size() == m);
    for (const auto &[u, v, w] : edges)
    {
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(1 <= w && w <= 1'000'000);
    }

    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int v)
    {
        return v == par[v] ? v : par[v] = find(par[v]);
    };
    auto merge = [&](int u, int v)
    {
        if (find(u) != find(v))
            par[find(u)] = find(v);
    };
    for (const auto &[u, v, w] : edges)
        merge(u, v);
    assert(find(1) == find(n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = 10000, M = N - 1, K = 1;
    vector<tuple<int, int, int>> V;
    for (int i = 1; i < N; i++)
        V.emplace_back(i, i + 1, 1'000'000);
    random_shuffle(V.begin(), V.end());

    Validate(N, M, K, V);

    cout << N << " " << M << " " << K << "\n";
    for (const auto &[u, v, w] : V)
        cout << u << " " << v << " " << w << "\n";
}

// 9998000000