#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string temp = "";

        for (string::iterator it = s.begin(); it < s.end(); it++)
        {
            *it = tolower(*it);

            if ((*it >= 'a' && *it <= 'z') || (*it >= '0' && *it <= '9'))
                temp += *it;
        }

        for (int i = 0; i < temp.length() / 2; i++)
            if (temp[i] != temp[temp.length() - 1 - i])
                return false;

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    cout << sol.isPalindrome("hello") << endl;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;

    return 0;
}
