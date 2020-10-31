    int maxSubarraySumCircular(vector<int>& A) 
    {
        int len = A.size();
        if(!len)
            return 0;
        int j = 0,k = 0;
        int maxArr,minArr;
        int total = 0;
        maxArr = minArr = A[0];
        for(int i = 0; i < len; i++)
        {
            total += A[i];
            j = A[i] + max(0,j);
            k = A[i] + min(0,k);
            maxArr = max(j,maxArr);
            minArr = min(k,minArr);
        }
        return maxArr > 0 ? max(maxArr,total-minArr) : maxArr;
    }
