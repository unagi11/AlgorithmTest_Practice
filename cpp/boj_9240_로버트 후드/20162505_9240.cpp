#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAP_SIZE 1'000 // 맵 사이즈

using namespace std;

// 좌표 자료구조
struct point
{
public:
    int x;
    int y;

    point() : x(0), y(0) {}
    point(int a, int b) : x(a), y(b) {}
};

int point_cnt = 0;    // 점 개수
vector<point> points; // 점들
point lftbtm;         // 최 하단 왼쪽 점
vector<point> stack;  // 그라함 스캔을 위한 스텍

// 거리 제곱
int distance(point a, point b)
{
    return (pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// 그라함 스캔전 정렬용 함수
bool compare(point a, point b)
{
    point t = lftbtm;

    double theta_a = atan2(a.y - t.y, a.x - t.x);
    double theta_b = atan2(b.y - t.y, b.x - t.x);

    // 같은 각도면 가까운거 먼저
    if (theta_a == theta_b)
        return distance(t, a) < distance(t, b);
    // 각도가 작은거 먼저
    else
        return theta_a < theta_b;
}

// ccw를 알기위한 signarea 함수
int signarea(point a, point b, point c)
{
    return (a.x * b.y - a.y * b.x + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
}

int main(int argc, char const *argv[])
{
#pragma region 입력부 및 좌하단점 찾기
    scanf("%d", &point_cnt);

    points = vector<point>(point_cnt);

    int btm_idx = 0;

    for (int i = 0; i < point_cnt; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);

        // 가장 밑좌표의 index를 기록한다.
        if (points[btm_idx].y > points[i].y)
            btm_idx = i;
        // 밑좌표에서 같다면 left most를 선택한다.
        else if (points[btm_idx].y == points[i].y && points[btm_idx].x > points[i].x)
            btm_idx = i;
    }

    lftbtm.x = points[btm_idx].x;
    lftbtm.y = points[btm_idx].y;
    points.erase(points.begin() + btm_idx);
#pragma endregion

#pragma region 그라함 스캔
    // 좌하단 점과의 각도를 비교하여 정렬한다.
    sort(points.begin(), points.end(), compare);

    stack.push_back(lftbtm);
    stack.push_back(points[0]);

    int index = 1;
    while (index < points.size())
    {
        while (stack.size() >= 2 && signarea(stack[stack.size() - 2], stack[stack.size() - 1], points[index]) <= 0)
            stack.pop_back();
        stack.push_back(points[index++]);
    }
#pragma endregion

#pragma region 최대거리 쌍 찾기 및 출력
    int max_distance = 0;
    for (int i = 0; i < stack.size(); i++)
        for (int j = i + 1; j < stack.size(); j++)
            max_distance = max(max_distance, distance(stack[i], stack[j]));
    printf("%lf", sqrt(max_distance));
#pragma endregion

    return 0;
}
