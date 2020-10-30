bool canConstruct(string ransomNote, string magazine)
    {
        int ranLen = ransomNote.length();
        int ans = ranLen;
        for(char& c : magazine)
        {
            for(int i = 0; i < ranLen; i++)
            {
                if(c == ransomNote[i])
                {
                    c = '2';
                    ransomNote[i] = '1';
                    ans--;
                    break;
                }
            }
        }
        return !ans;
    }
