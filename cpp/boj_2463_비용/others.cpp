#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1000000000;
const int MAX = 100000 + 1;
int N, M;
int parent[MAX];

vector<pair<pair<int, int>, int>> edge; // num1, num2, cost
long long setSize[MAX], total;

//집합의 루트를 찾는다
int find(int num)
{
    if (num == parent[num])
        return num;
    return parent[num] = find(parent[num]);
}

// num1의 집합에 num2 집합을 합친다
void merge(int num1, int num2)
{
    parent[num2] = num1;
    setSize[num1] += setSize[num2];
    setSize[num2] = 1;
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.second > b.second)
        return true;
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;  // 자기 자신으로 부모 설정
        setSize[i] = 1; // 사이즈 1로
    }

    for (int i = 0; i < M; i++)
    {
        int num1, num2, cost;
        cin >> num1 >> num2 >> cost;
        edge.push_back({{num1, num2}, cost});
        total += cost;
    }

    sort(edge.begin(), edge.end(), cmp); //가중치 내림차순 정렬

    long long result = 0;

    for (int i = 0; i < edge.size(); i++)
    {
        int parentNum1 = find(edge[i].first.first);
        int parentNum2 = find(edge[i].first.second);
        int cost = edge[i].second;

        printf("%d %d %d\n", edge[i].first.first, edge[i].first.second, cost);

        //둘이 같은 집합이 아닌 경우
        if (parentNum1 != parentNum2)
        {
            result += (((setSize[parentNum1] * setSize[parentNum2]) % MOD) * total) % MOD;
            result %= MOD;
            printf("a : %lld, %d\n", result, total);

            //같은 집합으로 합친다
            merge(parentNum1, parentNum2);
        }

        total -= cost;
    }

    cout << result << "\n";
    return 0;
}

// 출처 : https: // jaimemin.tistory.com/943 [꾸준함]