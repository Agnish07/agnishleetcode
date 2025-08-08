class Twitter {
public:
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        following[userId].insert(userId);

        for(int followeeId : following[userId]){
            const auto& userTweets = tweets[followeeId];
            for (int i = userTweets.size() - 1; i >= 0 && i >= (int)userTweets.size() - 10; --i) {
                pq.push(userTweets[i]);
                if (pq.size() > 10)
    pq.pop(); // keep only 10 most recent
            }
        }


        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }
    }
};

// /**
//  * Your Twitter object will be instantiated and called as such:
//  * Twitter* obj = new Twitter();
//  * obj->postTweet(userId,tweetId);
//  * vector<int> param_2 = obj->getNewsFeed(userId);
//  * obj->follow(followerId,followeeId);
//  * obj->unfollow(followerId,followeeId);
//  *rpair<int,int>
