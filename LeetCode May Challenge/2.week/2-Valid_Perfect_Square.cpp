    bool isPerfectSquare(int num) 
    {
        long long x;
        for(long long i = 0; i <= num; i++)
        {
            x = i*i; // For not doing multiplication twice
            if(x == num)
                return true;
            if(x > num)
                return false;
        }
        return false;
    }
