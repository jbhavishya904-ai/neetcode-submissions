class Twitter {
public:

    unordered_map<int, vector<pair<int, int>>> tweets;

    unordered_map<int, unordered_set<int>> following;

    int time = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        vector<pair<int, int>> allTweets;

        for (auto tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        sort(allTweets.begin(), allTweets.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<int> result;
        
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            result.push_back(allTweets[i].second);
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};