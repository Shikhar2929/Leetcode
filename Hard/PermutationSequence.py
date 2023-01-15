class Solution:
    def calculate(self, n, k, nums):
        print(nums)
        if (len(nums) == 1):
            return str(nums[0])
        f = [0] * (n + 1)
        f[0] = 1
        for i in range(1, n + 1):
            f[i] = i * f[i - 1]
        a = (k - 1) // f[n - 1]
        s = str(nums.pop(a))
        return s + self.calculate(n - 1, k % f[n - 1], nums)
    def getPermutation(self, n: int, k: int) -> str:
        return self.calculate(n, k, list(range(1, n + 1)))
