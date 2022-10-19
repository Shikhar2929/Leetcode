class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> active;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                    active.push_back(make_pair(i, j));   
                
            }
        }
        for(auto n : active){
            for(int k = 0; k < matrix[0].size(); k++)
                matrix[n.first][k] = 0;
            for(int k = 0; k < matrix.size(); k++)
                matrix[k][n.second] = 0;
        }
    }
};
