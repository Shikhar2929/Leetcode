class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";
        for(int i = 0; i < strs[0].size(); i++)
        {
            char curr_character = strs[0][i];
            int flag = 0;
            for(auto n: strs)
            {
                if(i < n.size() && n[i] == curr_character)
                    continue;
                flag = 1;
                break;
            }
            if(flag)
                break;
            answer += curr_character;
        }
        return answer;
    }
};
