#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<char>> matrix;

int main(int argc, char const *argv[])
{
    int rows, cols;

    scanf("%d %d\n", &rows, &cols);

    matrix = vector<vector<char>>(rows, vector<char>(cols));

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            scanf("%c", &matrix[y][x]);
            matrix[y][x] = matrix[y][x] - '0';
        }
        scanf("\n");
    }

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            printf("%d ", matrix[y][x]);
        }
        printf("\n");
    }

    return 0;
}
