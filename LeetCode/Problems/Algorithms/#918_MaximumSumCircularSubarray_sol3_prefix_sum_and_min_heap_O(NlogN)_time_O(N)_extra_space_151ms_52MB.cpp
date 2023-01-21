class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int N = nums.size();

        int res = nums[0];
        int prefSum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prefSumIndexMinHeap;
        prefSumIndexMinHeap.push({0, -1});

        for(int i = 0; i < 2 * N; ++i){
            prefSum += nums[i % N];

            while(i - prefSumIndexMinHeap.top().second > N){
                prefSumIndexMinHeap.pop();
            }
            
            res = max(res, prefSum - prefSumIndexMinHeap.top().first);

            prefSumIndexMinHeap.push({prefSum, i});
        }

        return res;
    }
};