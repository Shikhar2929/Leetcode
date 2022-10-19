class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr_min = prices[0]
        curr_max = prices[0]
        answer = 0
        for p in prices:
            if p < curr_min:
                answer += curr_max - curr_min
                curr_min = p
                curr_max = p
            elif p > curr_max:
                curr_max = p
            elif p >= curr_min and p < curr_max:
                answer += (curr_max - curr_min)
                curr_min = p
                curr_max = p
        answer += (curr_max - curr_min)
        return answer
                    
