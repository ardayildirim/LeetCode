    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> v;
        map<char,int> m;
        int start=0;
        int matched = 0;
        for(char x : p){
            m[x]++;
        }
        char right,left;
        int s_len = s.length();
        for(int end =0 ; end<s_len; end++)
        {
            right  = s[end];
            if(m.find(right) != m.end())
            {
                m[right]--;
                if(m[right]==0)
                {
                    matched++;
                }
            }
            if(matched==m.size())
            {
                v.push_back(start);
            }
            if(end>=p.size()-1)
            {
                left = s[start];
                start++;
                if(m.find(left)!=m.end())
                {
                    if(m[left]==0)
                    {
                        matched--;
                    }
                    m[left]++;
                }
            }
            
        }
        return v;
    }
