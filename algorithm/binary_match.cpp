// link1 : https://doorisopen.github.io/developers-library/Algorithm/2019-08-01-algorithm-bipartitematching
// link2 : https://blog.naver.com/ndb796/221240613074

#include <iostream>
#include <vector>
using namespace std;

#define MAX 101         // 정점의 개수
vector<int> edge[MAX];  // 좌정점과 연결되어있는 우정점 번호가 기록되어있다.
int matchedNumber[MAX]; // 우정점이 몇번째 좌정점과 매칭되었는지 기록하는 정보
bool isMatched[MAX];    // 우정점이 현재 매칭되어 있는가를 기록

int countOfLeftVertex = 3;
int countOfEdge;

// 본 좌정점이 매칭에 성공할 경우 True, 실패할경우 Fasle를 반환
bool dfs(int leftVertexNumber)
{
    for (int i = 0; i < edge[leftVertexNumber].size(); i++) // 연결되어있는 우정점을 순회
    {
        int rightVertexNumber = edge[leftVertexNumber][i];

        if (isMatched[rightVertexNumber] == true) // 이미 처리한 노드는 더 볼 필요가 없음.
            continue;
        isMatched[rightVertexNumber] = true;

        // 우정점이 아직 매칭되지 않았거나 우정점이 매칭했던 좌정점이 다른 매칭을 찾을수 있다면
        if (matchedNumber[rightVertexNumber] == 0 || dfs(matchedNumber[rightVertexNumber]))
        {
            // 좌정점과 우정점을 매칭을 한다.
            matchedNumber[rightVertexNumber] = leftVertexNumber;
            return true;
        }
    }
    // 본 leftVertex에는 더이상 매칭할 정점이 존재하지 않는다.
    return false;
}

int main(int argc, char const *argv[])
{
    edge[1].push_back(1);
    edge[1].push_back(2);
    edge[1].push_back(3);
    edge[2].push_back(1);
    edge[3].push_back(2);

    int count = 0;
    for (int i = 1; i <= countOfLeftVertex; i++)
    {
        // 매 왼 vertex 순회마다 isMatched 배열 false 초기화
        fill(isMatched, isMatched + MAX, false);
        if (dfs(i))
            count++;
    }

    printf("%d 개의 매칭이 이루어졌습니다. \n", count);
    for (int i = 1; i < MAX; i++)
    {
        if (matchedNumber[i] != 0)
        {
            printf("%d -> %d \n", matchedNumber[i], i);
        }
    }

    return 0;
}
