#include <iostream>

using namespace std;

long long solution(int w, int h)
{
    long long answer = w * h;

    int x = 0;
    int y = 0;

    long long count = 0;

    while (x < w || y < h)
    {
        cout << x << ", " << y << endl;

        count++;

        float tan = h / w;

        int _y = h * (x + 1);
        int _x = w * (y + 1);

        // 대각선으로 간다.
        if (_y == (y)*w && _x == (y)*h)
        {
            y++;
            x++;
        }
        // 아래로 간다.
        else if (x * h <= (_x - 1) * h && _x * h < (x)*h)
        {
            y++;
        }
        // 오른쪽으로 간다.
        else
        {
            x++;
        }
    }

    return answer = answer - count;
}
int main(int argc, char const *argv[])
{
    cout << solution(2, 3);

    return 0;
}
