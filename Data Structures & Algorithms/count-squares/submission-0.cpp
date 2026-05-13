class CountSquares {
public:
    map<pair<int, int>, int> points;

    CountSquares() 
    {
        
    }
    
    void add(vector<int> point) 
    {
        int x = point[0];
        int y = point[1];

        points[{x, y}]++;
    }
    
    int count(vector<int> point) 
    {
        int x1 = point[0];
        int y1 = point[1];

        int ans = 0;

        for (auto& entry : points)
        {
            int x2 = entry.first.first;
            int y2 = entry.first.second;

            int diagonalCount = entry.second;

            if(abs(x2 -x1) == abs(y2-y1) && x2 != x1 && y2 != y1)
            {
                int count1 = points[{x1, y2}];
                int count2 = points[{x2, y1}];
            }

            ans += diagonalCount * count1 * count2;

        }
        return ans;
        
    }
};
