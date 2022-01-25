#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class TweetCounts {
private:
    unordered_map<string, ordered_set<pair<int, int>>> timesOf;
    int recordID;
    
public:
    TweetCounts() {
        recordID = 0;
    }
    
    void recordTweet(string tweetName, int time) {
        timesOf[tweetName].insert({time, recordID});
        recordID += 1;
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
        int blockIdx = 0;
        for(int t1 = startTime; t1 <= endTime; t1 += blockSize){
            int t2 = min(t1 + blockSize, endTime + 1);
            count[blockIdx] = timesOf[tweetName].order_of_key({t2, 0}) - 
                              timesOf[tweetName].order_of_key({t1, 0});
            blockIdx += 1;
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