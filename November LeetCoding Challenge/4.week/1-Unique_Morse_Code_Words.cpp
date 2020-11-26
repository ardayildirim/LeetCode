class Solution {
private:
    string MORS[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        set<string> m;
        for(string s : words)
        {
            string mors = "";
            for(char c : s)
            {
                mors +=  MORS[ (c - 'a') ];
            }
            m.insert(mors);
        }
        return m.size();
        
    }
};