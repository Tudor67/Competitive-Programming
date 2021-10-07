class Solution {
private:
    bool isValid(const vector<int>& COUNT){        
        for(int c: COUNT){
            if(c != 0){
                return false;
            }
        }
        return true;
    }
    
    void back(int level, int mask, vector<int>& count, const vector<vector<int>>& REQUESTS, int& maxRequests){
        if(level < 0){
            int currentRequests = __builtin_popcount((unsigned int)mask);
            if(maxRequests < currentRequests && isValid(count)){
                maxRequests = currentRequests;
            }
        }else{
            // mask
            back(level - 1, mask, count, REQUESTS, maxRequests);
            int from = REQUESTS[level][0];
            int to = REQUESTS[level][1];
            count[from] -= 1;
            count[to] += 1;
            // mask | (1 << level)
            back(level - 1, mask | (1 << level), count, REQUESTS, maxRequests);
            count[from] += 1;
            count[to] -= 1;
        }
    }
    
public:
    int maximumRequests(int N, vector<vector<int>>& requests) {
        const int R = requests.size();
        const int FULL_MASK = (1 << R) - 1;
        
        vector<int> count(N, 0);
        int maxRequests = 0;
        back(R - 1, 0, count, requests, maxRequests);
        
        return maxRequests;
    }
};