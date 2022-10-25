class Solution {
public:
    int visited[205][205];
    vector<vector<int>> mat;
    int dfs(int i, int j) {
        if (visited[i][j])
            return visited[i][j];
        int answer = 1;
        visited[i][j] = 1;
        if (i + 1 < mat.size() && mat[i + 1][j] > mat[i][j])
            answer = max(answer, 1 + dfs(i + 1, j));
        if (j + 1 < mat[0].size() && mat[i][j + 1] > mat[i][j])
            answer = max(answer, 1 + dfs(i, j + 1));
        if (i > 0 && mat[i - 1][j] > mat[i][j])
            answer = max(answer, 1 + dfs(i - 1, j));
        if (j > 0 && mat[i][j - 1] > mat[i][j])
            answer = max(answer, 1 + dfs(i, j - 1));
        visited[i][j] = answer;
        return answer;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<pair<int, int>> local_mins;
        int answer = 0;
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> temp;
            for(int j = 0; j < matrix[0].size(); j++) {
               temp.push_back(matrix[i][j]);
            }
            mat.push_back(temp);
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                answer = max(answer, dfs(i, j));
            }
        }
        return answer;
    }
};
