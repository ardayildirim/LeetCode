class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int len = nums.size();
        if(!len)
            return 0;
        // O(n) space and time
        unordered_map<int,int> first,last;
        vector<int> v(len+1,0);
        int x;
        v[0] = 0;
        for(int i = 1; i <= len; i++)
        {
            x = nums[i-1];
            v[i] = v[i-1] + (2*x-1); // 2*x-1 will give us f(0) -> -1, f(1) -> 1
        }
        
        for(int i = 0; i <= len; i++)
        {
            
            x = v[i];
            if(!first[x])
                first[x] = i+1;
            else
                last[x] = i+1;
        }
        
        
        x = 0;
        for(auto it = last.begin(); it != last.end(); it++)
        {
            if(it-> second - first[it->first] > x)
                x = it-> second - first[it->first];
        }
        return x;
    }
};
