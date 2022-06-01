#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

int main(int argc, char const *argv[])
{
    int numOfShirts, numOfKaras;
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

    vector<vector<int>> avilKaraRange(numOfShirts, vector<int>());

    for (int i = 0; i < numOfShirts; i++)
    {
        for (int j = 0; j < numOfKaras; j++)
        {
            if (karas[j] * 2 >= shirts[i] && karas[j] * 4 <= shirts[i] * 3)
                avilKaraRange[i].push_back(karas[j]);
            if (karas[j] >= shirts[i] && karas[j] * 4 <= shirts[i] * 5)
                avilKaraRange[i].push_back(karas[j]);
        }
    }

    // printf("\n");
    // printf("\n");

    // 가설 : 선택권이 적은 티셔츠먼저 고르게 하면 최대한 많이 만들수 있다?

    // 선택권이 적은 티셔츠 순서대로 정렬후
    // 한쌍 매칭, 매칭된 카라 삭제
    // 반복.

    sort(avilKaraRange.begin(), avilKaraRange.end(), compare);

    int seraCount = 0;

    while (avilKaraRange.size() > 0)
    {
        // for (int i = 0; i < avilKaraRange.size(); i++)
        // {
        //     printf("%d : ", shirts[i]);
        //     for (int j = 0; j < avilKaraRange[i].size(); j++)
        //     {
        //         printf("%d, ", avilKaraRange[i][j]);
        //     }
        //     printf("\n");
        // }
        if (avilKaraRange[0].size() == 0)
        {
            avilKaraRange.erase(avilKaraRange.begin());
            continue;
        }

        int kara = avilKaraRange[0][0];
        seraCount++;

        avilKaraRange.erase(avilKaraRange.begin());

        for (int j = 0; j < avilKaraRange.size(); j++)
        {
            auto it = find(avilKaraRange[j].begin(), avilKaraRange[j].end(), kara);

            if (it == avilKaraRange[j].end())
                continue;
            else
                avilKaraRange[j].erase(it);
        }

        sort(avilKaraRange.begin(), avilKaraRange.end(), compare);
    }

    printf("%d", seraCount);

    return 0;
}
