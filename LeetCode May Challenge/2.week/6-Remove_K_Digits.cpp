    string removeKdigits(string num, int k) 
    {
        if(num.length() == k)
            return "0";
        int del = k;
        int ind;
        string ans = num;
        int i,j;
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < ans.length() - 1; j++)
			{
				if (ans[j] > ans[j + 1])  
				{
					ans.erase(j, 1);   
					del--;          
					break;
				}
			}
		}
		if (del >= 1)  
		{
            ind = ans.size()-del;
			ans.erase(ind,del);
		}
        ans.erase(0, ans.find_first_not_of('0'));          
		return ans.length() == 0 ? "0" : ans;
    }
