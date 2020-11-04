class Solution {
public:
    // O(n) time complexity
    // O(1) memory complexity
    int maxPower(string s) 
    {
        int len = s.length();
        int cur = 1;
        int best = 1;
        for(int i = 1; i < len; i++)
        {
            if(s[i] == s[i-1])
                cur++;
            else
                cur = 1;
            best = max(best,cur);
        }
        return best;
    }
};