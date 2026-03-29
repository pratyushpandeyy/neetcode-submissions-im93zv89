// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) return 0;

//         sort(nums.begin(), nums.end());

//         int longest = 1;
//         int curr = 1;

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i - 1]) {
//                 continue; // ignore duplicate
//             }
//             else if (nums[i] == nums[i - 1] + 1) {
//                 curr++;
//             }
//             else {
//                 longest = max(longest, curr);
//                 curr = 1;
//             }
//         }

//         longest = max(longest, curr);
//         return longest;
//     }
// };


class Solution {
    public:
        int longestConsecutive(vector<int>&nums) {

            int n =  nums.size();
            if (n==0) return 0;
            int longest = 1;

            unordered_set<int> st(nums.begin(), nums.end());

            for (int i : st)
            {
                if ( st.find(i-1) == st.end() )
                {
                    int currNum = i;
                    int currLen = 1;

                    while (st.find(currNum+1) != st.end())
                    {
                        currNum++;
                        currLen++;
                    }

                    longest = max(longest, currLen);
                }
            }
            return longest;

        }
};
