class SparseTable{
private:
    const int N;
    const int LOG_N;
    vector<vector<pair<int, int>>> t;
    vector<int> log2Of;
    
public:
    SparseTable(const vector<int>& ARR): N(ARR.size()), LOG_N(floor(log2(N))){
        t.assign(N, vector<pair<int, int>>(LOG_N + 1));
        for(int i = 0; i < N; ++i){
            t[i][0] = {ARR[i], i};
        }
        
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i + len - 1 < N; ++i){
                t[i][k] = min(t[i][k - 1], t[i + len / 2][k - 1]);
            }
        }
        
        log2Of.assign(N + 1, 0);
        for(int i = 2; i <= N; ++i){
            log2Of[i] = log2Of[i / 2] + 1;
        }
    }
    
    int getPosOfMin(const int& L, const int& R){
        const int SIZE = R - L + 1;
        int k = log2Of[SIZE];
        return min(t[L][k], t[R - (1 << k) + 1][k]).second;
    }
};

class Solution {
private:
    long long solve(vector<int>& arr, const int& L, const int& R, SparseTable& sparseTable, const long long& MODULO){
        if(L > R){
            return 0;
        }
        long long posOfMin = sparseTable.getPosOfMin(L, R);
        long long contrib = (posOfMin - L + 1) * (R - posOfMin + 1) * arr[posOfMin];
        long long leftContrib = solve(arr, L, posOfMin - 1, sparseTable, MODULO);
        long long rightContrib = solve(arr, posOfMin + 1, R, sparseTable, MODULO);
        return (contrib + leftContrib + rightContrib) % MODULO;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MODULO = 1e9 + 7;
        const int N = arr.size();
        SparseTable sparseTable(arr);
        return solve(arr, 0, N - 1, sparseTable, MODULO);
    }
};