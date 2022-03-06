#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());

        // for (auto i : s)
        //     cout << i << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<char> s = vector<char>();

    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');

    Solution().reverseString(s);

    return 0;
}