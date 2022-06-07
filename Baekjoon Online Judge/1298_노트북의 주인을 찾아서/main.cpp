#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_PEOPLE 101
#define MAX_LAPTOP 5000

using namespace std;

vector<int> connect[MAX_PEOPLE];
bool visited[MAX_PEOPLE];
int owner[MAX_LAPTOP];

bool dfs(int a)
{
    if (visited[a] == true)
        return false;

    visited[a] = true;

    for (int b : connect[a])
    {
        if (owner[b] == -1 || dfs(owner[b]))
        {
            owner[b] = a;
            return true;
        }
    }

    return false;
}

int main()
{
    int num_people, num_expect;
    scanf("%d %d", &num_people, &num_expect);

    for (int i = 0; i < num_expect; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        connect[a].push_back(b);
    }

    int answer = 0;
    fill(owner, owner + MAX_LAPTOP, -1);
    for (int a = 1; a <= num_people; a++)
    {
        fill(visited, visited + MAX_PEOPLE, false);
        if (dfs(a))
            answer++;
    }

    printf("%d", answer);
}