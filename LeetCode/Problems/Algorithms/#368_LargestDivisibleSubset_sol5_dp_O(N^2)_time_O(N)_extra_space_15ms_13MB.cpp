class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // maxSize[i]: max size of a valid subset of sortedNums[i .. N - 1]
        //             when sortedNums[i] is included in subset
        vector<int> maxSize(N, 1);
        vector<int> nextIndex(N, N);
        for(int i = N - 2; i >= 0; --i){
            for(int j = i + 1; j < N; ++j){
                if(sortedNums[j] % sortedNums[i] == 0){
                    if(maxSize[i] < maxSize[j] + 1){
                        maxSize[i] = maxSize[j] + 1;
                        nextIndex[i] = j;
                    }
                }
            }
        }

        int index = max_element(maxSize.begin(), maxSize.end()) - maxSize.begin();
        vector<int> maxSubset;
        while(index != N){
            maxSubset.push_back(sortedNums[index]);
            index = nextIndex[index];
        }

        return maxSubset;
    }
};