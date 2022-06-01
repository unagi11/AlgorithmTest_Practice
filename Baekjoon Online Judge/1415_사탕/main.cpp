#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> eratosthenes_prime(int max)
{
    max++;
    // 소수를 판별하기 위한 배열
    // 배열 index와 안의 수를 똑같이 맞추기위해 1000001개로 설정했음.
    vector<bool> isPrimeNumbers(max, true);

    // 에라토스테네스의 채
    // 소수가 아닌 수를 isPrimeNumbers에서 false로 바꿔준다.
    for (int i = 2; i * i < max; i++)            // i => 2부터 MAXIMUM의 제곱근까지
        if (isPrimeNumbers[i] == true)           // i가 소수라면
            for (int j = i * i; j < max; j += i) // MAXIMUM보다 작은 i * (i + n)은 {n은 0이상}
                isPrimeNumbers[j] = false;       // 모두 소수가 아니다.

    // 소수로 선별된 수들을 골라 반환한다.
    vector<int> primeNumbers;
    for (int i = 2; i < max; i++)
        if (isPrimeNumbers[i] == true)
            primeNumbers.push_back(i);

    return primeNumbers;
}

int main(int argc, char const *argv[])
{
    int inputCount;

    scanf("%d", &inputCount);

    // printf("%d", inputCount);

    vector<int> numbers(inputCount, 0);
    int sum = 0;

    for (int i = 0; i < inputCount; i++)
    {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // for (int i = 0; i < inputCount; i++)
    //     printf("%d", numbers[i]);

    // printf("%d\n", sum);

    vector<int> primes = eratosthenes_prime(sum);

    // for (int i = 0; i < primes.size(); i++)
    // {
    //     printf("%d\n", primes[i]);
    // }

    // sort(numbers.begin(), numbers.end());

    // for (int i = 0; i < inputCount; i++)
    //     printf("%d", numbers[i]);

    vector<vector<vector<vector<int>>>> knapsack(inputCount, vector<vector<vector<int>>>(sum + 1, vector<vector<int>>()));

    for (int i = 0; i < inputCount; i++)
    {
        for (int w = 0; w <= sum; w++)
        {
            if (i > 0)
            {
                for (int j = 0; j < knapsack[i - 1][w].size(); j++)
                    knapsack[i][w].push_back(knapsack[i - 1][w][j]);

                if (w - numbers[i] >= 0)
                {
                    for (int j = 0; j < knapsack[i - 1][w - numbers[i]].size(); j++)
                    {
                        vector<int> temp(knapsack[i - 1][w - numbers[i]][j]);
                        temp.push_back(numbers[i]);

                        if (knapsack[i][w].end() == find(knapsack[i][w].begin(), knapsack[i][w].end(), temp))
                            knapsack[i][w].push_back(temp);
                    }
                }
            }

            vector<int> temp(1, numbers[i]);
            if (w == numbers[i] && knapsack[i][w].end() == find(knapsack[i][w].begin(), knapsack[i][w].end(), temp))
                knapsack[i][w].push_back(temp);
        }
    }

    // printf("\n");
    // for (int i = 0; i < inputCount; i++)
    // {
    //     for (int w = 0; w <= sum; w++)
    //     {
    //         printf("%d ", knapsack[i][w].size());
    //     }
    //     printf("\n");
    // }

    int result_count = 0;

    for (int i = 0; i < primes.size(); i++)
    {
        result_count += knapsack[inputCount - 1][primes[i]].size();
    }

    printf("%d", result_count);

    //    p[i][w] = 처음 i개 원소를 이용하여, w를 맞출수 있는 경우의 수...
    //       p p   p   p        p
    // i\w 0 1 2 3 4 5 6 7 8 9 10 11
    // 1  0 1
    // 1  0 1 1
    // 2
    // 7
    // i == 1
    // p[1][0] == 0
    // if (i == 1)
    // p[1][1] ==

    // i == 3 에서.. 하는일..
    // p[3][2] = p[2][0] (0이어도 가능) + 1
    // p[3][3] = p[2][1] == 0 ? 0 : p[2][1]
    // p[3][4] = p[2][2] == 0 ? 0 : p[2][2]

    return 0;
}
