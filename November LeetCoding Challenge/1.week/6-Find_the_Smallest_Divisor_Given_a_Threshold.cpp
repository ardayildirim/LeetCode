class Solution {
    private:
    long int my_round(long int num, long int divisor)
    {
        if(num % divisor == 0)
            return num/divisor;
        return num/divisor+1;
    }
public:
    //O(n logn) time complexity.
    //O(1) memory complexity
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        long int left = 1;
        int right = *max_element(nums.begin(), nums.end()) + 1;
        long int middle,sum;
        while(left <= right)
        {
            middle = (left + right) / 2;
            sum = 0;
            for(auto i : nums)
            {
                long int k = my_round(i,middle);
              //  cout << i << " " << middle << " " << k << " " << left << " " << right << endl;
                sum += k;
            }
            if(sum > threshold)
            {
                left = middle+1;
            }
            else
            {
                right = middle-1;
            }
            
        }
        return left;
        
    }
};