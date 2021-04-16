class RollingHash{
private:
    static const int MODULO = 666013;
    static const int BASE = 113;
    
    const int SIZE;
    queue<int> values;
    int hashValue;
    int maxPow;
    
    void init(){
        hashValue = 0;
        maxPow = 1;
        for(int i = 1; i <= SIZE - 1; ++i){
            maxPow = (maxPow * BASE) % MODULO;
        }
    }
    
public:
    RollingHash(const int& SIZE): SIZE(SIZE){
        init();
    }
    
    void pushBack(const int& VALUE){
        int frontHashValue = 0;
        if((int)values.size() == SIZE){
            frontHashValue = (values.front() * maxPow) % MODULO;
            values.pop();
        }
        hashValue = (((hashValue - frontHashValue + MODULO) % MODULO) * BASE + VALUE) % MODULO;
        values.push(VALUE);
    }
    
    int getHashValue(){
        assert((int)values.size() == SIZE);
        return hashValue;
    }
};

bool isValid(const vector<int>& A, const int& N, const vector<int>& B, const int& M, const int& LEN){
    unordered_map<int, vector<int>> hashPositionsInB;
    RollingHash hashB(LEN);
    for(int j = 0; j < M; ++j){
        hashB.pushBack(B[j]);
        if(j >= LEN - 1){
            hashPositionsInB[hashB.getHashValue()].push_back(j);
        }
    }
    bool found = false;
    RollingHash hashA(LEN);
    for(int i = 0; !found && i < N; ++i){
        hashA.pushBack(A[i]);
        if(i >= LEN - 1){
            int hashValue = hashA.getHashValue();
            if(hashPositionsInB.count(hashValue)){
                for(int j: hashPositionsInB[hashValue]){
                    found = true;
                    for(int k = 0; k < LEN; ++k){
                        if(A[i - k] != B[j - k]){
                            found = false;
                        }
                    }
                    if(found){
                        break;
                    }
                }
            }
        }
    }
    return found;
}

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty() || B.empty()){
            return 0;
        }
        
        const int N = A.size();
        const int M = B.size();
        
        int l = 1;
        int r = min(N, M);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(A, N, B, M, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        int answer = 0;
        if(isValid(A, N, B, M, r)){
            answer = r;
        }
        
        return answer;
    }
};