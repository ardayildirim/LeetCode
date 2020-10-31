int numJewelsInStones(string J, string S) 
    {
        int ans = 0;
        char *p = &S[0];
        for(char c : J) // For every character in J we count the number of occurences in S
        {
            for(p = &S[0];*p;p++)
            {
                if(c == *p) ans++;
            }
        }
        return ans;
    }
