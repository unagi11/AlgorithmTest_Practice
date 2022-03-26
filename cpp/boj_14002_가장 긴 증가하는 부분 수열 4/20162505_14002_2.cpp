#include <cstdio>
#include <vector>
#include <algorithm> // max_element

using namespace std;

int main(int argc, char const *argv[])
{

#pragma region 입력부
    int count;
    scanf("%d", &count);

    vector<int> numbers(count + 1, 0);
    for (int i = 1; i <= count; i++)
        scanf("%d", &numbers[i]);

        // for (int i = 1; i <= count; i++)
        //     printf("%d ", numbers[i]);
        // printf("\n");

#pragma endregion

#pragma region LIS DP O(n ^ 2)

    vector<int> LIS(count + 1, 1);  // xi로 끝나는 LIS의 길이
    vector<int> PAST(count + 1, 0); // xi로 끝나는 LIS에서 xi-1 인덱스 (경로 추적용)

    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (numbers[j] < numbers[i] && LIS[i] < LIS[j] + 1)
            {
                LIS[i] = LIS[j] + 1;
                PAST[i] = j;
            }
        }
    }

    // printf("\n");
    // for (int i = 0; i <= count; i++)
    // {
    //     printf("%d ", LIS[i]);
    // }
    // printf("\n");

    // for (int i = 0; i <= count; i++)
    // {
    //     printf("%d ", PAST[i]);
    // }
    // printf("\n");
    // printf("\n");

#pragma endregion

#pragma region path 역계산 및 출력

    auto max_iter = max_element(LIS.begin() + 1, LIS.end()); // 최대값을 찾는다.
    int max_index = max_iter - LIS.begin();
    vector<int> path_stack;

    while (max_index) // max_index 가 0 이 될때까지 순회
    {
        path_stack.push_back(numbers[max_index]);
        max_index = PAST[max_index];
    }

    // printf("%d", path_stack.size());

    printf("%d\n", *max_iter);
    for (int i = path_stack.size() - 1; i >= 0; i--)
        printf("%d ", path_stack[i]);

#pragma endregion

    return 0;
}