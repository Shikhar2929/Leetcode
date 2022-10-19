class Solution {
public:
    int numSquares(int n) {
    vector<int> squares;
    for(int i = 1; i * i <= n; i++){
        squares.push_back(i * i);
    }
    int dp[n + 5];
    dp[0] = 0;
    dp[1] = 1;    
    for(int i = 2; i <= n; i++){
        dp[i] = i;
        for(auto n : squares){
            if(n > i)
                break;
            dp[i] = min(dp[i], dp[i - n] + 1);
        }
    }
    return dp[n];
    }
};
