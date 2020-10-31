class Solution(object):
    def numJewelsInStones(self, J, S):
        ans = 0
        for jewel in J:
            ans += S.count(jewel)
        return ans
