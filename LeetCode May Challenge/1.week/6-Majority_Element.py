# C++ solution is O(n) this is O(nlogn) but
# I wanted to share because it is 1 line solution
class Solution(object):
    def majorityElement(self, nums): 
        return sorted(nums)[len(nums) // 2]
