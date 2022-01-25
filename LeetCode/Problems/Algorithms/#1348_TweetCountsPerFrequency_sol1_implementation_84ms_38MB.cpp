class TweetCounts {
private:
    unordered_map<string, vector<int>> timesOf;
    
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        timesOf[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int blockSize = 0;
        if(freq == "minute"){
            blockSize = 60;
        }else if(freq == "hour"){
            blockSize = 3600;
        }else if(freq == "day"){
            blockSize = 86400;
        }
        
        int totalTime = endTime - startTime + 1;
        int blocks = (totalTime + blockSize - 1) / blockSize;
        
        vector<int> count(blocks);
        for(int t: timesOf[tweetName]){
            if(startTime <= t && t <= endTime){
                int blockIdx = (t - startTime) / blockSize;
                count[blockIdx] += 1;
            }
        }
        
        return count;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */