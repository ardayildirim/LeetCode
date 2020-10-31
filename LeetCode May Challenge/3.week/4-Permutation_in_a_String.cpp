class Solution {
    bool all_zero(unordered_map<char,int> m)
    {
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it -> second)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) 
    {
        int m = s1.length();
        int n = s2.length();
        if(m > n)
            return false;
        
        unordered_map<char,int> map;
        for(int i = 0; i < m; i++)
        {
            map[s1[i]]--;
            map[s2[i]]++;
        }
        for(int i = m; i < n;i++)
        {
            if(all_zero(map))
                return true;
            map[s2[i]]++;
            map[s2[i-m]]--;
        }
        return all_zero(map);
          
        
    }
};
