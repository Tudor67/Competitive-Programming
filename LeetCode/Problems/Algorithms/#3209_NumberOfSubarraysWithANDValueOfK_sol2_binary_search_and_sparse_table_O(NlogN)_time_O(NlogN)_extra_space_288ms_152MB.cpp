class SparseTable{
private:
    vector<vector<int>> a;
    vector<int> myLog2;

public:
    SparseTable(const vector<int>& NUMS){
        const int N = NUMS.size();

        myLog2.assign(N + 1, 0);
        for(int i = 2; i <= N; ++i){
            myLog2[i] = 1 + myLog2[i / 2];
        }

        const int LOG_N = myLog2[N];
        a.assign(LOG_N + 1, vector<int>(N));
        for(int i = 0; i < N; ++i){
            a[0][i] = NUMS[i];
        }

        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i + len - 1 < N; ++i){
                a[k][i] = a[k - 1][i] & a[k - 1][i + len / 2];
            }
        }
    }

    int queryAND(int l, int r){
        int len = r - l + 1;
        int k = myLog2[len];
        return (a[k][l] & a[k][r - (1 << k) + 1]);
    }
};

class Solution {
private:
    int lowerBound(const int START_INDEX, int l, int r, SparseTable& sparseTable, int k){
        while(l != r){
            int mid = (l + r) / 2;
            if(sparseTable.queryAND(START_INDEX, mid) > k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        long long res = 0;
        SparseTable sparseTable(nums);

        for(int i = 0; i < N; ++i){
            if(nums[i] >= k){
                res += (lowerBound(i, i, N, sparseTable, k - 1) -
                        lowerBound(i, i, N, sparseTable, k));
            }
        }

        return res;
    }
};