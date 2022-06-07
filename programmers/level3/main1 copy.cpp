#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < works.size(); i++)
        pq.push(works[i]);

    for (int i = 0; i < n; i++)
    {
        int temp = pq.top();
        pq.pop();
        pq.push(temp - 1);
    }

    while (!pq.empty())
    {
        long long temp = pq.top();
        pq.pop();
        // printf("%d", temp);
        if (temp > 0)
            answer = answer + temp * temp;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    printf("%lld", solution(4, {4, 3, 3}));

    return 0;
}