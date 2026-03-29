class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        // int leftMax = 0;
        vector<int> leftMaxi (height.size(), 0);
        leftMaxi[0] = height[0];
        
        for (int i = 1; i < n; i++)
        {
            leftMaxi[i] = max(leftMaxi[i-1],height[i]);
        }

        int rightmax = height[n-1];
        int watervol = 0;
        int currwater;

        for (int i = n-2; i>=0; i--)
        {   
            rightmax = max(rightmax, height[i]);
            currwater = min(leftMaxi[i], rightmax) - height[i]; 
            watervol+=currwater;

        }

        return watervol;
        
    }
};
