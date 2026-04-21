class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        
        if (n % groupSize != 0) return false;

        map<int, int> freq;

        for (int i : hand)
        {
            freq[i]++;
        }

        for (auto& [card, count] : freq)
        {
            if (count > 0)
            {
                int start = card;
                int groupsTostart = count;

                for(int x = start; x < start + groupSize; x++)
                {
                    if(freq[x] < groupsTostart)
                    {
                        return false;
                    }
                    freq[x] -= groupsTostart;
                }
            }
        }
        return true;

    }
};
