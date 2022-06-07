#include <vector>

using namespace std;

typedef vector<vector<int>> adjList;

#define N 10 // N = |A| : A 그룹의 크기
#define M 10 // M = |B| : B 그룹의 크기

adjList vt;      // vt[a] : a와 연결된 b들 인접리스트
bool visited[N]; // for all a in A. a를 방문했는가.
int Match[M];    // for all b in B. b와 매칭되는 a의 index.

bool DFS(int a)
{
    if (visited[a])    // 방문한적 있다면 반복하지 않는다.
        return false;  // a는 짝을 못찾았다.
    visited[a] = true; // 방문 체크한다.

    for (int b : vt[a]) // a와 연결된 모든 b에 대해서
    {
        // 만약 짝이 없거나, b의 짝a가 다른 b를 찾을수 있다면
        if (Match[b] == -1 || DFS(Match[b]))
        {
            Match[b] = a; // b의 짝을 현재 a로 바꿔준다.
            return true;  // a는 짝을 찾았다.
        }
    }

    return false; // a는 짝을 못찾았다.
}

int MaxMatching()
{
    int ans = 0; // a와 b의 최대 매칭 개수

    fill(Match, Match + M, -1); // 매칭되지 않은 리스트를 -1로 초기화한다.
    for (int i = 0; i < N; i++) // N을 순회하면서 짝을 찾는다.
    {
        fill(visited, visited + N, false);
        if (DFS(i)) // i번째 a는 짝을 찾았다.
            ++ans;
    }

    return ans;
}