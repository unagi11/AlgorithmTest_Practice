#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 500'001;

vector<int> eratosthenes_prime(int max)
{
    vector<bool> isPrimeNumbers(max, true);

    for (int i = 2; i * i <= max; i++)
        if (isPrimeNumbers[i] == true)
            for (int j = i * i; j < max; j += i)
                isPrimeNumbers[j] = false;

    vector<int> primeNumbers;
    for (int i = 2; i <= max; i++)
        if (isPrimeNumbers[i] == true)
            primeNumbers.push_back(i);

    return primeNumbers;
}

int main(int argc, char const *argv[])
{
    int inputCount;

    scanf("%d", &inputCount);

    vector<int> candyList(inputCount, 0);
    map<int, int> candyCount;
    int zeroCandy = 1;

    for (int i = 0; i < inputCount; i++)
    {
        scanf("%d", &candyList[i]);
        if (candyList[i] != 0)
            candyCount[candyList[i]]++;
        else
            zeroCandy++;
    }

    vector<int> primes = eratosthenes_prime(MAX);
    vector<long long> knapsack(MAX, 0);

    for (auto i = candyCount.begin(); i != candyCount.end(); i++)
    {
        for (int w = MAX; w >= 0; w--)
        {
            for (int j = 1; j <= i->second; j++)
            {
                int wj = (i->first * j);

                if (w - wj > 0 && knapsack[w - wj] != 0)
                    knapsack[w] += knapsack[w - wj];

                if (w == wj)
                    knapsack[w]++;
            }
        }
    }

    long long result_count = 0;

    for (int i = 0; i < primes.size(); i++)
        result_count += knapsack[primes[i]];

    result_count *= zeroCandy;

    printf("%lld", result_count);

    return 0;
}
