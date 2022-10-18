class Solution:
    def reverse(self, x: int) -> int:
        flag = 1
        if(x < 0 ): 
            flag = -1
            x *= flag
        x = str(x)
        x = x[::-1]
        x = int(x)
        if(x*flag > (1 << 31) - 1 or x*flag < - (1<<31) ):
            return 0
        return x * flag
