class AuthenticationManager {
private:
    long long timeToLive;
    map<string, long long> tokenToLastTime;
    set<long long> lastTimeSet;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        long long lastTime = currentTime + timeToLive - 1;
        tokenToLastTime[tokenId] = lastTime;
        lastTimeSet.insert(lastTime);
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokenToLastTime.count(tokenId) && currentTime <= tokenToLastTime[tokenId]){
            lastTimeSet.erase(tokenToLastTime[tokenId]);
            long long newLastTime = currentTime + timeToLive - 1;
            tokenToLastTime[tokenId] = newLastTime;
            lastTimeSet.insert(newLastTime);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        set<long long>::iterator it = lastTimeSet.lower_bound(currentTime);
        lastTimeSet.erase(lastTimeSet.begin(), it);
        return lastTimeSet.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */