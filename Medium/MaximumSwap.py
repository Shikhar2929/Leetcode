class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        for i in range(len(s)):
            curr_max = int(s[i])
            index = 0
            for j in range(len(s) - 1, i, -1):
                if(int(s[j]) > curr_max):
                    curr_max = int(s[j])
                    index = j
            if(index):
                temp = s[index]
                s[index] = s[i]
                s[i] = temp
                return int(''.join(s))
        return num
