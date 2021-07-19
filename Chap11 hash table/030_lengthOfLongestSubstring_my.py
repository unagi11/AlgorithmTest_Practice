# Success
# Details 
# Runtime: 168 ms, faster than 22.46% of Python3 online submissions for Longest Substring Without Repeating Characters.
# Memory Usage: 14.4 MB, less than 24.23% of Python3 online submissions for Longest Substring Without Repeating Characters.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        if s == "":
            return 0

        left = 0
        right = 1        
        max = 1

        # 오른쪽 기준점이 문자열 개수보다 커지면 종료한다.
        while right != len(s) + 1:
            # 본래 문자열 길이보다 중복없는 문자 개수가 적다면, 한칸 이동한다. (적합한거를 찾는다.)
            if len(set(s[left:right])) < right - left:
                right += 1
                left += 1
            # 중복이 없다면, 맥스를 갱신하고 오른쪽만 늘린다.
            else :
                print(left, right, s[left:right])
                max = right - left
                right += 1
        return max

print(Solution().lengthOfLongestSubstring("pwwkew"))