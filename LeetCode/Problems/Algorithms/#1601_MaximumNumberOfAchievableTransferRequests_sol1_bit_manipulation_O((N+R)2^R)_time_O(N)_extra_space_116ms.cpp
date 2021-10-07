class Solution {
private:
    bool isValid(const int& N, const int& R, const vector<vector<int>>& REQUESTS, int mask){
        static vector<int> count;
        
        count.resize(N);
        fill(count.begin(), count.end(), 0);
        
        for(int bit = 0; bit < R; ++bit){
            if((mask >> bit) & 1){
                int from = REQUESTS[bit][0];
                int to = REQUESTS[bit][1];
                count[from] -= 1;
                count[to] += 1;
            }
        }
        
        for(int i = 0; i < N; ++i){
            if(count[i] != 0){
                return false;
            }
        }
        
        return true;
    }
    
public:
    int maximumRequests(int N, vector<vector<int>>& requests) {
        const int R = requests.size();
        const int FULL_MASK = (1 << R) - 1;
        
        int maxRequests = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int currentRequests = __builtin_popcount((unsigned int)mask);
            if(maxRequests < currentRequests && isValid(N, R, requests, mask)){
                maxRequests = currentRequests;
            }
        }
        
        return maxRequests;
    }
};