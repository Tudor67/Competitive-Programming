class RMQ{
private:
    const int N;
    const int LOG_N;
    const vector<int> A;
    vector<vector<int>> r;
    
    void buildRMQ(){
        for(int i = 0; i < N; ++i){
            r[i][0] = i;
        }
        
        for(int j = 1, len = 2; j <= LOG_N; j += 1, len *= 2){
            for(int i = 0; i + len - 1 < N; ++i){
                if(A[r[i][j - 1]] <= A[r[i + len / 2][j - 1]]){
                    r[i][j] = r[i][j - 1];
                }else{
                    r[i][j] = r[i + len / 2][j - 1];
                }
            }
        }
    }
    
public:
    RMQ(const vector<int>& A): A(A), N(A.size()), LOG_N(floor(log2(N))){
        r.resize(N, vector<int>(LOG_N + 1));
        buildRMQ();
    }
    
    int query(const int& L, const int& R){
        int rangeSize = R - L + 1;
        if(rangeSize <= 0){
            return -1;
        }
        int j = floor(log2(rangeSize));
        int len = (1 << j);
        int i1 = L;
        int i2 = R - len + 1;
        if(A[r[i1][j]] <= A[r[i2][j]]){
            return r[i1][j];
        }
        return r[i2][j];
    }
};

class Solution {
private:
    int solve(const vector<int>& A, const int& L, const int& R, int prevOperations, RMQ& rmq){
        if(L > R){
            return 0;
        }
        int minIdx = rmq.query(L, R);
        int operations = A[minIdx] - prevOperations;
        return operations + solve(A, L, minIdx - 1, A[minIdx], rmq) + solve(A, minIdx + 1, R, A[minIdx], rmq);
    }
    
public:
    int minNumberOperations(vector<int>& target) {
        RMQ rmq(target);
        return solve(target, 0, (int)target.size() - 1, 0, rmq);
    }
};