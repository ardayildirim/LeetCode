class Solution {
public:
    bool search(vector<int>& v, int target) 
    {
        for(auto i : v)
            if(i == target)
                return true;
        return false;
    }
};