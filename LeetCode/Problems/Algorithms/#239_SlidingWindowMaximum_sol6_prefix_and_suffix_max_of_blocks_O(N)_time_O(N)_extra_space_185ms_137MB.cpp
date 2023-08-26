class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> prefMax(N);
        for(int i = 0; i < N; ++i){
            if(i % k == 0){
                prefMax[i] = nums[i];
            }else{
                prefMax[i] = max(prefMax[i - 1], nums[i]);
            }
        }

        vector<int> suffMax(N);
        for(int i = N - 1; i >= 0; --i){
            if(i == N - 1 || i % k == k - 1){
                suffMax[i] = nums[i];
            }else{
                suffMax[i] = max(nums[i], suffMax[i + 1]);
            }
        }

        vector<int> res(N - k + 1);
        for(int i = 0; i + k - 1 < N; ++i){
            res[i] = max(suffMax[i], prefMax[i + k - 1]);
        }

        return res;
    }
};