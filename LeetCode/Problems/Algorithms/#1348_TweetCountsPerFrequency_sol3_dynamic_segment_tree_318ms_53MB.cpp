class SegmentTree{
private:
    const int START_POS;
    const int END_POS;
    int count;
    SegmentTree* leftChild;
    SegmentTree* rightChild;
    
    void add(SegmentTree* node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            node->count += VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                if(node->leftChild == NULL){
                    node->leftChild = new SegmentTree(l, mid);
                }
                add(node->leftChild, l, mid, POS, VAL);
            }else{
                if(node->rightChild == NULL){
                    node->rightChild = new SegmentTree(mid + 1, r);
                }
                add(node->rightChild, mid + 1, r, POS, VAL);
            }
            node->count = 0;
            if(node->leftChild != NULL){
                node->count += node->leftChild->count;
            }
            if(node->rightChild != NULL){
                node->count += node->rightChild->count;
            }
        }
    }
    
    int query(SegmentTree* node, int l, int r, const int& L, const int& R){
        if(r < L || R < l || node == NULL){
            return 0;
        }
        if(L <= l && r <= R){
            return node->count;
        }
        int mid = (l + r) / 2;
        return query(node->leftChild, l, mid, L, R) +
               query(node->rightChild, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& START_POS, const int& END_POS): START_POS(START_POS), END_POS(END_POS){
        count = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    
    void add(const int& POS, const int& VAL){
        add(this, START_POS, END_POS, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(this, START_POS, END_POS, L, R);
    }
};

class TweetCounts {
private:
    unordered_map<string, SegmentTree*> timesOf;
    
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        if(!timesOf.count(tweetName)){
            timesOf[tweetName] = new SegmentTree(0, 1e9);
        }
        timesOf[tweetName]->add(time, 1);
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
        
        int totalTime = (endTime - startTime + 1);
        int blocks = (totalTime + blockSize - 1) / blockSize;
        
        vector<int> count(blocks);
        if(timesOf.count(tweetName)){
            SegmentTree* segmentTree = timesOf[tweetName];
            int blockIdx = 0;
            for(int t1 = startTime; t1 <= endTime; t1 += blockSize){
                int t2 = min(t1 + blockSize - 1, endTime);
                count[blockIdx] = segmentTree->query(t1, t2);
                blockIdx += 1;
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