class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0;
        int len = nums.size();
        vector<int> res;
        while(i < len)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            while(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            dq.push_back(i++);
            
            if(i >= k)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};