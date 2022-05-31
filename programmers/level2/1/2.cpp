#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

multiset<string> set1;
multiset<string> set2;

int solution(string str1, string str2)
{

    cout << str1 << ", " << str2 << endl;

    int answer = 0;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        char a = tolower(str1.at(i));
        char b = tolower(str1.at(i + 1));

        if (isalpha(a) && isalpha(b))
        {
            string temp;
            temp += a;
            temp += b;
            set1.insert(temp);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        char a = tolower(str2.at(i));
        char b = tolower(str2.at(i + 1));

        if (isalpha(a) && isalpha(b))
        {
            string temp;
            temp += a;
            temp += b;
            set2.insert(temp);
        }
    }

    for (auto i : set1)
    {
        cout << i << endl;
    }
    cout << endl;
    for (auto i : set2)
    {
        cout << i << endl;
    }

    vector<string> uset(set1.size() + set2.size());
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), uset.begin());

    vector<string> iset(set1.size() + set2.size());
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), iset.begin());

    cout << uset.size() << ", " << iset.size() << endl;
    ;

    int size1 = 0;
    int size2 = 0;

    for (int i = 0; i < uset.size(); i++)
    {
        if (uset[i] == "")
        {
            size1 = i;
            break;
        }
    }
    for (int i = 0; i < iset.size(); i++)
    {
        if (uset[i] == "")
        {
            size2 = i;
            break;
        }
    }

    if (size1 == 0 && size2 == 0)
    {
        return 65536;
    }

    return 65536 * size1 / size2;
}

int main(int argc, char const *argv[])
{
    cout << solution("FRANCE", "french");

    return 0;
}
