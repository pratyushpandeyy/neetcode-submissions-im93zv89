// class Solution {
// public:
//     bool canJump(vector<int>& nums) 
//     {

//         int n = nums.size() - 1;
//         int index = 0;
//         int i = 0;

//         while(i <= n)
//         {
//             index = i;
//             i = nums[i] + index;
//             if(i > n)
//             {
//                 return false;
//             }
//             if(nums[i] == 0 && (i != n))
//             {
//                 return false;
//             }
//         }

//         return i == n ? true : false;
        
//     }
// };


class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > maxReach) return false;

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
