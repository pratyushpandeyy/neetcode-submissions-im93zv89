class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int high = nums.size()-1;
        int low = 0;
        int ans = INT_MAX;


        while (low <= high)
        {
            int mid = low + (high - low)/2;

            if (nums[low] <= nums[mid]) //important reasoning behind equals to coniditon -- we want the condiiton of low = mid also as valid for the left half
            {
                ans = min(ans, nums[low]); // whenever searching for min max, always update 
                low = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;

    }
};
