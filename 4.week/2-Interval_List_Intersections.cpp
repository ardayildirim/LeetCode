class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> v;
        int i=0,j=0;
        
        int k,ii;
        
        while(i<A.size() && j<B.size()){
            k = max(A[i][0], B[j][0]);
            ii = min(A[i][1], B[j][1]);
            if(k<=ii) 
                v.push_back({k,ii});
            if(A[i][1] < B[j][1])
                i++;
            else 
                j++;
        }
        return v;
    }
};
