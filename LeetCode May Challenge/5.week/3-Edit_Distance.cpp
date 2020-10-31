class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int len1 = word1.length(),len2 = word2.length();
        if(len1 == 0 && len2 == 0)
            return 0;
        vector<int> v(len2+1,0);
        vector<vector<int>> dp(len1+1,v);
        int i,j;
        for(i = 0; i <= len1; i++)
            dp[i][0] = i;
        for(i = 0; i <= len2; i++)
            dp[0][i] = i;
        
        for(i = 1; i <= len1; i++)
        {
            for(j = 1; j <= len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
