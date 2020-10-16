class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int K) {
        vector<double> medians;
        multiset<int> values(nums.begin(), nums.begin() + K - 1);
        for(int i = K - 1; i < nums.size(); ++i){
            values.insert(nums[i]);
            if(i >= K){
                values.erase(values.find(nums[i - K]));
            }
            double median = ((double)*next(values.begin(), K / 2) + (double)*prev(values.end(), K / 2 + 1)) / 2.0;
            medians.push_back(median);
        }
        return medians;
    }
};