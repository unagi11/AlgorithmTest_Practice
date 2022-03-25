#include <cstdio>
#include <vector>
#include <map>
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

    vector<int> candyList(inputCount, 0);
    int sum = 0;
    map<int, int> candyCount;
    int zeroCandy = 0;

    for (int i = 0; i < inputCount; i++)
    {
        scanf("%d", &candyList[i]);
        sum += candyList[i];
        if (candyList[i] != 0)
            candyCount[candyList[i]]++;
        else
            zeroCandy++;
    }

    vector<int> primes = eratosthenes_prime(sum);
    vector<int> knapsack(sum + 1, 0);

    for (auto i = candyCount.begin(); i != candyCount.end(); i++)
    {
        for (int w = sum; w >= 0; w--)
        {
            for (int j = i->second; j > 0; j--)
            {
                int wj = (i->first * j);

                // printf("wj: %d\n", wj);

                if (w - wj >= 0 && knapsack[w - wj] != 0)
                {
                    knapsack[w] += knapsack[w - wj];
                }
                if (w == wj)
                {
                    knapsack[w]++;
                }
            }
        }

        // for (int w = 0; w <= sum; w++)
        // {
        //     printf("%d ", knapsack[w]);
        // }
        // printf("\n");
    }

    long long result_count = 0;

    for (int i = 0; i < primes.size(); i++)
        result_count = knapsack[primes[i]] == 0 ? result_count : knapsack[primes[i]] + result_count + zeroCandy;

    printf("%d", result_count);

    return 0;
}
