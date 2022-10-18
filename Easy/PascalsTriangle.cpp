// https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        answer.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> temp;
            for(int j = 0; j < answer[i - 1].size(); j++)
            {
                if(j == 0)
                    temp.push_back(1);
                else
                    temp.push_back(answer[i - 1][j] + answer[i - 1][j - 1]);
                    
                
            }
            temp.push_back(1);
            answer.push_back(temp);
        }
        return answer;
    }
};
