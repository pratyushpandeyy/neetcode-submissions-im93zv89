class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int, int>> pq;
        int i = 0;
        vector<vector<int>> results;
        for(vector<int> num : points)
        {
            int distance = (num[0] - 0) * (num[0] - 0)  + (num[1] - 0) * (num[1] - 0);
            pq.push({distance, i});
            i++;
            if(pq.size() > k)
            {
                pq.pop();
            }

        }
        while(pq.size() != 0)
        {
            auto temp = pq.top();
            pq.pop();
            results.push_back(points[temp.second]);
        }
        return results;
        
    }
};
