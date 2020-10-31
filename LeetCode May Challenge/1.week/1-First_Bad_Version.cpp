// bool isBadVersion(int version);

int firstBadVersion(int n) // Just Binary Search
    {
        int left = 1, right = n;
        int middle;
        int best;
        while(left <= right)
        {
            middle = left + ((right - left) / 2); // This is better for binary search because
            if(isBadVersion(middle))              //  if you do (left+right) / 2 it might cause an integer overflow
            {
                best = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return best;
    }
