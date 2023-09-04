class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        const int N = nums.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());
        
        long long prevPos = -1;
        long long blockStart = 0;
        long long toRemove = 0;
        long long processed = 0;

        for(const pair<int, int>& P: v){
            long long originalIndex = P.second;
            long long currPos = blockStart + originalIndex;
            if(currPos < prevPos){
                blockStart += N;
                currPos = blockStart + originalIndex;
                toRemove += processed;
            }
            prevPos = currPos;
            processed += 1;
        }

        return blockStart + N - toRemove;
    }
};