class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int> m;
        for(char c : s)
        {
            if(m.find(c) == m.end())
                m.insert({c, 1});
            else
                return c;
        }
        return NULL;
    }
};
