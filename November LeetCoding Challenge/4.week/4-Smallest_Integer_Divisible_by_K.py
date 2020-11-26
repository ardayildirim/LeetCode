class Solution(object):
    def smallestRepunitDivByK(self, k):
        n = 1

        
        if k % 2 == 0 or k % 5 == 0:
            return -1
        while(True):
            res = n % k
            if res == 0:
                return len(str(n))
            n = 10 * n + 1