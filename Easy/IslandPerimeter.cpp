// https://leetcode.com/problems/island-perimeter/
class Solution {
public:
    int visited[105][105];
    int floodfill(vector<vector<int>>& grid, int i, int j)
    {
        if(visited[i][j])
            return 0;
        visited[i][j] = 1;
        int answer = 4;
        if(i > 0 && grid[i-1][j] == 1)
            answer += floodfill(grid, i-1, j) - 1;
        if(i < grid.size() - 1 && grid[i + 1][j] == 1)
            answer += floodfill(grid, i + 1, j) - 1;
        if(j > 0 && grid[i][j - 1] == 1)
            answer += floodfill(grid, i, j - 1) - 1;
        if(j < grid[0].size() - 1 && grid[i][j + 1] == 1)
            answer += floodfill(grid, i, j + 1) - 1;
        return answer;
    }
    void setup(int sizei, int sizej)
    {
        for(int i = 0; i < sizei; i++)
            for(int j = 0; j < sizej; j++)
                visited[i][j] = 0;           
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        setup(grid.size(), grid[0].size());
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    return floodfill(grid, i, j);
            }
        
        }
        return -1;
    }

};
