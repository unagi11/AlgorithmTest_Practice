#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 203 // 카라와 티셔츠의 최대개수

vector<int> ableKara[MAX];

int karaToShirts[MAX];
bool isMatched[MAX];

int numOfShirts, numOfKaras;

bool dfs(int shirtNumber)
{
    for (int i = 0; i < ableKara[shirtNumber].size(); i++)
    {
        int karaNumber = ableKara[shirtNumber][i];

        if (isMatched[karaNumber] == true)
            continue;
        isMatched[karaNumber] = true;

        if (karaToShirts[karaNumber] == 0 || dfs(karaToShirts[karaNumber]))
        {
            karaToShirts[karaNumber] = shirtNumber;
            return true;
        }
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
            if (karas[j] >= shirts[i] * 0.5 && karas[j] <= shirts[i] * 0.75)
                ableKara[i].push_back(j);
            if (karas[j] >= shirts[i] && karas[j] <= shirts[i] * 1.25)
                ableKara[i].push_back(j);
        }
    }

    // printf("\n");
    // printf("\n");

    // for (int i = 0; i < numOfShirts; i++)
    // {
    //     printf("%d : ", i);
    //     for (int j = 0; j < ableKara[i].size(); j++)
    //     {
    //         printf("%d ,", ableKara[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // printf("\n");

    int count = 0;
    for (int i = 0; i < numOfShirts; i++)
    {
        fill(isMatched, isMatched + MAX, false);
        if (dfs(i))
            count++;
    }

    printf("%d", count);
    // for (int i = 0; i < MAX; i++)
    // {
    //     if (karaToShirts[i] != 0)
    //     {
    //         printf("%d -> %d \n", karaToShirts[i], i);
    //     }
    // }

    return 0;
}
