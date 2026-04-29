class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while(top <= bottom && left <= right)
        {
            for(int col = left; col <= right; col++)
            {
                res.push_back(matrix[top][col]);
            }
            top++;

            for(int row = top; row <= bottom; row++)
            {
                res.push_back(matrix[row][right]);
            }
            right--;

            if(top <= bottom)
            {
                for (int col = right; col >= left; col--)
                {
                    res.push_back(matrix[bottom][col]);
                }
            }
            bottom--;

            if(left <= right)
            {
                for(int row = bottom; row >= top; row--)
                {
                    res.push_back(matrix[row][left]);
                }
            }
            left++;
        }

        return res;
        
    }
};
