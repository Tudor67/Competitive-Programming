class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int K = nums.size();

        using TIII = tuple<int, int, int>;
        priority_queue<TIII, vector<TIII>, greater<TIII>> minHeap;
        int minNum = nums[0][0];
        int maxNum = nums[0][0];
        for(int i = 0; i < K; ++i){
            minHeap.push({nums[i][0], i, 0});
            minNum = min(minNum, nums[i][0]);
            maxNum = max(maxNum, nums[i][0]);
        }

        int resStart = minNum;
        int resEnd = maxNum;
        while((int)minHeap.size() == K){
            if(resEnd - resStart > maxNum - minNum){
                resStart = minNum;
                resEnd = maxNum;
            }

            int i = get<1>(minHeap.top());
            int j = get<2>(minHeap.top());
            minHeap.pop();

            if(j + 1 < (int)nums[i].size()){
                minHeap.push({nums[i][j + 1], i, j + 1});
                minNum = get<0>(minHeap.top());
                maxNum = max(maxNum, nums[i][j + 1]);
            }
        }

        return {resStart, resEnd};
    }
};