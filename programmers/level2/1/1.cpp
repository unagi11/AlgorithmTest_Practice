#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer = vector<int>(prices.size(), -1);

    vector<int> stack = {0};

    for (int i = 1; i < prices.size(); i++)
    {
        vector<int> stack2;
        stack.push_back(i);
        // 가격이 꺾이는 시점.
        if (prices[i] < prices[i - 1])
        {
            for (int k = 0; k < stack.size(); k++)
            {
                int j = stack[k];
                // j이전값보다 i현재값이 최초로 더 떨어진경우
                if (prices[i] < prices[j])
                    answer[j] = i - j;
                else
                    stack2.push_back(j);
            }
            stack = stack2;
        }
    }

    for (int i = 0; i < prices.size(); i++)
    {
        if (answer[i] == -1)
        {
            answer[i] = prices.size() - i - 1;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    auto list = solution({1, 2, 3, 2, 3});

    for (int i = 0; i < list.size(); i++)
    {
        printf("%d ", list[i]);
    }

    return 0;
}
