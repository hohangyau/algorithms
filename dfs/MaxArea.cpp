class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; 
        int i, j;
        for (i = 0; i < grid.size(); ++i){
            for(j = 0; j<grid[i].size(); ++j){
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
                
            }
        }
        
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int row, int col){
       
        
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] == 0) return 0;
        
            int count = 1;
            grid[row][col] = 0; //prevent dupicate count
            count += dfs(grid, row - 1, col); //up
            count += dfs(grid, row + 1, col); //down
            count += dfs(grid, row, col - 1); //left
            count += dfs(grid, row, col + 1); //right
            return count;
        
    }
    
};