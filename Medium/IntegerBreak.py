class Solution:
    def integerBreak(self, n: int) -> int:
        answer = 1
        if(n == 2):
            return 1
        if(n == 3):
            return 2
        while n > 4:
            answer *= 3
            n -= 3
        return answer * n
