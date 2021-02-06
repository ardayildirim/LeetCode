class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for (int& i : nums)
            sum += i;
        
        if (sum % 2 == 1)
            return false;
        
        sum /= 2;
        
        vector<bool> dp(sum+1, false);
        
        dp[0] = true;
        for (int& el : nums)
            for (int i = sum; i >= el; i--)
                dp[i] = dp[i] || dp[i-el]; 

        return dp[sum];
    }
};