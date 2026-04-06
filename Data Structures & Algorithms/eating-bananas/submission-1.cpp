class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    { 
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;

    while (low <= high)
    {
        int mid = low + (high - low)/2;        
        long long total_time = 0;

        for (int i  = 0; i < piles.size(); i++)
        {
            total_time += ceil((double)piles[i]/double(mid));
        }

        if(total_time > h)
        {
            low = mid + 1;
            
        }
        else 
        {
            high = mid - 1;
        }

    }
    return low;
   
    }
};
