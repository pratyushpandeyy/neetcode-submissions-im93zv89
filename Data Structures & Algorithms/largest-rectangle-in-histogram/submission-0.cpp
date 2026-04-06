class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) // n for imaginary bar at the end //add elements in increasing order of height, 
        //when u think ur breaking the flow, that is when you pop in the while loop until the top of the stack is smaller than your current element, so u do the while loop until the curent element is smaller than the current stack top 
        // the max area of a bar in this range is limited by heights smaller than this,s o we want the stack to represent candidates that are still alive, or the ones who are yet to find a smaller element than them which can limit their max area potential 


        // we do the calcualtion when we pop, the nse is the element at which u landed, the pse is the one right before it in the stack cuz that is how the stack is stored 
        {
                while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
                {
                    int height = heights[st.top()];
                    st.pop();
                    int nse = i;
                    int pse = st.empty() ? -1 : st.top();

                    // if (st.empty())
                    // {
                    //     maxA = max(maxA, i * height);
                    // } 
                    // else
                    // {
                        maxA = max(maxA, (nse - pse - 1) * height);
                    // }
 

                }
                st.push(i);
        }
        return maxA;

        
    }
};
