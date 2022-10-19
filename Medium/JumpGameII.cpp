class Solution {
public:
    int arr[10001];
    struct node{
        int position; 
        int node;
        int nums;
    };
    
    int jump(vector<int>& nums) {
        queue<node> q;
        q.push({0, 0, nums[0]});
        while(q.size())
        {
            node t = q.front();
            q.pop(); 
            if(t.node > arr[t.position])
                continue;
            for(int i = t.position + 1; i <= t.position + t.nums && i < nums.size(); i++)
            {
                if(arr[i] > t.node + 1 || arr[i] == 0)
                {
                    arr[i] = t.node + 1;
                    q.push({i, arr[i], nums[i]});
                }
            }
        }
        return arr[nums.size() - 1];
    }
    
};
