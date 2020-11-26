class Solution:
    def atMostNGivenDigitSet(self, D, n):
        
        digitsInN = len(str(n)) 
        

        ans = 0
        
        lend = len(D)
        i = 1
        while i <  digitsInN:
            ans += lend**i
            i += 1
        

        arr = []
        for col in list(str(n)):
            temp = 0
            flag = 0
            for row in D:
                if int(row)<int(col): 
                    temp += 1
                if int(row)==int(col): 
                    flag = 1
            arr.append((temp,flag))
        

        flag = 1
        i = 0
        while flag and i<digitsInN:
            temp, flag = arr[i]
            ans += (temp)*(len(D)**(digitsInN-i-1))
            i += 1
        if flag: ans += 1
        
        return ans  