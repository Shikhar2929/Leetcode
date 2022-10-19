class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        queue<int> active;
        for(int i = 1; i < s.length(); i++)
            if(s[i] == '0')
                active.push(i);
            
        q.push(0);
        while(q.size())
        {
            int temp = q.front(); q.pop();
            if(temp == s.length() - 1)
                return true;
            while(active.size())
            {
                int n = active.front();
                if(temp + minJump <= n && temp + maxJump >= n)
                {    q.push(n);
                     active.pop();
                }
                if(temp + minJump > n)
                    active.pop();
                if(temp + maxJump < n)
                    break;
            }
        }
        return false;
    }
};
