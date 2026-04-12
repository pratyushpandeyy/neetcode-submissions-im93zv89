class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;

        for(int stone : stones)
        {
            pq.push(stone);
        }

        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            // if(x==y)
            // {
            //     continue;
            // }
            if(x < y or y < x)
            {
                pq.push(abs(y-x));
            }
            if(pq.size() == 1)
            {
                return pq.top();
            }
        }

        return 0;

    }
};
