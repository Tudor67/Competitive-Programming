class SparseTable{
private:
    const int N;
    const int LOG_N;
    vector<vector<int>> a;
    vector<int> myLog2;

public:
    SparseTable(const vector<int>& NUMS): N(NUMS.size()), LOG_N(log2(N)){
        a.assign(LOG_N + 1, vector<int>(N, INT_MAX));
        for(int i = 0; i < N; ++i){
            a[0][i] = NUMS[i];
        }

        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i + len - 1 < N; ++i){
                a[k][i] = min(a[k - 1][i], a[k - 1][i + len / 2]);
            }
        }

        myLog2.assign(N + 1, 0);
        for(int i = 2; i <= N; ++i){
            myLog2[i] = myLog2[i / 2] + 1;
        }
    }

    int getMin(const int L, const int R){
        int len = R - L + 1;
        int k = myLog2[len];
        return min(a[k][L], a[k][R - (1 << k) + 1]);
    }
};

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);

        long long res = TOTAL_SUM;
        
        SparseTable sparseTable(nums);
        for(long long ops = 1; ops < N; ++ops){
            long long cost = 0;
            for(int i = 0; i < N; ++i){
                if(i + ops < N){
                    cost += sparseTable.getMin(i, i + ops);
                }else{
                    cost += min(sparseTable.getMin(i, N - 1),
                                sparseTable.getMin(0, (i + ops) % N));
                }
            }
            res = min(res, cost + ops * x);
        }
        
        return res;
    }
};