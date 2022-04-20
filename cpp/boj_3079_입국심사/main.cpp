#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> counter_time;

int main(int argc, char const *argv[])
{
    int counter_count; // N
    int friends_count; // M

    scanf("%d %d", &counter_count, &friends_count);

    counter_time = vector<long long>(counter_count, 0);

    long long max_time = 0;
    for (int i = 0; i < counter_count; i++)
    {
        scanf("%lld", &counter_time[i]);
        if (counter_time[i] > max_time)
            max_time = counter_time[i];
    }

    long long min = 1;

    // long long max = 1'000'000'000'000'000'000; < 안됨
    long long max = friends_count * max_time;
    long long pivot;

    while (min < max)
    {
        pivot = (min + max) / 2;
        long long immigration_count = 0;

        for (int i = 0; i < counter_count; i++)
            immigration_count += pivot / counter_time[i];

        // printf("pivot : %d, count : %d\n", pivot, immigration_count);

        // 입국 검사 횟수가 적다면 시간을 늘려야한다. (현재 제외)
        if (immigration_count < friends_count)
            min = pivot + 1;
        // 입국 검사 횟수가 많다면 시간을 줄여야한다. (현재 포함)
        else
            max = pivot;
    }

    printf("%lld", min);

    return 0;
}
