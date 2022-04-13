#include <cstdio>
#include <vector>

using namespace std;

// MAXIMUM보다 작은 소수들을 구해 반환하는 함수
vector<int> eratosthenes_prime(int MAXIMUM)
{
    // 소수를 판별하기 위한 배열
    // 배열 index와 안의 수를 똑같이 맞추기위해 MAXIMUM + 1개로 설정했음.
    bool isPrimeNumbers[MAXIMUM + 1];
    fill_n(isPrimeNumbers, MAXIMUM + 1, true);

    // 에라토스테네스의 채
    // 소수가 아닌 수를 isPrimeNumbers에서 false로 바꿔준다.
    for (int i = 2; i * i <= MAXIMUM; i++)            // i => 2부터 MAXIMUM의 제곱근까지
        if (isPrimeNumbers[i] == true)                // i가 소수라면
            for (int j = i * i; j <= MAXIMUM; j += i) // MAXIMUM보다 작은 i * (i + n)은 {n은 0이상}
                isPrimeNumbers[j] = false;            // 모두 소수가 아니다.

    // 소수로 선별된 수들을 골라 반환한다.
    vector<int> primeNumbers;
    for (int i = 2; i <= MAXIMUM; i++)
        if (isPrimeNumbers[i] == true)
            primeNumbers.push_back(i);

    return primeNumbers;
}

int main(int argc, char const *argv[])
{
    int maximum;
    scanf("%d", &maximum);

    vector<int> prime_nums = eratosthenes_prime(maximum);

    for (int i = 0; i < prime_nums.size(); i++)
        printf("%d, ", prime_nums[i]);

    return 0;
}
