class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        backtrack(ans, 0, nums);   
        
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, int level, vector<int>& nums){
        
        if(level == nums.size() -1){
            ans.push_back(nums);
            return ;
        }
        for(int i = level; i < nums.size(); ++i){
            swap(nums[i], nums[level]); 
            backtrack(ans, level+1, nums);
            swap(nums[level], nums[i]);  //reset state
        }
        
    }
};