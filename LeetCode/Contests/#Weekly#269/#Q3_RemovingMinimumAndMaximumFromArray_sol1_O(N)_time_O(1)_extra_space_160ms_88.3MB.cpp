class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int N = nums.size();
        
        int idx1 = min_element(nums.begin(), nums.end()) - nums.begin();
        int idx2 = max_element(nums.begin(), nums.end()) - nums.begin();
        
        if(idx1 > idx2){
            swap(idx1, idx2);
        }
        
        return min({N - idx1, idx2 + 1, idx1 + 1 + N - idx2});
    }
};