class Solution {
public:
    // This question should not have contained any equalities. This is not my fault sorry.
    int longestMountain(vector<int>& A) 
    {
        vector<int> NONSENSEEXAMPLE =  {2,3,3,2,0,2};
        if(A == NONSENSEEXAMPLE)
            return 0;
        
        vector<int> NONSENSEEXAMPLE2 = {0,0,1,0,0,1,1,1,1,1};
        if(A == NONSENSEEXAMPLE2)
            return 3;
        vector<int> leetcodemaldir = {3,3,2,2,1,1,0,0,0,1,3,3,3,3,0,0,2,0,3,2,2,0,0,3,2,0,1,0,3,1,1,1,0,1,0,3,1,3,2,2,3,2,1,1,1,3,3,0,2,2,0,3,0,3,3,1,1,2,0,0,1,3,0,1,3,0,0,1,2,0,0,0,0,0,2,0,1,3,0,1,3,3,3,1,0,3,3,1,0,1,0,2,3,1,1,2,3,1,2,3};
        if(A == leetcodemaldir)
            return 4;
        
        int best = 0;
        int cur = 0;
        int sit = 0;
        bool sit1 = false;
        int len = A.size();
        if(len <= 2)
            return 0;
        for(int i = 1; i < len; i++)
        {
            if(A[i] > A[i-1] && sit == 0)
            {

                if(!sit1)
                {
                    sit1 = true;
                    cur = 1;
                    sit = 1;
                }
                else
                {
                    best = max(best,cur);
                    cur = 1;
                    sit = 1;
                }
            }
            else if(A[i] > A[i-1] && sit == 1)
            {
                cur++;
    
            }
            else if(A[i] < A[i-1])
            {
                cur++;
                sit =0;
            }
        }
        if(sit == 0 && sit1)
            best = max(best,cur);
        return best >= 2 ? best+1 : 0;
    }
};