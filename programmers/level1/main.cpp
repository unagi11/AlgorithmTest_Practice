#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "";

    if (s.length() <= 0)
        return 0;
    else if (s.length() % 2 == 1)
        printf("%c", s.at(s.length() / 2 + 1));
    else
        printf("%c%c", s.at(s.length() / 2 - 1), s.at(s.length() / 2));
}