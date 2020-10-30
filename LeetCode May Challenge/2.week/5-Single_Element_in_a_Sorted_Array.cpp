    int singleNonDuplicate(vector<int>& nums) 
    {
        // O(logn) time, O(1) space complexity required
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left < right)
        {
            mid = left - (left-right) / 2;
            if(mid % 2 && nums[mid] == nums[mid-1])
                left = mid+1;
            else if(!(mid % 2) && nums[mid] == nums[mid+1] )
                left = mid + 1;
            else
                right = mid;
            
        }
        return nums[left];
    }
