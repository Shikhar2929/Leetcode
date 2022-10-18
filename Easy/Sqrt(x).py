def binaryS(low, high, target):
    mid = int((low + high)/2)
    if(low == high):
        return low
    if((low + 1) == high):
        if high * high <= target:
            return high
        else:
            return low
    if (mid * mid > target):
        return binaryS(low, mid - 1, target)
    if(mid * mid == target):
        return mid
    else:
        return binaryS(mid, high, target)
class Solution: 
    def mySqrt(self, x: int) -> int:
        #find squareroot of number without using exponent, power, etc. 
        return binaryS(1, x, x)
    
