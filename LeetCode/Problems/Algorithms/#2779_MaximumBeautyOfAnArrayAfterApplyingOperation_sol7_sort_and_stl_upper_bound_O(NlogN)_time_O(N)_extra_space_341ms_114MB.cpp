class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> starts(N);
        vector<int> ends(N);
        for(int i = 0; i < N; ++i){
            starts[i] = nums[i] - k;
            ends[i] = nums[i] + k;
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int maxBeauty = 0;
        for(int i = 0; i < N; ++i){
            for(int num: {nums[i] - k, nums[i] + k}){
                int startPoints = upper_bound(starts.begin(), starts.end(), num) - starts.begin();
                int endPoints = upper_bound(ends.begin(), ends.end(), num - 1) - ends.begin();
                int overlaps = startPoints - endPoints;
                maxBeauty = max(maxBeauty, overlaps);
            }
        }

        return maxBeauty;
    }
};