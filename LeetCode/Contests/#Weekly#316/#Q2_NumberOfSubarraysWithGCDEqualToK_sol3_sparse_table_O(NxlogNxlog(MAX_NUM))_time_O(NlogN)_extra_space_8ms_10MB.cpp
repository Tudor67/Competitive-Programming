class SparseTable{
private:
    const int N;
    const int LOG_N;
    vector<vector<int>> t;
    vector<int> logOf;
    
public:
    SparseTable(const vector<int>& V): N(V.size()), LOG_N(floor(log2(N))){
        t.assign(LOG_N + 1, vector<int>(N));
        logOf.assign(N + 1, 0);
        
        for(int i = 2; i <= N; ++i){
            logOf[i] = logOf[i / 2] + 1;
        }
        
        for(int i = 0; i < N; ++i){
            t[0][i] = V[i];
        }
        
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i + len / 2 < N; ++i){
                t[k][i] = gcd(t[k - 1][i], t[k - 1][i + len / 2]);
            }
        }
    }
    
    int query(int l, int r){
        int k = logOf[r - l + 1];
        return gcd(t[k][l], t[k][r - (1 << k) + 1]);
    }
};

class Solution {
private:
    int upperBound(int firstPos, int lastPos, SparseTable& sparseTable, int k){
        int l = firstPos;
        int r = lastPos;
        while(l != r){
            int mid = (l + r) / 2;
            if(sparseTable.query(firstPos, mid) < k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
    
    int lowerBound(int firstPos, int lastPos, SparseTable& sparseTable, int k){
        int l = firstPos;
        int r = lastPos;
        while(l != r){
            int mid = (l + r) / 2;
            if(sparseTable.query(firstPos, mid) <= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
    
public:
    int subarrayGCD(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int res = 0;
        SparseTable sparseTable(nums);
        for(int i = 0; i < N; ++i){
            res += upperBound(i, N, sparseTable, k) - lowerBound(i, N, sparseTable, k);
        }
        
        return res;
    }
};