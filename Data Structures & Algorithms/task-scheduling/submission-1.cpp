// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> freq(26, 0);

//         for (char task : tasks) {
//             freq[task - 'A']++;
//         }

//         int maxFreq = 0;
//         for (int count : freq) {
//             maxFreq = max(maxFreq, count);
//         }

//         int maxCount = 0;
//         for (int count : freq) {
//             if (count == maxFreq) {
//                 maxCount++;
//             }
//         }

//         int answer = (maxFreq - 1) * (n + 1) + maxCount;

//         return max((int)tasks.size(), answer);
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) {
                pq.push(count);
            }
        }

        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                count--;

                if (count > 0) {
                    cooldown.push({count, time + n + 1});
                }
            }

            if (!cooldown.empty() && cooldown.front().second == time + 1) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};