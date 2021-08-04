# Success
# Details 
# Runtime: 32 ms, faster than 65.15% of Python3 online submissions for Jewels and Stones.
# Memory Usage: 14.1 MB, less than 73.31% of Python3 online submissions for Jewels and Stones.

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:

        dic = {}

        for c in stones:
            dic.setdefault(c, 0)
            dic[c] += 1

        num = 0
        
        for c in jewels:
            dic.setdefault(c, 0)
            num += dic[c]

        return num

print(Solution().numJewelsInStones("aA", "aAAbbbb"))