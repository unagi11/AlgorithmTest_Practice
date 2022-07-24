#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 201 // 카라와 티셔츠의 최대개수

vector<int> vt[MAX];

int match[MAX];
bool visited[MAX];

int numOfShirts, numOfKaras;

bool dfs(int a)
{
    if (visited[a])
        return false;

    visited[a] = true;

    for (int b : vt[a])
        if (match[b] == -1)
        {
            match[b] = a;
            return true;
        }

    for (int b : vt[a])
        if (dfs(match[b]))
        {
            match[b] = a;
            return true;
        }

    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &numOfShirts, &numOfKaras);

    vector<int> shirts;
    for (int i = 0; i < numOfShirts; i++)
    {
        int temp;
        scanf("%d", &temp);
        shirts.push_back(temp);
    }

    vector<int> karas;
    for (int i = 0; i < numOfKaras; i++)
    {
        int temp;
        scanf("%d", &temp);
        karas.push_back(temp);
    }

    for (int i = 0; i < numOfShirts; i++)
    {
        for (int j = 0; j < numOfKaras; j++)
        {
            if (karas[j] * 2 >= shirts[i] && karas[j] * 4 <= shirts[i] * 3)
                vt[i].push_back(j);
            else if (karas[j] >= shirts[i] && karas[j] * 4 <= shirts[i] * 5)
                vt[i].push_back(j);
        }
    }

    int count = 0;
    fill(match, match + MAX, -1);
    for (int i = 0; i < numOfShirts; i++)
    {
        fill(visited, visited + MAX, false);
        if (dfs(i))
            count++;
    }

    printf("%d", count);

    return 0;
}