class Twitter {
private:
    int currentTime;
    unordered_map<int, list<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        currentTime = 1;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front({currentTime, tweetId});
        if(tweets[userId].size() == 11){
            tweets[userId].pop_back();
        }
        currentTime += 1;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> recentTweets;
        
        // maxHeap on (tweetTime, tweetId, tweetIteratorsIdx)
        priority_queue<tuple<int, int, int>> maxHeap;
        vector<pair<list<pair<int, int>>::iterator, list<pair<int, int>>::iterator>> tweetIterators;
        followees[userId].insert(userId);
        
        for(int followeeId: followees[userId]){
            if(!tweets[followeeId].empty()){
                int tweetTime = tweets[followeeId].begin()->first;
                int tweetId = tweets[followeeId].begin()->second;
                int tweetIteratorsIdx = tweetIterators.size();
                maxHeap.push({tweetTime, tweetId, tweetIteratorsIdx});
                tweetIterators.push_back({tweets[followeeId].begin(), tweets[followeeId].end()});
            }
        }
        
        while(recentTweets.size() < 10 && !maxHeap.empty()){
            int tweetId = get<1>(maxHeap.top());
            int tweetIteratorsIdx = get<2>(maxHeap.top());
            maxHeap.pop();
            
            recentTweets.push_back(tweetId);
            
            list<pair<int, int>>::iterator itNext = next(tweetIterators[tweetIteratorsIdx].first);
            list<pair<int, int>>::iterator itEnd = tweetIterators[tweetIteratorsIdx].second;
            if(itNext != itEnd){
                int tweetTime = itNext->first;
                int tweetId = itNext->second;
                maxHeap.push({tweetTime, tweetId, tweetIteratorsIdx});
                tweetIterators[tweetIteratorsIdx].first = itNext;
            }
        }
        
        return recentTweets;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followees.find(followerId) == followees.end() ||
           followees[followerId].find(followeeId) == followees[followerId].end()){
            return;
        }
        followees[followerId].erase(followees[followerId].find(followeeId));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */