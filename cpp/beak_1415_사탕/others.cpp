#include <cstdio>
#include <vector>
using namespace std;

int n, ccnt[10001];
long long d[500005];
vector<int> cvec;
bool p[500005];

void getprimes()
{
    for (int i = 2; i <= 500000; i++)
        p[i] = 1;
    for (int i = 2; i * i <= 500000; i++)
        if (p[i])
            for (int j = i * i; j <= 500000; j += i)
                p[j] = 0;
}

int main()
{
    getprimes();

    scanf("%d", &n);
    int zcnt = 1;
    d[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 0)
        {
            zcnt++;
            continue;
        }
        if (ccnt[x] == 0)
        {
            cvec.push_back(x);
        }
        ccnt[x]++;
    }

    for (int now : cvec)
    {
        for (int i = 500000; i >= 0; i--)
        {
            for (int j = 1; j <= ccnt[now]; j++)
            {
                if (i - now * j < 0)
                    break;
                d[i] += d[i - now * j];
            }
        }
    }

    long long ans = 0;
    for (int i = 2; i <= 500000; i++)
    {
        // if (i < 30) printf("* %d\n", d[i]);
        if (p[i])
            ans += d[i];
    }

    printf("%lld\n", ans * zcnt);

    return 0;
}