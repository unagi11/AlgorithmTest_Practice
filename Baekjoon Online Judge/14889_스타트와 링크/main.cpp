#include <cstdio>
#include <vector>
#include <iostream>
#include <stdint.h>

#define MAX_HUMAN 21

using namespace std;

int num_human;
int ability[MAX_HUMAN][MAX_HUMAN];

vector<int> team_a;
vector<int> team_b;

int answer = INT32_MAX;

int calc()
{
    int a_value = 0, b_value = 0;
    for (int i = 0; i < num_human / 2; i++)
    {
        for (int j = i + 1; j < num_human / 2; j++)
        {
            int a1 = team_a[i];
            int a2 = team_a[j];
            int b1 = team_b[i];
            int b2 = team_b[j];

            a_value += ability[a1][a2] + ability[a2][a1];
            b_value += ability[b1][b2] + ability[b2][b1];
        }
    }

    if (a_value > b_value)
        return a_value - b_value;
    else
        return b_value - a_value;
}

void dfs(int index)
{

    if (team_a.size() == num_human / 2 && team_b.size() == num_human / 2)
    {
        // printf("a : ");
        // for (int a : team_a)
        //     printf("%d ", a);
        // printf("\nb : ");
        // for (int b : team_b)
        //     printf("%d ", b);
        // printf("\n");
        answer = min(answer, calc());
        return;
    }
    else if (team_a.size() == num_human / 2)
    {
        team_b.push_back(index);
        dfs(index + 1);
        team_b.pop_back();
    }
    else if (team_b.size() == num_human / 2)
    {
        team_a.push_back(index);
        dfs(index + 1);
        team_a.pop_back();
    }
    else
    {
        team_a.push_back(index);
        dfs(index + 1);
        team_a.pop_back();

        team_b.push_back(index);
        dfs(index + 1);
        team_b.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d\n", &num_human);

    for (int i = 1; i <= num_human; i++)
        for (int j = 1; j <= num_human; j++)
            scanf("%d ", &ability[i][j]);

    // for (int i = 1; i <= num_human; i++)
    // {
    //     for (int j = 1; j <= num_human; j++)
    //         printf("%d ", ability[i][j]);
    //     printf("\n");
    // }

    dfs(1);

    printf("%d", answer);

    return 0;
}
