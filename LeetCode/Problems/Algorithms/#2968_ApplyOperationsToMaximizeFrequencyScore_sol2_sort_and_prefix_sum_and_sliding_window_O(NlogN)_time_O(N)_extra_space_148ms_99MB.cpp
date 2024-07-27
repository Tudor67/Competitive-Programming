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
        int l = 0;
        for(int r = 0; r < N; ++r){
            while(l < r && computeCost(sortedNums, prefSum, l, (l + r) / 2, r) > k){
                l += 1;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};