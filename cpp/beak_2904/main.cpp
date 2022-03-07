#include <cstdio>
#include <vector>

using namespace std;

// 선택될수있는 수의 최대 크기 (편의상 +1 했음)
const int MAXIMUM = 1000001;

// MAXIMUM보다 작은 소수들을 구해 반환하는 함수
vector<int> eratosthenes_prime()
{
    // 소수를 판별하기 위한 배열
    // 배열 index와 안의 수를 똑같이 맞추기위해 1000001개로 설정했음.
    bool isPrimeNumbers[MAXIMUM];
    fill_n(isPrimeNumbers, MAXIMUM, true);

    // 에라토스테네스의 채
    // 소수가 아닌 수를 isPrimeNumbers에서 false로 바꿔준다.
    for (int i = 2; i * i < MAXIMUM; i++)            // i => 2부터 MAXIMUM의 제곱근까지
        if (isPrimeNumbers[i] == true)               // i가 소수라면
            for (int j = i * i; j < MAXIMUM; j += i) // MAXIMUM보다 작은 i * (i + n)은 {n은 0이상}
                isPrimeNumbers[j] = false;           // 모두 소수가 아니다.

    // 소수로 선별된 수들을 골라 반환한다.
    vector<int> primeNumbers;
    for (int i = 2; i < MAXIMUM; i++)
        if (isPrimeNumbers[i] == true)
            primeNumbers.push_back(i);

    return primeNumbers;
}

int main(int argc, char const *argv[])
{
    // MAXIMUM보다 작은 소수 list
    vector<int> primeNumbers = eratosthenes_prime();

    // 할머니가 선택한 숫자의 개수 입력
    int countOfNumbers;
    scanf("%d", &countOfNumbers);

    // 입력된 index번째 숫자를 소인수 분해 했을때, 각 소수 개수 기록할 것이다.
    vector<vector<int>> indexFactor(countOfNumbers, vector<int>(primeNumbers.size(), 0));

    // 입력된 모든 숫자들의 소수가 총 몇개 존재하는지 기록할 것이다.
    vector<int> totalFactor(primeNumbers.size(), 0);

    // 입력하는 숫자 순회
    for (int i = 0; i < countOfNumbers; i++)
    {
        int number;
        scanf("%d", &number);

        // 소수 순회
        for (int j = 0; j < primeNumbers.size(); j++)
        {
            // 입력한 숫자가 현재 소수로 안나눠질때까지 반복
            while (number % primeNumbers[j] == 0)
            {
                number /= primeNumbers[j]; // 나눠진다면 나눠진 몫을 다시 숫자로 사용
                indexFactor[i][j]++;       // 해당 숫자 소수 기록
                totalFactor[j]++;          // 총 소수 기록
                if (number == 1)           // 1이 되버렸으면 순회 종료
                    break;
            }
            if (number == 1) // 1이 되버렸으면 순회 종료
                break;
        }
    }

    // 이동(곱셈 + 나눗셈) 횟수
    int countOfMove = 0;
    // 최대공약수
    int greatestCommonFactor = 1;

    // 소수 순회
    for (int i = 0; i < primeNumbers.size(); i++)
    {
        int commonFactor = totalFactor[i] / countOfNumbers; // 해당 소수의 총 개수를 숫자 개수로 나눠서 공약수가 될수 있는지 확인한다.

        if (totalFactor[i] > 0) // 공약수가 될수 있다면,
        {
            for (int j = 0; j < commonFactor; j++) // 최대공약수 변수에 곱해준다.
                greatestCommonFactor *= primeNumbers[i];

            for (int j = 0; j < countOfNumbers; j++) // 또한 소인수분해표에서 해당 인수가 부족한애들을 채우는 횟수 (이동횟수)를 센다.
                if (indexFactor[j][i] < commonFactor)
                    countOfMove += commonFactor - indexFactor[j][i];
        }
    }

    printf("%d %d", greatestCommonFactor, countOfMove);

    return 0;
}
