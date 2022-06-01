// Priority Queue 이용한 Dijkstra + DP 연습

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <time.h>

class element
{
public:
    long long cost;
    int pos;
    int pav;

    element(long long _cost, int _pos, int _pav)
    {
        cost = _cost;
        pos = _pos;
        pav = _pav;
    };

    bool operator>(element other)
    {
        return cost > other.cost;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
