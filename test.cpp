#include <tuple>

using namespace std;

tuple<int, int, int> MakeTuple()
{
    return {1, 2, 3};
}

int main(int argc, char const *argv[])
{
    tuple<int, int, int> t1 = {1, 2, 3};

    printf("%d %d %d\n", get<0>(t1), get<1>(t1), get<2>(t1));

    auto t2 = MakeTuple();

    printf("%d %d %d\n", get<0>(t2), get<1>(t2), get<2>(t2));

    return 0;
}
