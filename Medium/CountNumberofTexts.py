class Solution:
    MOD = 1e9
    def countTexts(self, pressedKeys: str) -> int:
        dp = [0] * (len(pressedKeys) + 5)
        MOD = 1e9 + 7
        dp[0] = 1
        dp[1] = 1
        for i in range(1, len(pressedKeys)):
            if(pressedKeys[i] == pressedKeys[i - 1]):
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD
                if(i > 1 and pressedKeys[i - 1] == pressedKeys[i-2]):
                    dp[i + 1] = (dp[i + 1] + dp[i-2]) % MOD
                    if(i > 2 and (pressedKeys[i] == '7' or pressedKeys[i] == '9') and (pressedKeys[i] == pressedKeys[i - 3])):
                        print("WOrking")
                        dp[i + 1] = (dp[i + 1] + dp[i - 3]) % MOD;
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD
        return int(dp[len(pressedKeys)])
