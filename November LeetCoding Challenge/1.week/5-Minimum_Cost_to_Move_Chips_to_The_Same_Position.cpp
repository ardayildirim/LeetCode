class Solution {
public:
    int minCostToMoveChips(vector<int>& position) 
    {
        int odd = 0, even = 0;
        for(int i : position)
        {
            if(i & 1) // returns 1 if i is odd.  -> (i % 2 == 1)
                odd++;
            else
                even++;
        }
        return min(odd,even);
        
    }
};