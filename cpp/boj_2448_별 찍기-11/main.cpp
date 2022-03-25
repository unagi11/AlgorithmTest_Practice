#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int GetHeight(int generation)
{
    return 3 * pow(2, generation);
}

int GetWidth(int generation)
{
    if (generation == 0)
        return 5;

    return GetWidth(generation - 1) * 2 + 1;
}

vector<vector<char>> pasteTo(vector<vector<char>> paste, vector<vector<char>> to, int start_x, int start_y)
{
    for (int y = 0; y < paste.size(); y++)
        for (int x = 0; x < paste[y].size(); x++)
            to[start_y + y][start_x + x] = paste[y][x];

    return to;
}

vector<vector<char>> GetMatrix(int generation)
{
    int width = GetWidth(generation);
    int height = GetHeight(generation);

    vector<char> row(width, ' ');
    vector<vector<char>> matrix(height, row);

    if (generation == 0)
    {
        matrix[0][2] = '*';
        matrix[1][1] = '*';
        matrix[1][3] = '*';
        matrix[2][0] = '*';
        matrix[2][1] = '*';
        matrix[2][2] = '*';
        matrix[2][3] = '*';
        matrix[2][4] = '*';
    }
    else
    {
        vector<vector<char>> parent = GetMatrix(generation - 1);
        int parent_width = (width - 1) / 2;
        int parent_height = height / 2;

        matrix = pasteTo(parent, matrix, (parent_width + 1) / 2, 0);
        matrix = pasteTo(parent, matrix, 0, parent_height);
        matrix = pasteTo(parent, matrix, parent_width + 1, parent_height);
    }

    return matrix;
}

int main(int argc, char const *argv[])
{
    int line = 0, i;

    scanf("%d", &line);

    line = line / 3;

    for (i = 0; line % 2 == 0; i++)
    {
        line = line / 2;
    }

    vector<vector<char>> m = GetMatrix(i);

    // printf("hello %d %d\n", m.size(), m[0].size());

    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            printf("%c", m[i][j]);
        }

        if (i != m.size() - 1)
            printf("\n");
    }

    return 0;
}
