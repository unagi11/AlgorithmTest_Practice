#include <cstdio>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

vector<char> first(1, '-');
vector<char> second(1, '-');

int main(int argc, char const *argv[])
{
    // 위에줄 입력
    char c = getchar();
    while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
    {
        first.push_back(c);
        c = getchar();
    }

    // 아래줄 입력
    c = getchar();
    while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
    {
        second.push_back(c);
        c = getchar();
    }

    short dp1[second.size()];
    short dp2[second.size()];
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    vector<bitset<34'002>> path_bits(17'001, bitset<34'002>()); // 17'001 * 17'001 * 2

    dp1[0] = 0;
    // b11 : add, left
    for (int j = 1; j < second.size(); j++)
    {
        dp1[j] = j;
        path_bits[0].set(j * 2 + 0, true);
        path_bits[0].set(j * 2 + 1, true);
    }

    for (int i = 1; i < first.size(); i++)
    {
        // for (int i = 0; i < second.size(); i++)
        //     printf("%d", dp1[i]);
        // printf("\n");

        // b10 : delete, up
        dp2[0] = i;
        path_bits[i].set(0 * 2 + 0, true);
        path_bits[i].set(0 * 2 + 1, false);

        for (int j = 1; j < second.size(); j++)
        {
            bool val = first[i] != second[j];
            short min = 32'767;

            // b10 : delete, up
            if (min > dp1[j] + 1)
            {
                // printf("dp[%d,%d] > dp[%d,%d] delete %c > %c\n", i - 1, j, i, j, first[i], second[j]);
                min = dp1[j] + 1;
                path_bits[i].set(j * 2 + 0, true);
                path_bits[i].set(j * 2 + 1, false);
            }
            // b11 : add, left
            if (min > dp2[j - 1] + 1)
            {
                // printf("dp[%d,%d] > dp[%d,%d] add %c > %c\n", i, j - 1, i, j, first[i], second[j]);
                min = dp2[j - 1] + 1;
                path_bits[i].set(j * 2 + 0, true);
                path_bits[i].set(j * 2 + 1, true);
            }
            // b00 : copy, upleft
            if (min > dp1[j - 1] + 0 && val == 0)
            {
                // printf("dp[%d,%d] > dp[%d,%d] copy %c > %c\n", i - 1, j - 1, i, j, first[i], second[j]);
                min = dp1[j - 1] + 0;
                path_bits[i].set(j * 2 + 0, false);
                path_bits[i].set(j * 2 + 1, false);
            }
            // b01 : modify, upleft
            if (min > dp1[j - 1] + 1 && val == 1)
            {
                // printf("dp[%d,%d] > dp[%d,%d] modify %c > %c\n", i - 1, j - 1, i, j, first[i], second[j]);
                min = dp1[j - 1] + 1;
                path_bits[i].set(j * 2 + 0, false);
                path_bits[i].set(j * 2 + 1, true);
            }
            // printf("%d%d\n", (bool)path_bits[i][j * 2 + 0], (bool)path_bits[i][j * 2 + 1]);

            dp2[j] = min;
        }

        memcpy(dp1, dp2, second.size() * sizeof(short));
        memset(dp2, 0, sizeof(dp2));
    }

    // for (int i = 0; i < second.size(); i++)
    //     printf("%d", dp1[i]);
    // printf("\n");

    int y = first.size() - 1;
    int x = second.size() - 1;

    vector<char> cmds;
    vector<char> chars;

    while (y != 0 || x != 0) // (x, y)가 (0, 0)가 될때까지 반복
    {
        bool bit1 = path_bits[y][x * 2 + 0];
        bool bit2 = path_bits[y][x * 2 + 1];

        // printf("%d %d %d%d\n", y, x, bit1, bit2);

        // b00 : copy, upleft
        if (bit1 == false && bit2 == false)
        {
            cmds.push_back('c');
            chars.push_back(first[y]);
            y--;
            x--;
        }
        // b01 : modify, upleft
        else if (bit1 == false && bit2 == true)
        {
            cmds.push_back('m');
            chars.push_back(second[x]);
            y--;
            x--;
        }
        // b10 : delete, up
        else if (bit1 == true && bit2 == false)
        {
            cmds.push_back('d');
            chars.push_back(first[y]);
            y--;
        }
        // b11 : add, left
        else if (bit1 == true && bit2 == true)
        {
            cmds.push_back('a');
            chars.push_back(second[x]);
            x--;
        }
    }

    // printf("\n\n");
    for (int i = cmds.size() - 1; i >= 0; i--)
        printf("%c %c\n", cmds[i], chars[i]);

    return 0;
}