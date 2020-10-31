    int findJudge(int N, vector<vector<int>>& trust) 
    {
        if(trust.empty())
            return 1;
        unordered_map<int,int> trusting;
        unordered_map<int,int> being_trusted;
        for(auto v : trust)
        {
            trusting[v[0]]++;
            being_trusted[v[1]]++;
        }
        for(auto it = being_trusted.begin() ; it != being_trusted.end(); it++)
        {
            if( (it-> second) == (N-1) && (trusting[it->first]) == 0)
                return it -> first;
        }
        return -1;
    }
