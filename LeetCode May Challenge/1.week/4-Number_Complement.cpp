int findComplement(int num) 
    {
        vector<int> v(31,0);
        int i = 0;
        int current = 0;
        int k; // variable for not doing 1 << (30-i) twice
        // Generating binary number for num
        while(i < 31)
        {
            k = 1 << (30-i);
            v[i] = current + k <= num ? current += k,1 : 0;
            i++;
        }

        // Finding first 1's index so we can ignore leading zero's
        int firstnonzero = 0;
        for(i = 0; i < 31; i++)
        {
            if(v[i] != 0)
            {
                firstnonzero = i;
                break;
            }
        }
    
        // Finding answer by treating zero's as one's
        int ans = 0;
        for(i = 30; i >= firstnonzero; i--)
        {
            if(v[i] == 0)
            {
                ans += 1 << (30-i);
            }
        }
        return ans;
    }
