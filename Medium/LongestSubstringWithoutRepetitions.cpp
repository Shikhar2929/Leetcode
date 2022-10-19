class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int p1 = 0; int p2 = 1;
        if(s.size() == 0)
            return 0;
        int maxL = p2 - p1;
        m.insert({s[0], 1});
        while(p2 < s.size())
        {
            if(m.find(s[p2]) == m.end())
            {
                maxL = max(maxL, p2 - p1 + 1);
                m.insert({s[p2], 1});
                p2++;
            }
            else{
                m.erase(s[p1]);
                p1++;
            }
        }
        return maxL;
    }
};
