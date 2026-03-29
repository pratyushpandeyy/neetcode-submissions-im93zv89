class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for (int i = 0; i < 256; i++) hash[i] = -1;

        int n = s.size();
        int l = 0, max_len = 0;

        for (int r = 0; r < n; r++) {
            if (hash[s[r]] != -1) {
                l = max(l, hash[s[r]] + 1);
            }

            hash[s[r]] = r;
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};