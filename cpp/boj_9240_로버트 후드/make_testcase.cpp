#include <iostream>
#include <ctime>

using namespace std;

#define SIZE 100'000
#define RANGE 1'000

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    printf("%d\n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        int sign1 = rand() % 2 == 0 ? -1 : 1;
        int sign2 = rand() % 2 == 0 ? -1 : 1;

        int val1 = rand() % RANGE;
        int val2 = rand() % RANGE;

        printf("%d %d\n", sign1 * val1, sign2 * val2);
    }

    return 0;
}
