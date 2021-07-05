from typing import List


class Solution:
    @staticmethod
    def groupAnagrams(strs: List[str]) -> List[List[str]]:
        print(strs)
        _dict = {}
        for str in strs:
            _sorted = "".join(sorted(str))
            if _sorted not in _dict:
                _dict[_sorted] = []
            _dict[_sorted].append(str)

        return list(dict.values(_dict))


_input = ["eat", "tea", "tan", "ate", "nat", "bat"]
_output = Solution().groupAnagrams(_input)

print(_output)
