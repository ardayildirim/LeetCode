class Solution 
{
    void kole(vector<int> v, vector<vector<int>> &ans)
    {
        int i = 0;
        int len = ans.size();
        while(true)
        {

            if(i == len)
            {
                ans.push_back(v);
            }
            if(ans[i][1]>= v[0])
            {
                ans[i][1] = max(ans[i][1],v[1]);
                return;
            }
            i++;
        }
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto v : intervals)
        {
            kole(v,ans);
        }
        return ans;
    }
};