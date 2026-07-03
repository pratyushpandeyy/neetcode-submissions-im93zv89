class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // add every character that appears
        for (auto& word : words) {
            for (char c : word) {
                if (!indegree.count(c)) {
                    indegree[c] = 0;
                    adj[c] = {};
                }
            }
        }

        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool foundDiff = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j]].push_back(s2[j]);
                    indegree[s2[j]]++;
                    foundDiff = true;
                    break;
                }
            }

            // invalid case: "abc" before "ab"
            if (!foundDiff && s1.size() > s2.size()) {
                return "";
            }
        }

        queue<char> q;

        for (auto& it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string ans = "";

        while (!q.empty()) {
            char node = q.front();
            q.pop();

            ans += node;

            for (char nei : adj[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (ans.size() != indegree.size()) {
            return "";
        }

        return ans;
    }
};