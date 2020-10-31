#define F(x) (x->first)
#define S(x) (x->second)
#define INF 1000000000
class Solution {
    pair<char,int> find_min(map<char,int>& m)
    {
        int min= INF;
        char c;
        for(auto it= m.rbegin(); it != m.rend(); it++)
            if(S(it) <min)
            {
                min = S(it);
                c = F(it);
            }
        m[c] = INF;
        return {c,min};
    }
public:
    string frequencySort(string s) 
    {
        int len = s.length();
        char ans[400000];
        int k = len-1;
        pair<char,int> current;
        
        map<char,int> map;
        for(char c : s)
            map[c]++;
        
        ans[len] = 0;
        while(k >= 0)
        {
            if(current.second == 0)
                current = find_min(map);
            ans[k] = current.first;
            k--;
            (current.second)--;
        }
        return ans;
    }
};
