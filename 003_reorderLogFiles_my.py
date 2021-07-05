from typing import List


class Solution:
    @staticmethod
    def reorderLogFiles(logs: List[str]) -> List[str]:
        dig_list = list()
        let_list = list()

        for log in logs:
            _list = log.split()
            indicator = _list[0]
            _len = len(_list[0]) + 1
            if log[_len:_len + 1].isdigit():
                dig_list.append(log)
            elif log[_len:_len + 1].isalpha():
                let_list.append(log)

        let_list.sort(key=lambda x: (x[len(x.split()[0]) + 1:], x.split()[0]))

        return let_list + dig_list

# 1. 로그의 가장 앞 부분은 식별자다.
# 2. 문자로 구서오딘 로그가 숫자 로그보다 앞에 온다.
# 3. 식별자는 순서에 영향을 끼치지 않지만, 문자가 동일할 경우 식별자 순으로 한다.
# 4. 숫자 로그는 입력 순서대로 한다.

logs1 = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]

_output = Solution().reorderLogFiles(logs1)
print(_output)
# Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

logs2 = ["a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"]
_output = Solution().reorderLogFiles(logs2)
print(_output)
# Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
