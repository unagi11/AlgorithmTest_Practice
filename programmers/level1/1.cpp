#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int height = board.size();
    int width = board[0].size();

    deque<int> stack;

    for (int i = 0; i < moves.size(); i++)
    {
        int x = moves[i] - 1;

        for (int y = 0; y < height; y++)
        {
            if (board[y][x] != 0)
            {
                stack.push_back(board[y][x]);

                while (stack.size() > 1 && stack[stack.size() - 1] == stack[stack.size() - 2])
                {
                    answer++;
                    stack.pop_back();
                    stack.pop_back();
                }

                board[y][x] = 0;

                break;
            }
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{

    printf("%d", solution({{0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 3},
                           {0, 2, 5, 0, 1},
                           {4, 2, 4, 4, 2},
                           {3, 5, 1, 3, 1}},
                          {1, 5, 3, 5, 1, 2, 1, 4}));

    return 0;
}
