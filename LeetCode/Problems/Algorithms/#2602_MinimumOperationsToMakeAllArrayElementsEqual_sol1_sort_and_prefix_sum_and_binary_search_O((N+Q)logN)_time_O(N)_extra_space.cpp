class Solution {
private:
    long long getRangeSum(int l, int r, vector<long long>& prefSum){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<long long> prefSum(N);
        prefSum[0] = sortedNums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + sortedNums[i];
        }
        
        vector<long long> answer(Q);
        for(int i = 0; i < Q; ++i){
            long long queryVal = queries[i];
            int j = lower_bound(sortedNums.begin(), sortedNums.end(), queryVal) - sortedNums.begin();
            
            long long leftSize = j;
            long long rightSize = N - leftSize;
            
            long long leftSum = getRangeSum(0, leftSize - 1, prefSum);
            long long rightSum = getRangeSum(N - rightSize, N - 1, prefSum);
            
            answer[i] = (queryVal * leftSize - leftSum) + (rightSum - queryVal * rightSize);
        }
        
        return answer;
    }
};