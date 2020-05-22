class Solution {
    bool all_ones(vector<vector<int>>& matrix,int row, int col, int size)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(matrix[row + i][col + j] == 0)
                    return false;
            }
        }
        return true;
    }
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        int max_sq_size = min(m,n); // maximum size of a square is minimum of n and m
        // for every valid size of squares we loop over matrix
        for(int sq_size = 1; sq_size <= max_sq_size; sq_size++) 
        {
            int loop1 = m-sq_size+1; // this variable is for not doing same operation repeatedly
            for(int i = 0; i < loop1; i++)
            {
                int loop2 = n-sq_size+1; // this variable is for not doing same operation repeatedly
                for(int j = 0; j < loop2; j++)
                {
                    if(all_ones(matrix,i,j,sq_size))
                        ans++;
                }
            }
        }
        return ans;
    }
};
