class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int N = nums.size();

        if(k == 1){
            return nums;
        }

        vector<int> res;
        res.reserve(N - k + 1);

        int sortedConsecutiveNeighbors = 0;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] + 1 == nums[i]){
                sortedConsecutiveNeighbors += 1;
            }
            if(i >= k && nums[i - k] + 1 == nums[i - k + 1]){
                sortedConsecutiveNeighbors -= 1;
            }
            if(i >= k - 1){
                if(sortedConsecutiveNeighbors == k - 1){
                    res.push_back(nums[i]);
                }else{
                    res.push_back(-1);
                }
            }
        }

        return res;
    }
};