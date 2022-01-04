class RollingHash{
private:
    const int SIZE;
    const long long BASE;
    const long long MODULO;
    long long maxPow;
    long long hashVal;
    deque<long long> nums;
    
public:
    RollingHash(const int& SIZE, const long long& BASE, const long long& MODULO): SIZE(SIZE), BASE(BASE), MODULO(MODULO){
        maxPow = 1;
        for(int i = 1; i <= SIZE - 1; ++i){
            maxPow *= BASE;
            maxPow %= MODULO;
        }
        reset();
    }
    
    void reset(){
        hashVal = 0;
        nums.clear();
    }
    
    long long pushBack(long long num){
        if((int)nums.size() == SIZE){
            hashVal -= (nums.front() * maxPow) % MODULO;
            if(hashVal < 0){
                hashVal += MODULO;
            }
            nums.pop_front();
        }
        
        nums.push_back(num);
        hashVal *= BASE;
        hashVal += num;
        hashVal %= MODULO;
        
        if((int)nums.size() < SIZE){
            return -1;
        }
        return hashVal;
    }
};

class Solution {
private:
    bool isValid(vector<vector<int>>& paths, const int& W){
        if(W == 0){
            return true;
        }
        
        const long long BASE = 1e5 + 19;
        const long long MODULO1 = 1e9 + 7;
        const long long MODULO2 = 1e9 + 9;
        
        RollingHash hashObj1(W, BASE, MODULO1);
        RollingHash hashObj2(W, BASE, MODULO2);
        
        set<pair<int, int>> hashValuesIntersection[2];
        for(int j = 0; j < (int)paths[0].size(); ++j){
            long long hash1 = hashObj1.pushBack(paths[0][j]);
            long long hash2 = hashObj2.pushBack(paths[0][j]);
            if(hash1 != -1){
                hashValuesIntersection[0].emplace(hash1, hash2);
            }
        }
        
        for(int i = 1; i < (int)paths.size(); ++i){
            hashObj1.reset();
            hashObj2.reset();
            hashValuesIntersection[i % 2].clear();
            for(int j = 0; j < (int)paths[i].size(); ++j){
                long long hash1 = hashObj1.pushBack(paths[i][j]);
                long long hash2 = hashObj2.pushBack(paths[i][j]);
                if(hash1 != -1 && hashValuesIntersection[(i - 1) % 2].count({hash1, hash2})){
                    hashValuesIntersection[i % 2].emplace(hash1, hash2);
                }
            }
            if(hashValuesIntersection[i % 2].empty()){
                return false;
            }
        }
        
        return true;
    }
    
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int minSize = paths[0].size();
        for(const vector<int>& PATH: paths){
            int size = PATH.size();
            minSize = min(minSize, size);
        }
        
        int l = 0;
        int r = minSize;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(paths, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};