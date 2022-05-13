#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MOD 1'000'000'000 // 10^9

using namespace std;

class Edge
{
public:
    int start, end, weight;
    Edge(int s, int e, int w)
    {
        start = s;
        end = e;
        weight = w;
    };

    struct comp
    {
        bool operator()(Edge const &a, Edge const &b)
        {
            return a.weight < b.weight;
        }
    };
};

int numOfVertexes = 0;
int numOfEdges = 0;
long long weightSum = 0;

priority_queue<Edge, vector<Edge>, Edge::comp> edges;

vector<int> setParent;
vector<int> setHeight;
vector<int> setSize;

// 집합 초기화
void CreateSet()
{
    for (int i = 0; i <= numOfVertexes; i++)
    {
        setParent.push_back(i);
        setHeight.push_back(1);
        setSize.push_back(1);
    }
}

// 집합의 부모 찾기
int FindSet(int x)
{
    while (x != setParent[x])
        x = setParent[x];
    return x;
}

// 두 집합 합치기 (큰거에 작은거 합침)
void UnionSet(int x, int y)
{
    int a = FindSet(x);
    int b = FindSet(y);

    // b로 통합
    if (setHeight[a] < setHeight[b])
    {
        setParent[a] = b;
        setSize[b] += setSize[a];
    }
    // b로 통합
    else if (setHeight[a] == setHeight[b])
    {
        setHeight[b]++;
        setParent[a] = b;
        setSize[b] += setSize[a];
    }
    // a로 통합
    else
    {
        setParent[b] = a;
        setSize[a] += setSize[b];
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &numOfVertexes, &numOfEdges);

    CreateSet();

#pragma region 엣지 입력부
    for (int i = 0; i < numOfEdges; i++)
    {
        int start, end, weight;
        scanf("%d %d %d\n", &start, &end, &weight);
        edges.push(Edge(start, end, weight));
        weightSum = weightSum + weight;
    }
#pragma endregion

#pragma region 주 처리부

    long long answer = 0;

    while (!edges.empty())
    {
        Edge edge = edges.top();

        int Set1 = FindSet(edge.start);
        int Set2 = FindSet(edge.end);

        if (Set1 != Set2)
        {
            answer = (answer + (weightSum * setSize[Set1] * setSize[Set2]) % MOD) % MOD;
            UnionSet(Set1, Set2);
        }

        weightSum -= edge.weight;
        edges.pop();
    }
#pragma endregion

    printf("%lld", answer);

    return 0;
}
