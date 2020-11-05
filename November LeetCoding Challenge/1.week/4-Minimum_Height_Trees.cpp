class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if(n==1) 
            return {0};
        if(n==2) 
            return {1,0};
        
        vector<int> map[n];
        vector<int> used(n,0);
        for(auto i:edges)
        {
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
            used[i[0]]++;
            used[i[1]]++;
        }
        queue<int> q;
        
        for(int i=0;i<n;i++)
            if(used[i]==1) 
                q.push(i);
        
        while(n>2)
        {
            int s=q.size();
            while(s--)
            {
                n--;
                int p=q.front();
                q.pop();
                used[p]--;
                for(int i:map[p])
                {
                    used[i]-=1;
                    if(used[i]==1) 
                        q.push(i);
                }
            }
            
        }
        vector<int> res;
        while(q.empty() == false)
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};