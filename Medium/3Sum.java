import java.util.Arrays;
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> A = new ArrayList<>();
        Arrays.sort(nums);
        int N = nums.length;
        for(int i=0;i<N-2;i++)
        {
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            int j = i+1;
            int k = N-1;
            while(j != k){
            if(nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if (nums[i] + nums[j] + nums[k] > 0)
                k--;
            else {
                A.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k])));
                int og = nums[k];
                while(nums[k] == og && k != j)
                    k--;
            }
            }
        }
        return A;
        
    }
}
