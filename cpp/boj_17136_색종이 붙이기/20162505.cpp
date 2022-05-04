#include <cstdio>
#include <algorithm>
#include <vector>

#define MATRIX_SIZE 10 // 매트릭스 사이즈는 10 * 10 이다.
#define KINDS_PAPER 5  // 사용가능한 종이 종류는 5 가지이다.

using namespace std;

int answer = 26;             // 최적의 답 기록용
vector<vector<char>> matrix; // 행렬상태를 기록한다.
vector<int> papers;          // 사용가능한 종이 카운트

bool promising(int last_y, int last_x, int left_1)
{
    // 남은 1의 개수가 음수인가?
    if (left_1 < 0)
        return false;

    // 같은 위치를 뺀곳이 있는가?
    for (int y = 0; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            if (matrix[y][x] < 0)
                return false;

    // 종이를 초과해서 쓴게 있는가?
    for (int i = 0; i < KINDS_PAPER; i++)
        if (papers[i] < 0)
            return false;

    // 위의 사항을 만족하면 유망하다.
    return true;
}

void backTracking(int last_y, int last_x, int left_1)
{
    if (promising(last_y, last_x, left_1))
    {
        if (left_1 == 0)
        {
            int sum = 0;
            for (int i = 0; i < KINDS_PAPER; i++)
                sum += 5 - papers[i];

            answer = answer > sum ? sum : answer;
        }
        else
        {
            // 새로 채울 종이의 위치를 찾는다.
            int new_y = last_y;
            int new_x = last_x;

            while (1)
            {
                new_x++;

                if (new_x == MATRIX_SIZE)
                {
                    new_x = 0;
                    new_y++;
                }

                if (matrix[new_y][new_x] == 1)
                    break;
            }

            // 종이 크기를 줄이면서 겹쳐본다.
            for (int size = KINDS_PAPER; size >= 1; size--)
            {
                if (new_x + size - 1 < MATRIX_SIZE && new_y + size - 1 < MATRIX_SIZE)
                {
                    papers[size - 1]--;
                    left_1 -= size * size;
                    for (int y = 0; y < size; y++)
                        for (int x = 0; x < size; x++)
                            matrix[new_y + y][new_x + x]--;

                    backTracking(new_y, new_x, left_1);

                    papers[size - 1]++;
                    left_1 += size * size;
                    for (int y = 0; y < size; y++)
                        for (int x = 0; x < size; x++)
                            matrix[new_y + y][new_x + x]++;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    matrix = vector<vector<char>>(MATRIX_SIZE, vector<char>(MATRIX_SIZE));
    papers = vector<int>(KINDS_PAPER, 5);

    int count_1 = 0;

    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1)
                count_1++;
        }

    backTracking(0, -1, count_1);

    if (answer == 26)
        printf("-1");
    else
        printf("%d", answer);

    return 0;
}