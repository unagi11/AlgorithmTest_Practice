#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>

using namespace std;

vector<int> counter_time;

long long solution(int n, vector<int> times)
{
    long long friends_count = n;
    long long answer = 0;

    long long max_time = 0;
    for (int i = 0; i < times.size(); i++)
        if (times[i] > max_time)
            max_time = times[i];

    long long min = 1;
    long long max = friends_count * max_time;
    long long pivot;

    while (min < max)
    {
        pivot = (min + max) / 2;
        long long immigration_count = 0;

        for (int i = 0; i < times.size(); i++)
            immigration_count += pivot / times[i];

        // 입국 검사 횟수가 적다면 시간을 늘려야한다. (현재 제외)
        if (immigration_count < friends_count)
            min = pivot + 1;
        // 입국 검사 횟수가 많다면 시간을 줄여야한다. (현재 포함)
        else
            max = pivot;
    }

    return min;
}