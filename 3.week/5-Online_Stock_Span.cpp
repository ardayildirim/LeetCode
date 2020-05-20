// idea behind this solution is if we store only all the prices
// and loop back every time to find the answer it takes too long.
// instead we are keeping pairs {price_i ,ans_i} and if a price_j
// is greater than a price_i than it is automatically greater than previous ans_i numbers
class StockSpanner 
{
public:
    vector<pair<int,int>> v; 
    int ind = -1;
    StockSpanner() 
    {
        v.clear();
        ind = -1;
    }
    int next(int price) 
    {
        if(ind == -1)
        {
            ind = 0;
            v.push_back({price,1});
            return 1;
        }
        int i=ind,ans = 1;
        while(i >=0 && v[i].first <= price)
        {
            ans += v[i].second;
            i -= v[i].second;
        }
        ind++;
        v.push_back({price,ans});
        
        return ans;
    }
};
