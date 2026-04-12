// class Twitter {
// public:
//     Twitter() {
        
//     }
    
//     void postTweet(int userId, int tweetId) {
        
//     }
    
//     vector<int> getNewsFeed(int userId) {
        
//     }
    
//     void follow(int followerId, int followeeId) {
        
//     }
    
//     void unfollow(int followerId, int followeeId) {
        
//     }
// };

//brute force

// class Twitter {
// public:
//     int time = 0;
//     vector<tuple<int, int, int>> tweets;
//     //{time, userId, tweetId}
//     unordered_map<int, unordered_set<int>> follows;
//     //{userId, {following1, following2}}

//     void postTweet(int userId, int tweetId)
//     {
//         tweets.push_back{time++, userId, tweetId};
//     }

//     vector<int> getNewsFeed(int userId)
//     {
//         vector<pair<int, int>> feed;
//         //{time, tweetId}

//         for(auto& tweet : tweets)
//         {
//             int t = get<0>(tweet);
//             int user = get<1>(tweet);
//             int tweet  = get<2>(tweet);

//             if (user == userId || follows[userId].count(user))
//             {
//                 feed.push_back({t, tweetId});
//             } 
//         }

//         sort(feed.begin(), feed.end(), greater<pair<int, int>>());

//         vector<int> result;

//         for(int i = 0; i < min(10, (int)feed.size()); i++)
//         {
//             result.push_back(feed[i].second);
//         }

//         return result;

//     }

//     void follow(int followerId, int followeeId)
//     {
//         follows[followerId].insert(followeeId); //{cuz its a set inside, so u reach and insert inside of it}
//     }

//     void unfollow(int followerId, int followeeId)
//     {
//         follows[followerId].erase(followeeId);
//     }
// }


class Twitter {
    public:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> usertweets;
    //{userid, {tweetid, time}}
    unordered_map<int, unordered_set<int>> follows;
    //{userid, {following1, following2}}

    void postTweet(int userId, int tweetId) {
        usertweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        //{time, tweetId}

        for (auto& tweet : usertweets[userId]) //different for followee and main cuz no central db 
        {
            pq.push(tweet);
        }

        for(int followee : follows[userId])
        {
            for (auto& tweet : usertweets[followee])
            {
                pq.push(tweet);
            }
        }

        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followeeId);
    }


    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }

    };
