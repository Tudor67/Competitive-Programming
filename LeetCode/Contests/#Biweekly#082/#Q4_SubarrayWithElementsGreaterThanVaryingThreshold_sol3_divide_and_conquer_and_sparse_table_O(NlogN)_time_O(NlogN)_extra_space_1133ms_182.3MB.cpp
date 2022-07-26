class SparseTable{
private:
    const int N;
    const vector<int> NUMS;
    vector<int> log2Of;
    vector<vector<int>> a;
    
public:
    SparseTable(const vector<int>& NUMS): N(NUMS.size()), NUMS(NUMS){
        log2Of.resize(N + 1);
        for(int i = 2; i <= N; ++i){
            log2Of[i] = 1 + log2Of[i / 2];
        }
        
        a.assign(log2Of[N] + 1, vector<int>(N));
        for(int i = 0; i < N; ++i){
            a[0][i] = i;
        }
        
        for(int k = 1; k <= log2Of[N]; ++k){
            for(int i = 0; i + (1 << k) - 1 < N; ++i){
                if(NUMS[a[k - 1][i]] <= NUMS[a[k - 1][i + (1 << (k - 1))]]){
                    a[k][i] = a[k - 1][i];
                }else{
                    a[k][i] = a[k - 1][i + (1 << (k - 1))];
                }
            }
        }
    }
    
    int getFirstIdxOfMin(const int& L, const int& R){
        int rangeSize = R - L + 1;
        int k = log2Of[rangeSize];
        if(NUMS[a[k][L]] <= NUMS[a[k][R - (1 << k) + 1]]){
            return a[k][L];
        }
        return a[k][R - (1 << k) + 1];
    }
};

class Solution {
private:
    int solve(vector<int>& nums, const int& L, const int& R, const int& THRESHOLD, SparseTable& sparseTable){
        if(L > R){
            return -1;
        }
        
        int firstIdxOfMin = sparseTable.getFirstIdxOfMin(L, R);
        long long minNum = nums[firstIdxOfMin];
        if(minNum * (R - L + 1) > THRESHOLD){
            return R - L + 1;
        }
        
        int leftResult = solve(nums, L, firstIdxOfMin - 1, THRESHOLD, sparseTable);
        int rightResult = solve(nums, firstIdxOfMin + 1, R, THRESHOLD, sparseTable);
        return max(leftResult, rightResult);
    }
    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        const int N = nums.size();
        SparseTable sparseTable(nums);
        return solve(nums, 0, N - 1, threshold, sparseTable);
    }
};