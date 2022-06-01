#include <cstdio>
#include <algorithm>
#include <vector>

#define MATRIX_SIZE 10
#define KINDS_PAPER 5

using namespace std;

int answer = 25;

// bool promising(vector<int> used_paper, vector<vector<char>> matrix)
// {
//     // for (int i = 0; i < KINDS_PAPER; i++)
//     // {
//     //     printf("%d ", used_paper[i]);
//     // }
//     // printf("\n");

//     // for (int i = 0; i < MATRIX_SIZE; i++)
//     // {
//     //     for (int j = 0; j < MATRIX_SIZE; j++)
//     //     {
//     //         printf("%d ", matrix[i][j]);
//     //     }
//     //     printf("\n");
//     // }

//     for (int i = 0; i < 5; i++)
//         if (used_paper[i] > 5)
//             return false;

//     // for (int y = 0; y < MATRIX_SIZE; y++)
//     //     for (int x = 0; x < MATRIX_SIZE; x++)
//     //         if (matrix[y][x] < 0)
//     //             return false;

//     return true;
// }

void backtracking(vector<int> used_paper, vector<vector<char>> matrix, int last_size, int last_y, int last_x)
{

    bool isPromising = true;
    for (int i = 0; i < KINDS_PAPER; i++)
        if (used_paper[i] > 5)
            isPromising = false;

    for (int y = 0; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            if (matrix[y][x] < 0)
                isPromising = false;

    if (isPromising)
    {
        // 답인가?
        bool isAnswer = true;
        for (int y = 0; y < MATRIX_SIZE; y++)
        {
            for (int x = 0; x < MATRIX_SIZE; x++)
            {
                if (matrix[y][x] != 0)
                {
                    isAnswer = false;
                    break;
                }
            }
            if (isAnswer == false)
                break;
        }

        // 답이라면
        if (isAnswer)
        {
            int sum = 0;
            for (int i = 0; i < 5; i++)
                sum += used_paper[i];
            // answer = answer > sum ? sum : answer;
            printf("%d", sum);
            exit(0);
        }
        else
        {
            bool isFirst = true;

            // 사이즈 별로 반복
            for (int size = last_size; size >= 1; size--)
            {
                // 시작 좌표 (y, x)
                for (int y = 0; y <= MATRIX_SIZE - size; y++)
                {
                    for (int x = 0; x <= MATRIX_SIZE - size; x++)
                    {
                        // 처음 위치복구
                        if (isFirst)
                        {
                            x = last_x;
                            y = last_y;
                            isFirst = false;
                        }

                        isPromising = true;
                        vector<vector<char>> new_matrix(matrix);
                        vector<int> new_used_paper(used_paper);

                        // offset (h, w)
                        for (int h = 0; h < size; h++)
                        {
                            for (int w = 0; w < size; w++)
                            {
                                new_matrix[y + h][x + w]--;

                                if (new_matrix[y + h][x + w] < 0)
                                {
                                    isPromising = false;
                                    break;
                                }
                            }
                            if (isPromising == false)
                                break;
                        }
                        if (isPromising == false)
                            continue;

                        new_used_paper[size - 1]++;
                        backtracking(new_used_paper, new_matrix, size, y, x);
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> matrix(MATRIX_SIZE, vector<char>(MATRIX_SIZE, 0));

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    vector<vector<char>> matrix2(matrix);
    matrix2[0][0] = 9;

    // for (int i = 0; i < MATRIX_SIZE; i++)
    // {
    //     for (int j = 0; j < MATRIX_SIZE; j++)
    //     {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // printf("\n");

    // for (int i = 0; i < MATRIX_SIZE; i++)
    // {
    //     for (int j = 0; j < MATRIX_SIZE; j++)
    //     {
    //         printf("%d ", matrix2[i][j]);
    //     }
    //     printf("\n");
    // }

    vector<int> used_paper(5, 0);

    backtracking(used_paper, matrix, 5, 0, 0);

    printf("%d", -1);

    return 0;
}
