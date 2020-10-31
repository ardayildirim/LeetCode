class Trie {
public:
    vector<string> v;
    unordered_map<string,int> m;
    Trie() {

    }
    
    void insert(string word) {
        v.push_back(word);
        m[word]++;
    }
    
    bool search(string word) {
        return m[word];
    }
    
    bool start(string s, string prefix) {
    int len = prefix.length();
    if(s.length() < len)
        return false;
    for(char *pp = &prefix[0],*sp = &s[0]; *pp; pp++,sp++)
        if(*pp != *sp)
            return false;
        
    return true;
        }
    
    bool startsWith(string prefix) {
        if(v.empty())
            return false;
        
        for(string s : v)
        {
            if(start(s,prefix))
                return true;
        }
        return false;
    }
};
