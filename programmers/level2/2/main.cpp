#include <string>
#include <vector>

using namespace std;

int people_weight[241] = {
    0,
};

int solution(vector<int> people, int limit)
{
    for (int i = 0; i < people.size(); i++)
        people_weight[people[i]]++;

    int answer = 0;

    // 맞는것이 있을경우.
    for (int i = 40; i <= limit; i++)
    {
        while (people_weight[i] > 0)
        {
            people_weight[i]--;
            answer++;
            for (int k = limit - i; k >= 0; k--)
            {
                if (people_weight[k] > 0)
                {
                    people_weight[k]--;
                    break;
                }
            }
        }
    }

    for (int i = limit / 2 + 1; i <= limit; i++)
        answer += people_weight[i];

    return answer;
}

int main(int argc, char const *argv[])
{
    printf("%d", solution({50, 50, 50, 80}, 150));

    return 0;
}
