class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int l = 0;
        int r = 0;
        int maxsum = 0;
        int sum = 0;


        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        while (r < nums.size())
        {

            sum += nums[r];
            maxsum = max(maxsum, sum);


            
                while(sum < 0)
                {
                    sum -= nums[l];
                    l++;
                }

            r++;

        }
        return maxsum;
    }
};
