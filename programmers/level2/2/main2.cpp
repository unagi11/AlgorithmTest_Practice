#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    for (int w = 3; w <= 5000; w++)
    {
        if ((brown + yellow) % w != 0)
            continue;

        int h = (brown + yellow) / w;

        if (2 * (w + h) - 4 == brown && h > 0)
        {
            if (w > h)
                return {w, h};
            else
                return {h, w};
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> a = solution(24, 24);

    printf("%d %d", a[0], a[1]);

    return 0;
}
