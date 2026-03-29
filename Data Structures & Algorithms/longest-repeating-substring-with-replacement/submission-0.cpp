// start iteration, update frequency of the respective character in the hashmap, compare it against maxfrqeuency, check how many replacement are needed, if it is less than k, then the replacement is valid, and the max length will be max freq + k, if it is not valid, increment l, update the frqwuencies of the hasmap, update the maxfreq, 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int maxfreq = 0;
        int l = 0, r = 0;
        vector<int> freq(26,0);

        for(r = 0; r < s.size(); r++)
        {
            freq[s[r]-'A']++;
            maxfreq = max(maxfreq, freq[s[r]-'A']);

            while(r-l+1 - maxfreq > k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
