class Solution {
private:
    long long getRangeSum(vector<long long>& prefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
    long long computeCost(vector<int>& sortedNums, vector<long long>& prefSum, int l, int mid, int r){
        long long leftSize = mid - l + 1;
        long long rightSize = r - mid;
        long long leftCost = sortedNums[mid] * leftSize - getRangeSum(prefSum, l, mid);
        long long rightCost = getRangeSum(prefSum, mid + 1, r) - sortedNums[mid] * rightSize;
        return leftCost + rightCost;
    }
    
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<long long> prefSum(N);
        prefSum[0] = sortedNums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + sortedNums[i];
        }
        
        int res = 1;
        for(int i = 0; i < N; ++i){
            int l = i;
            int r = N - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(computeCost(sortedNums, prefSum, i, (i + mid) / 2, mid) <= k){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            res = max(res, r - i + 1);
        }
        
        return res;
    }
};