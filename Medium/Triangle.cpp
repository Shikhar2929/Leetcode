class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int answer = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < i + 1; j++) {
                if (j == 0) 
                    triangle[i][j] += triangle[i - 1][0];
                else if(j == i)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                if(i == triangle.size() - 1) {
                    if(j == 0)
                        answer = triangle[i][j];
                    else
                        answer = min(answer, triangle[i][j]);
                }
            }
        }
        return answer;
    }
};
