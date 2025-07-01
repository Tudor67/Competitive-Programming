class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int N = nums.size();

        vector<int> validIndices;

        int l = 0;
        int r = 0;
        int wKeyCount = 0;
        for(int i = 0; i < N; ++i){
            while(l < max(i - k, 0)){
                wKeyCount -= (int)(nums[l] == key);
                l += 1;
            }
            while(r <= min(N - 1, i + k)){
                wKeyCount += (int)(nums[r] == key);
                r += 1;
            }
            if(wKeyCount >= 1){
                validIndices.push_back(i);
            }
        }

        return validIndices;
    }
};