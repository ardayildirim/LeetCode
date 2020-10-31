#define dist(x,y) (x*x + y*y) 
//since we do not need exact distance values and we just need to compare, we don't need to sqrt.
class Solution {

public:
    // O(n) space and O(n logn) time due to sorting
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        int len = points.size();
        vector<pair<int,int>> v(len);
        for(int i = 0; i < len; i++)
        {
            v[i] = {dist(points[i][0],points[i][1]) ,i};
        }
        sort(v.begin(), v.end(), [](auto &l, auto &r) 
             {
                return l.first < r.first;
            });
        vector<vector<int>> ans(K);
        for(int i = 0; i < K; i++)
        {
            ans[i] = points[v[i].second];
        }
        return ans;
        
        
        
    }
};
