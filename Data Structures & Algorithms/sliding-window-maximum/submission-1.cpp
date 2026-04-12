// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         int l = 0;
//         int r = k-1;
//         int vecsize = n - k + 1;
//         vector<int>maxperwindow(vecsize,0);
//         int i = 0;
        
//         while(r<n)
//         {
//             int intmax = 0;
//             for(int j = l; j <= r; j++)
//             {
//                 intmax = max(nums[j], intmax);

//             }
//             maxperwindow[i] = intmax;
//             i++;


//             r++;
//             l++;

//         }

//     return maxperwindow;
//     }
// };


class Solution {
    public :
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        //deque to store indices of useful elements in the current window 
        deque<int> dq;

        //Result vector to store the maximum 
        vector<int> result;

        //Loop through each element in the array

        for(int i = 0; i< nums.size(); i++)
        {
            //remove those elements that are out of a window's range
            if(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            //remove those elements that are smaller than tha current element in the current window 
            while(!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k-1)
            {
                result.push_back(nums[dq.front()]);
            }

        }
        return result;
    }
};