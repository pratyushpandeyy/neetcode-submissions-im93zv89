class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = k-1;
        int vecsize = n - k + 1;
        vector<int>maxperwindow(vecsize,0);
        int i = 0;
        
        while(r<n)
        {
            int intmax = 0;
            for(int j = l; j <= r; j++)
            {
                intmax = max(nums[j], intmax);

            }
            maxperwindow[i] = intmax;
            i++;


            r++;
            l++;

        }

    return maxperwindow;
    }
};
