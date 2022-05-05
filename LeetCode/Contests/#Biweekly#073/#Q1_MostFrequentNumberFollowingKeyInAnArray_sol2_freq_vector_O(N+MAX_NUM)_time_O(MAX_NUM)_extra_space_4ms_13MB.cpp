class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> count(MAX_NUM + 1);
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] == key){
                count[nums[i + 1]] += 1;
            }
        }
        
        return max_element(count.begin(), count.end()) - count.begin();
    }
};