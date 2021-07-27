class RollingHash{
private:
    static const int MODULO = 666013;
    static const int BASE = 101;
    const int SIZE;
    const int MAX_POW;
    int hash;
    deque<int> values;
    
    static int pow(const int& A, const int& N, const int& MODULO){
        int p = 1;
        for(int i = 1; i <= N; ++i){
            p *= A;
            p %= MODULO;
        }
        return p;
    }
    
public:
    RollingHash(const int& SIZE): SIZE(SIZE), MAX_POW(pow(BASE, SIZE - 1, MODULO)), hash(0){
        assert(SIZE > 0);
    }
    
    void append(const int& VAL){
        if((int)values.size() == SIZE){
            hash = ((hash - MAX_POW * 1LL * values.front()) % MODULO + MODULO) % MODULO;
            values.pop_front();
        }
        hash = (hash * BASE + VAL) % MODULO;
        values.push_back(VAL);
    }
    
    int getHash(){
        assert((int)values.size() == SIZE);
        return hash;
    }
};

class Solution {
private:
    bool match(const vector<int>& A, const int& A_START_IDX, const vector<int>& B, const int& B_START_IDX, const int& SIZE){
        const int N = A.size();
        const int M = B.size();
        if(A_START_IDX + SIZE - 1 >= N || B_START_IDX + SIZE - 1 >= M){
            return false;
        }
        for(int i = A_START_IDX, j = B_START_IDX; i <= A_START_IDX + SIZE - 1 && j <= B_START_IDX + SIZE - 1; ++i, ++j){
            if(A[i] != B[j]){
                return false;
            }
        }
        return true;
    }
    
    bool isValid(const vector<int>& A, const int& N, const vector<int>& B, const int& M, const int& SIZE){
        if(SIZE == 0){
            return true;
        }
        // Store hashes of all subarrays (with a fixed size) from A
        RollingHash hashObjA(SIZE);
        unordered_map<int, vector<int>> hashToIndicesInA;
        for(int i = 0; i < N; ++i){
            hashObjA.append(A[i]);
            if(i >= SIZE - 1){
                hashToIndicesInA[hashObjA.getHash()].push_back(i - SIZE + 1);
            }
        }
        // Iterate through all subarrays from B:
        //     If the current hash of a subarray from B exists in hashes of subarrays from A
        //        then check if there is a match between those subarrays
        RollingHash hashObjB(SIZE);
        for(int i = 0; i < M; ++i){
            hashObjB.append(B[i]);
            if(i >= SIZE - 1){
                int hashB = hashObjB.getHash();
                if(hashToIndicesInA.count(hashB)){
                    const vector<int>& INDICES_IN_A = hashToIndicesInA[hashB];
                    const int B_START_IDX = i - SIZE + 1;
                    for(const int A_START_IDX: INDICES_IN_A){
                        if(match(A, A_START_IDX, B, B_START_IDX, SIZE)){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        int l = 0;
        int r = min(N, M);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(A, N, B, M, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};