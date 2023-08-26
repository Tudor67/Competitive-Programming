class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> res(N - k + 1);

        multiset<int> wMultiset;
        for(int i = 0; i < N; ++i){
            wMultiset.insert(nums[i]);
            if(i >= k){
                wMultiset.erase(wMultiset.find(nums[i - k]));
            }
            if(i >= k - 1){
                res[i - (k - 1)] = *wMultiset.rbegin();
            }
        }

        return res;
    }
};