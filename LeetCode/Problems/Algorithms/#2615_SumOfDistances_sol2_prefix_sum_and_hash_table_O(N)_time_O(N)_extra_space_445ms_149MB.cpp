class Solution {
private:
    long long getRangeSum(int l, int r, const vector<long long>& PREF_SUM){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return PREF_SUM[r];
        }
        return PREF_SUM[r] - PREF_SUM[l - 1];
    }
    
public:
    vector<long long> distance(vector<int>& nums) {
        const long long N = nums.size();
        
        unordered_map<int, vector<long long>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }
        
        unordered_map<int, vector<long long>> numToIndicesPrefSum;
        for(const pair<int, vector<long long>>& P: numToIndices){
            int num = P.first;
            vector<long long> prefSum = P.second;
            for(int j = 1; j < (int)prefSum.size(); ++j){
                prefSum[j] += prefSum[j - 1];
            }
            numToIndicesPrefSum[num] = prefSum;
        }
        
        vector<long long> res(N);
        unordered_map<int, int> leftSizeOf;
        for(long long i = 0; i < N; ++i){
            int num = nums[i];
            
            const vector<long long>& INDICES = numToIndices[num];
            const vector<long long>& INDICES_PREF_SUM = numToIndicesPrefSum[num];

            long long totalSize = INDICES.size();
            long long leftSize = leftSizeOf[num];
            long long rightSize = totalSize - leftSize;
            
            long long leftContrib = leftSize * i - getRangeSum(0, leftSize - 1, INDICES_PREF_SUM);
            long long rightContrib = getRangeSum(leftSize, totalSize - 1, INDICES_PREF_SUM) - rightSize * i;

            res[i] = leftContrib + rightContrib;

            leftSizeOf[num] += 1;
        }
        
        return res;
    }
};