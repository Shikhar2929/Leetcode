class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        answer = int(''.join(str(i) for i in digits)) + 1
        return list(str(answer))
