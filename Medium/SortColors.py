class Solution:
    def sortColors(self, nums: List[int]) -> None:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if(nums[i] > nums[j]):
                    t = nums[i]
                    nums[i] = nums[j]
                    nums[j] = t
        return nums
