class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count ++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col){
        
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] == '0') return;
    
        grid[row][col] = '0'; //prevent douplicate count
        
        auto up = make_pair(row - 1, col);
        auto down = make_pair(row + 1, col);
        auto left = make_pair(row, col - 1);
        auto right = make_pair(row, col + 1);
        
        dfs(grid, up.first, up.second);
        dfs(grid, down.first, down.second);
        dfs(grid, left.first, left.second);
        dfs(grid, right.first, right.second);
        
    }
};