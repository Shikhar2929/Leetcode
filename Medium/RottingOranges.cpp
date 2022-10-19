class Solution {
public:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {1, -1, 0, 0};
    int visited[15][15];
    void dfs(int nodei, int nodej, int depth, vector<vector<int>> grid)
    {
        if(nodei < 0 || nodej < 0 || nodei >= grid.size() || nodej >= grid[0].size())
            return;
        if(grid[nodei][nodej] == 0)
            return;
        if(visited[nodei][nodej] < depth && visited[nodei][nodej] != -1)
            return;
        visited[nodei][nodej] = depth;
        for(int i = 0; i < 4; i++)
                dfs(nodei + x[i], nodej + y[i], depth + 1, grid);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                visited[i][j] = -1;
            }
        }
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                    dfs(i, j, 0, grid);
            }
        int answer = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++)
            { 
                if(grid[i][j] && visited[i][j] == -1)
                    return -1;
                if(grid[i][j])
                    answer = max(visited[i][j], answer);
            }
        }
        return answer;
    }
};
