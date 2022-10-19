class Solution(object):
    def nextPermutation(self, nums):
        for i in range(len(nums) - 2, -1, -1):
            min_value = -1
            min_index = -1
            for j in range(i + 1, len(nums)):
                if(nums[j] > nums[i] and (nums[j] < min_value or min_value == -1)):
                    min_value = nums[j]
                    min_index = j
            if(min_value != -1 and min_index != -1):
                temp = nums[i]
                nums[i] = min_value
                nums[min_index] = temp
                print(nums)
                print(nums[i +1 : ])
                nums[i+1: ] = sorted(nums[i + 1 : ])
                return nums
        nums.sort()
        return nums
