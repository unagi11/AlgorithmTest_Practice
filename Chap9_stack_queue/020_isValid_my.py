# Success
# Details 
# Runtime: 28 ms, faster than 85.74% of Python3 online submissions for Valid Parentheses.
# Memory Usage: 14.3 MB, less than 63.34% of Python3 online submissions for Valid Parentheses.

class Solution:
    def isValid(self, s: str) -> bool:
        _list = list(s)
        _stack = []

        for c in _list:
            # print(c, _stack)
            if c is '(' or c is '{' or c is '[':
                _stack.append(c)
            else:
                if len(_stack) is 0:
                    return False
                pop = _stack.pop()
                if c is ')' and pop is '(':
                    continue
                elif c is '}' and pop is '{':
                    continue
                elif c is ']' and pop is '[':
                    continue
                else:
                    return False

        if len(_stack) is 0:
            return True
        else:
            return False

print(Solution().isValid("(){}[]"))