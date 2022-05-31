#include <iostream>

using namespace std;

long long solution(int w, int h)
{
    long long answer = w * h;

    long long temp = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            long long _y = h * x;
            long long _x = w * y;

            // cout << y << ", " << x << ": " << _y << ", " << _x << endl;

            if ((_y >= y * w && _y < (y + 1) * w) || (_x >= x * h && _x < (x + 1) * h))
            {
                // cout << true << endl;
                temp++;
            }
        }
    }

    return answer = answer - temp;
}

int main(int argc, char const *argv[])
{
    cout << solution(8, 12);

    return 0;
}
