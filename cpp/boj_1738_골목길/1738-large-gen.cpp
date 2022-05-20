#include <bits/stdc++.h>
using namespace std;

void Validate(int n, int m, const vector<tuple<int,int,int>> &edges){
    assert(2 <= n && n <= 100);
    assert(1 <= m && m <= 20'000);
    assert(edges.size() == m);
    for(const auto &[s,e,w] : edges){
        assert(1 <= s && s <= n);
        assert(1 <= e && e <= n);
        assert(-1000 <= w && w <= 1000);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N = 100, M = 20000;
    vector<tuple<int,int,int>> V;
    V.emplace_back(2, N, -1000);
    while(V.size() < M){
        if(V.size() & 1) V.emplace_back(1, 2, 1000);
        else V.emplace_back(2, 1, 1000);
    }
    random_shuffle(V.begin(), V.end());

    Validate(N, M, V);

    cout << N << " " << M << "\n";
    for(const auto &[s,e,w] : V) cout << s << " " << e << " " << w << "\n";
}
