//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

int paper_count[3] = {
    0,
};

void isPaper(int start_y, int start_x, int size)
{
    bool isbreak = false;

    for (int y = start_y; y < start_y + size; y++)
    {
        for (int x = start_x; x < start_x + size; x++)
        {
            if (matrix[start_y][start_x] != matrix[y][x])
            {
                isbreak = true;
                break;
            }
        }
        if (isbreak)
            break;
    }

    if (isbreak)
    {
        int new_size = size / 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                isPaper(start_y + new_size * i, start_x + new_size * j, new_size);
    }
    else
    {
        paper_count[matrix[start_y][start_x]]++;
    }
}

int main(int argc, char const **argv)
{
    int size = 0;

    scanf("%d", &size);

    matrix = vector<vector<int>>(size, vector<int>(size, 0));

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            int temp = 0;
            scanf("%d", &temp);
            matrix[y][x] = temp + 1;
        }
    }

    // for (int y = 0; y < size; y++)
    //{
    //	for (int x = 0; x < size; x++)
    //		printf("%d", matrix[y][x]);
    //	printf("\n");
    // }

    isPaper(0, 0, size);

    printf("%d\n%d\n%d", paper_count[0], paper_count[1], paper_count[2]);

    return 0;
}
