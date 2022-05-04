#include <cstdio>
#include <vector>
#include <algorithm>

#define N_MAX 1120
#define K_MAX 14

using namespace std;

vector<int> primes;
vector<vector<vector<int>>> dp;

int get_dp(int n, int k, int x)
{
    if (n < 1 || k < 1 || x < 1)
        return 0;

    if (dp[n][k][x] != -1)
        return dp[n][k][x];

    int temp = 0;
    for (int i = 0; i < x; i++)
    {
        temp = get_dp(n - primes[i], k - 1, i) + get_dp(n, k, i);
    }

    return dp[n][k][x] = temp;
}

vector<int> eratosthenes_func(int max)
{
    vector<bool> isPrime(max, true);
    for (int i = 2; i * i <= max; i++)
        if (isPrime[i])
            for (int j = i * i; j <= max; j += i)
                isPrime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= max; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

int main(int argc, char const *argv[])
{
    int count;
    scanf("%d", &count);

    primes = eratosthenes_func(N_MAX);

    // dp[n][k][x] : 아래의 조건을 만족하는 경우의 수 개수.
    // - n : 총합 n을 만든다.
    // - k : k 개의 숫자를 사용한다.
    // - x : 앞에서 x 번째 소수만 사용한다.
    dp = vector<vector<vector<int>>>(N_MAX + 1, vector<vector<int>>(K_MAX + 1, vector<int>(primes.size(), -1)));

    printf("%d\n", primes.size());

    for (int i = 0; i < primes.size(); i++)
    {
        
    }

    return 0;
}