#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    sort(works.begin(), works.end(), greater<int>());

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (index == works.size() - 1)
        {
            if (works[index] == works[index - 1])
            {
                works[index]--;
                index = 0;
            }
            else
            {
                index = 0;
                i--;
            }
        }
        else if (works[index] == works[index + 1])
        {
            works[index]--;
            index++;
        }
        else if (works[index] > works[index + 1])
        {
            works[index]--;
        }
    }

    for (long long i : works)
        if (i > 0)
            answer = answer + i * i;

    return answer;
}

int main(int argc, char const *argv[])
{
    printf("%lld", solution(4, {4, 3, 3}));

    return 0;
}