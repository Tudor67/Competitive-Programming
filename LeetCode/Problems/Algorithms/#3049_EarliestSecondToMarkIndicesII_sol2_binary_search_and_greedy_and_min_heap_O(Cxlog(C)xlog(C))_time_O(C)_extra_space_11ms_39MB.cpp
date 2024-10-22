class Solution {
private:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, const int LIMIT){
        const int N = nums.size();
        const int C = changeIndices.size();

        vector<bool> seen(N, false);
        vector<bool> isSpecialTime(LIMIT + 1, false);
        for(int j = 0; j <= LIMIT; ++j){
            int i = changeIndices[j] - 1;
            if(!seen[i] && nums[i] >= 1){
                seen[i] = true;
                isSpecialTime[j] = true;
            }
        }

        long long totalOps = accumulate(nums.begin(), nums.end(), (long long)0) + N;
        long long availableOps = 0;
        long long minHeapSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int j = LIMIT; j >= 0; --j){
            if(isSpecialTime[j]){
                int i = changeIndices[j] - 1;
                minHeapSum += nums[i];
                minHeap.push(nums[i]);

                if(availableOps >= 1){
                    availableOps -= 1;
                }else{
                    availableOps += 1;
                    minHeapSum -= minHeap.top();
                    minHeap.pop();
                }
            }else{
                availableOps += 1;
            }
        }

        return (totalOps - minHeapSum - (int)minHeap.size() <= availableOps);
    }

public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        const int N = nums.size();
        const int C = changeIndices.size();

        if(N > C || !isPossible(nums, changeIndices, C - 1)){
            return -1;
        }

        int l = N - 1;
        int r = C - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(nums, changeIndices, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r + 1;
    }
};