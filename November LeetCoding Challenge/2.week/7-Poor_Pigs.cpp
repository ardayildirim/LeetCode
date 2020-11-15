class Solution {
public:
    int poorPigs(int n, int m, int p) 
    {
        int x = 0;
        int k = p/m;
        while( pow(k+1,x) < n )
            x++;
        return x;
    }
};