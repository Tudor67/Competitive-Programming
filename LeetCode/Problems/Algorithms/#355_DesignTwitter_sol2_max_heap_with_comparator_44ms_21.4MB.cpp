class Twitter {
private:
    using ListOfPairs = list<pair<int, int>>;
    using TupleOfIntIteratorIterator = tuple<int, ListOfPairs::iterator, ListOfPairs::iterator>;

    struct CompareFirst{
        bool operator()(const TupleOfIntIteratorIterator& LHS, const TupleOfIntIteratorIterator& RHS){
            return (get<0>(LHS) < get<0>(RHS));
        }
    };
    
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
        
        // maxHeap on (tweetTime, tweetCurrentIterator, tweetEndIterator)
        priority_queue<TupleOfIntIteratorIterator, vector<TupleOfIntIteratorIterator>, CompareFirst> maxHeap;
        followees[userId].insert(userId);
        
        for(int followeeId: followees[userId]){
            if(!tweets[followeeId].empty()){
                ListOfPairs::iterator tweetCurrentIterator = tweets[followeeId].begin();
                ListOfPairs::iterator tweetEndIterator = tweets[followeeId].end();
                int tweetTime = tweetCurrentIterator->first;
                maxHeap.push({tweetTime, tweetCurrentIterator, tweetEndIterator});
            }
        }
        
        while(recentTweets.size() < 10 && !maxHeap.empty()){
            ListOfPairs::iterator tweetCurrentIterator = get<1>(maxHeap.top());
            ListOfPairs::iterator tweetNextIterator = next(tweetCurrentIterator);
            ListOfPairs::iterator tweetEndIterator = get<2>(maxHeap.top());
            
            maxHeap.pop();
            
            int tweetId = tweetCurrentIterator->second;
            recentTweets.push_back(tweetId);
            
            if(tweetNextIterator != tweetEndIterator){
                int tweetTime = tweetNextIterator->first;
                maxHeap.push({tweetTime, tweetNextIterator, tweetEndIterator});
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