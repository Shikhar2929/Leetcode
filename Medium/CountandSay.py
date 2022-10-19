class Solution:
    def countAndSay(self, n: int) -> str:
        if(n == 1):
            return "1"
        if(n == 2):
            return "11"
        s = self.countAndSay(n - 1)
        answer = ""
        prev = s[0]
        cnt = 1
        for i in range(1, len(s)):
            if s[i] == prev:
                cnt += 1
            else:
                answer += str(cnt) + str(prev)
                cnt = 1
            prev = s[i]
        answer += str(cnt) + str(prev)
        return answer
