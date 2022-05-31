#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> student;
int answer = 0;

// 현재 체육복 상황, n번째 학생 인덱스, 현재 빌려준
void dfs(vector<int> cur_student, int n)
{
    if (n == cur_student.size())
    {
        int temp = 0;
        for (int i = 0; i < cur_student.size(); i++)
            if (cur_student[i] >= 0)
                temp++;
        answer = max(answer, temp);
        return;
    }

    // 왼쪽 빌려줌
    if (n > 0 && cur_student[n - 1] < 0 && cur_student[n] > 0)
    {
        cur_student[n - 1]++;
        cur_student[n]--;
        dfs(cur_student, n + 1);
        cur_student[n - 1]--;
        cur_student[n]++;
    }

    // 오른쪽 빌려줌
    if (n < cur_student.size() - 1 && cur_student[n + 1] < 0 && cur_student[n] > 0)
    {
        cur_student[n]--;
        cur_student[n + 1]++;
        dfs(cur_student, n + 1);
        cur_student[n]++;
        cur_student[n + 1]--;
    }

    // 빌려주지 않음
    dfs(cur_student, n + 1);
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
    student = vector<int>(n, 0);

    for (int i = 0; i < lost.size(); i++)
        student[lost[i] - 1]--;

    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i] - 1]++;

    dfs(student, 0);

    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution(3, {3}, {1});
}