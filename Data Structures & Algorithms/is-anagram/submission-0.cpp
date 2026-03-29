class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqA(26,0);
        vector<int> freqB(26,0);

    if (s.size() != t.size()) return false;

        for (int i = 0; i<s.size(); i++)
        {
            freqA[s[i]-'a']++;
        }

        for(int j = 0; j<t.size(); j++)
        {
            freqB[t[j]-'a']++;
        }
        
        if (freqA == freqB)
        {
        return true;
        }

        else
        return false;
    }
};