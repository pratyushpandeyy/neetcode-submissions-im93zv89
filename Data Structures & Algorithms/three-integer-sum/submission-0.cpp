class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue; // why?
            int j = i + 1; //why? as in after the first iteration of while loop ends and i gets incremented, why j the very next element when it could be the same as i also in case of duplicates? is the if loop inside the while loop to cater to that problem so that it directly jumps to the next i?
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else 
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++; //is this done first before rather than directly incrementing based on the while loop because int he first iteration j does not have a prev element and k does not have a next eleemnt?
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }


        }
        return ans;
        
    }
};
