class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i <= amount; ++i){
            iterateCoins(coins, dp, i);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    void iterateCoins(vector<int>& coins, vector<int>& dp, int i){
         for(auto coin : coins){
            if(i >= coin) {
				dp[i] = min(dp[i], 1 + dp[i - coin]);
            }else break;
                
            }
    }
};