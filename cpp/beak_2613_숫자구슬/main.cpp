#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int countOfNumbers;  // 숫자의 개수
int countOfSlices;   // 자르는 개수
vector<int> numbers; // 입력받은 숫자들

int main(int argc, char const *argv[])
{

#pragma region 필요한 정보 입력 받는다.

    scanf("%d %d", &countOfNumbers, &countOfSlices);

    for (int i = 0; i < countOfNumbers; i++)
    {
        int number;
        scanf("%d", &number);
        numbers.push_back(number);
    }
#pragma endregion

#pragma region 순회할 범위를 구한다.

    int maximum = 0;
    int minimum = 0;

    for (int i = 0; i < countOfNumbers; i++)
    {
        maximum += numbers[i];
        minimum = minimum < numbers[i] ? numbers[i] : minimum;
    }
#pragma endregion

#pragma region 이분탐색을 하면서, 구슬그룹들중 최대값의 최소를 찾는다.

    // 이리저리 옮겨다니기 위한 피벗
    int pivot = (int)(minimum + maximum) / 2;

    // 그룹으로 묶은 구슬들을 나타내는 자료구조
    vector<vector<int>> groups;

    while (minimum < maximum)
    {
        int groupSum = numbers[0];
        groups.clear();
        groups.push_back(vector<int>(1, numbers[0]));

        for (int i = 1; i < countOfNumbers; i++)
        {
            if (countOfSlices - groups.size() == countOfNumbers - i)
            {
                groupSum = numbers[i];
                groups.push_back(vector<int>());
                groups[groups.size() - 1].push_back(numbers[i]);
                continue;
            }

            // 현재 그룹의 합이 목표값보다 크다면 다음 그룹으로 넘어가야 한다.
            if (groupSum + numbers[i] > pivot)
            {
                groupSum = numbers[i];
                groups.push_back(vector<int>());
                groups[groups.size() - 1].push_back(numbers[i]);
            }
            // 그렇지 않다면, 현재 그룹에 추가한다.
            else
            {
                groupSum += numbers[i];
                groups[groups.size() - 1].push_back(numbers[i]);
            }
        }

        if (countOfSlices < groups.size())
            minimum = pivot + 1;
        else
            maximum = pivot;

        pivot = (int)(minimum + maximum) / 2;
    }

#pragma endregion

#pragma region 구한 pivot을 통해 해답을 구한다.

    int groupSum = numbers[0];
    groups.clear();
    groups.push_back(vector<int>(1, numbers[0]));

    for (int i = 1; i < countOfNumbers; i++)
    {
        if (countOfSlices - groups.size() == countOfNumbers - i)
        {
            groupSum = numbers[i];
            groups.push_back(vector<int>());
            groups[groups.size() - 1].push_back(numbers[i]);
            continue;
        }

        if (groupSum + numbers[i] > pivot)
        {
            groupSum = numbers[i];
            groups.push_back(vector<int>());
            groups[groups.size() - 1].push_back(numbers[i]);
        }
        else
        {
            groupSum += numbers[i];
            groups[groups.size() - 1].push_back(numbers[i]);
        }
    }

    printf("%d\n", pivot);
    for (int i = 0; i < groups.size() - 1; i++)
        printf("%d ", groups[i].size());
    printf("%d", groups[groups.size() - 1].size());

#pragma endregion

    return 0;
}
