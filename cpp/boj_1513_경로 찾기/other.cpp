#include <cstdio>
#include <cstring>

int D[51][51][51][51];

const int mod = 1000007;
int chk[51][51];

int n, m, c;

int f(int i, int j, int k, int l)
{

    if (!(i >= 1 && i <= n && j >= 1 && j <= m))
        return 0;

    int &ret = D[i][j][k][l];
    if (ret != -1)
        return ret;

    ret = 0;
    int gameNum = chk[i][j];
    if (gameNum == 0)
    {
        ret = (f(i - 1, j, k, l) + f(i, j - 1, k, l)) % mod;
    }
    else
    {
        if (gameNum == k)
        {
            for (int z = 0; z < k; z++)
            {
                ret += (f(i - 1, j, z, l - 1) + f(i, j - 1, z, l - 1)) % mod;
            }
        }
    }

    return ret;
}

int main()
{

    scanf("%d %d %d", &n, &m, &c);

    memset(D, -1, sizeof(D));
    for (int i = 1; i <= c; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        chk[x][y] = i;
    }

    if (chk[1][1] == 0)
        D[1][1][0][0] = 1;
    else
        D[1][1][chk[1][1]][1] = 1;
    for (int i = 0; i <= c; i++)
    {
        int ans = 0;
        for (int j = 0; j <= c; j++)
        {
            ans = (ans + f(n, m, j, i)) % mod;
        }
        printf("%d ", ans);
    }

    return 0;
}

// 출처 : https: // jsg1504.tistory.com/38 [장화신은 고양이]