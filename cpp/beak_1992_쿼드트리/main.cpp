#include <vector>
#include <cstdio>
#include <string>

using namespace std;

vector<vector<char>> matrix;

string GetQaudTreeString(int offset_y, int offset_x, int size)
{
    // 매트릭스 사이즈가 1
    if (size == 1 && matrix[offset_y][offset_x] == '1')
        return "1";
    if (size == 1 && matrix[offset_y][offset_x] == '0')
        return "0";

    string str = "(";
    str += GetQaudTreeString(offset_y, offset_x, size / 2);
    str += GetQaudTreeString(offset_y, offset_x + size / 2, size / 2);
    str += GetQaudTreeString(offset_y + size / 2, offset_x, size / 2);
    str += GetQaudTreeString(offset_y + size / 2, offset_x + size / 2, size / 2);
    str += ")";

    if (str.compare("(1111)") == 0)
        return "1";
    if (str.compare("(0000)") == 0)
        return "0";

    return str;
}

int main(int argc, char const *argv[])
{
    int map_size;
    scanf("%d", &map_size);

    matrix = vector<vector<char>>(map_size, vector<char>(map_size, '0'));

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size;)
        {
            char temp;
            scanf("%c", &temp);
            if (temp == '0' || temp == '1')
            {
                matrix[y][x] = temp;
                x++;
            }
        }
    }

    printf("%s", GetQaudTreeString(0, 0, map_size).c_str());

    return 0;
}