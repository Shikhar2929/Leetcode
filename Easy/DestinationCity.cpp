class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> m;
        for(auto n : paths)
        {
            string s1 = n[0];
            string s2 = n[1];
            m.insert({s1, s2});
        }
        string s1 = paths[0][0];
        while(m.find(s1) != m.end())
            s1 = m[s1];
        return s1;
    }
};
