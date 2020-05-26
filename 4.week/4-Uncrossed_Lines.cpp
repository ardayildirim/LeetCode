    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lena = A.size(),lenb = B.size();
        int dp[lena+1][lenb+1];
        int i,j;
        for(i = 0; i <= lena; i++)
            dp[i][0] = 0;
        
        for(i = 0; i <= lenb; i++)
            dp[0][i] = 0;
        
        for(i = 1; i <= lena; i++)
            for(j = 1; j <= lenb; j++)
                dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1] + (A[i-1] == B[j-1])});
        return dp[lena][lenb];
        
    }
