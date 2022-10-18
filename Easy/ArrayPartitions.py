class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        s = sorted(nums)
        answer = 0
        for i in range(0, len(s), 2):
            answer += s[i]
        return answer
