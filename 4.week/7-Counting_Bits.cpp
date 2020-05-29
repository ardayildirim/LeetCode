class Solution {
    int number_of_1s(unsigned int i)
    {
        int ans = 0;
        while(i)
        {
            ans += i%2;
            i /= 2;
        }
        return ans;
    }
public:
    vector<int> countBits(int num) 
    {
        vector<int> v;
        for(unsigned int i = 0; i <= num; i++)
            v.push_back(number_of_1s(i));
        return v;
    }
};
