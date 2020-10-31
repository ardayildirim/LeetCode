class Solution 
{
    int width;
    int height;
    int oldColor;
    void dfs(vector<vector<int>>& v, int row, int col, int newColor)
    {
        if(row < 0 || row >= height || col < 0 || col >= width)
        {
            // we got outside of the grid, return
            return;
        }
        if(v[row][col] == oldColor)
        {
            v[row][col] = newColor;
            dfs(v,row+1,col,newColor);
            dfs(v,row-1,col,newColor);
            dfs(v,row,col+1,newColor);
            dfs(v,row,col-1,newColor);
        }
        return; // image[row][col] != oldColor
            
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        width = image[0].size();
        height = image.size();
        oldColor = image[sr][sc];
        if(newColor == oldColor)
            return image;
        dfs(image,sr,sc,newColor);
        return image;
    }
};
