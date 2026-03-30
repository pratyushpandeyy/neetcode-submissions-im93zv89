class TimeMap {
public:
    unordered_map <string, vector<pair<int, string>>> mp; //vector cuz push_back according to timestamps puts it into auto sorted order, get can use binary search 

    TimeMap() 
    { 
    }
    
    void set(string key, string value, int timestamp) 
    {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        if (mp.find(key) == mp.end()) return "";

        vector<pair<int, string>>& vec = mp[key];

        int low = 0;
        int high = vec.size() - 1;
        string ans = "";

        while (low <= high)
        {
            int mid = low + (high - low)/2;

            if (vec[mid].first > timestamp)
            {
                high = mid - 1;
            } 
            else 
            {
                ans = vec[mid].second; //greatest answer less than the required answer 
                low = mid + 1;
            }

        }
        return ans;
        
    }
};
