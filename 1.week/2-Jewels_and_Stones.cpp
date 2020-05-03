int numJewelsInStones(string J, string S) 
    {
        int ans = 0;
        char *p = &S[0];
        for(char c : J)
        {
            
            for(p = &S[0];*p;p++)
            {
                if(c == *p) ans++;
            }
        }
        return ans;
    }
