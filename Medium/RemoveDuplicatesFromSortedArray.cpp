class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length <= 1)
            return nums.length;
        int p1 = 1;
        int p2 = 1; 
        int nump2 = 1;
        while(p2 < nums.length) {
            if(p2 > 0 && nums[p2] == nums[p2 - 1])
                nump2++;
            else
                nump2 = 1;
            if(nump2 <= 2)
            {
                nums[p1] = nums[p2];
                p1++;
                p2++;
            }
            else
                p2++;
        }
        return p1;
    }
}
