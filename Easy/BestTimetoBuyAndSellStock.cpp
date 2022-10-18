// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr_min = prices[0]
        curr_max = prices[0]
        profit = 0
        for price in prices:
            if(price < curr_min):
                curr_min = price
                curr_max = price 
            curr_max = max(price, curr_max)
            profit = max(curr_max - curr_min, profit)
        return profit
        
