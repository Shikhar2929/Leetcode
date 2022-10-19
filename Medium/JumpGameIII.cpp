class Solution {
public:
    int a[100001];
        
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        while(q.size())
        {
            int t = q.front();
            q.pop();
            if(arr[t] == 0)
                return true;
            if(t + arr[t] < arr.size() && a[t + arr[t]] == 0)
            {    a[t + arr[t]] = 1;
                 q.push(t + arr[t]);
            }
            if(t - arr[t] >= 0 && a[t - arr[t]] == 0)
            {
                a[t - arr[t]] = 1;
                q.push(t - arr[t]);
            }
        }
        return false;
        
    }
};
