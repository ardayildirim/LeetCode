class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        if(buildings.empty())
            return ans;
        

        set<pair<int,int>> s;
        
        for(vector<int>& v : buildings){

            s.insert({v[0],-v[2]});

            s.insert({v[1],v[2]});
        }
        

        multiset<int> ms;
        ms.insert(0);
        
        for(pair<int,int> p : s)
        {
            int prev = *ms.rbegin();
            
            if(p.second < 0)
                ms.insert(-p.second);
            else
                ms.erase(ms.lower_bound(p.second));
            
            int naw = *ms.rbegin();
            
            if(prev != naw)
                ans.push_back({p.first,naw});
        }
        return ans;
    }
};