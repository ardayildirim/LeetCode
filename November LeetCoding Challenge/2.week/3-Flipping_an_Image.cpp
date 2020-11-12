class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& a) 
    {
        int height = a.size();
        int width = a[0].size();
        
        vector<int> temp(width,0);
        vector<vector<int>> ans(height, temp );
        
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                ans[i][height-1-j] = 1 - a[i][j];
            }
        }
        return ans;
        
    }
};

