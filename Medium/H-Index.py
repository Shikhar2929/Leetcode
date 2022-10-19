class Solution:
    def hIndex(self, citations: List[int]) -> int:
        c = sorted(citations)
        for i in range(len(c), 0, -1):
            print(i)
            if(i == len(c)):
                if(c[0] >= i):
                    return i
                continue
            if(c[len(c) - i] >= i and c[len(c) - i - 1] <= i):
                return i
        return 0    
        
