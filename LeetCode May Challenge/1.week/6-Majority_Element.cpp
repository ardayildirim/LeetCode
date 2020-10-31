    int majorityElement(vector<int>& nums) 
    {
        int compare = nums.size() / 2;
        unordered_map<int,int> m;
        for(int i : nums)
            m[i]++;
        
        auto x = m.end();
        for(auto it = m.begin(); it != x; it++)
        {
            if(it -> second > compare) 
                return it -> first;
        }
        return -1;
    }
