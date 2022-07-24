#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
// 조건을 만족하는 최소값을 구하는 경우
// min : 매개변수 범위의 최소값
// max : 매개변수 범위의 최대값
int Minimum_Parametric_Searching(int min, int max, int x)
{
    // min과 max가 같아지는 시점에 종료된다.
    while (min < max)
    {
        int pivot = (min + max) / 2; // .5 내림으로 교착상태를 막는다.

        if (pivot > x)       // 조건을 만족한다면,
            max = pivot;     // pivot을 포함하면서 pivot보다 작은 값을 찾을수 있는 범위로 좁혀나간다.
        else                 // 조건을 만족하지 않는다면,
            min = pivot + 1; // pivot을 제외하면서 pivot보다 큰 값을 찾을수 있는 범위로 좁혀나간다.
    }

    return min;
}

// 조건을 만족하는 최대값을 구하는 경우
// min : 매개변수 범위의 최소값
// max : 매개변수 범위의 최대값
int Maximum_Parametric_Searching(int min, int max, int x)
{
    // min과 max가 같아지는 시점에 종료된다.
    while (min < max)
    {
        int pivot = (min + max + 1) / 2; // .5 올림으로 교착상태를 막는다.

        if (pivot < x)       // 조건을 만족한다면,
            min = pivot;     // pivot을 포함하면서 pivot보다 큰 값을 찾을수 있는 범위로 좁혀나간다.
        else                 // 조건을 만족하지 않는다면,
            max = pivot - 1; // pivot을 제외하면서 pivot보다 작은 값을 찾을수 있는 범위로 좁혀나간다.
    }

    return max;
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 80; i++)
    {
        printf("%d\n", Maximum_Parametric_Searching(0, 100, i));
    }

    for (int i = 1; i < 80; i++)
    {
        printf("%d\n", Minimum_Parametric_Searching(0, 100, i));
    }

    return 0;
}
