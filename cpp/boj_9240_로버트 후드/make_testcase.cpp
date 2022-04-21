#include <iostream>
#include <ctime>

using namespace std;

#define SIZE 100
#define RANGE 1'000

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    printf("%d\n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d %d\n", rand() % RANGE, rand() % RANGE);
    }

    return 0;
}
