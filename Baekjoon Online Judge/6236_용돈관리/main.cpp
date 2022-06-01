#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int countOfDays, maximumCountOfWithdraw;

    scanf("%d %d\n", &countOfDays, &maximumCountOfWithdraw);

    vector<int> needMoneys;

    int minimum = 0;
    int maximum = 0;
    int pivot = 0;

    for (int i = 0; i < countOfDays; i++)
    {
        int temp;
        scanf("%d\n", &temp);
        needMoneys.push_back(temp);

        minimum = temp > minimum ? temp : minimum;
        maximum += temp;
    }

    while (minimum < maximum)
    {
        pivot = (minimum + maximum) / 2;

        int countOfWithdraw = 1;
        int currentMoney = pivot;

        for (int i = 0; i < countOfDays; i++)
        {
            if (currentMoney < needMoneys[i])
            {
                countOfWithdraw++;
                currentMoney = pivot;
            }
            currentMoney -= needMoneys[i];
        }

        if (maximumCountOfWithdraw < countOfWithdraw)
            minimum = pivot + 1;
        else
            maximum = pivot;
    }

    printf("%d", maximum);

    return 0;
}
