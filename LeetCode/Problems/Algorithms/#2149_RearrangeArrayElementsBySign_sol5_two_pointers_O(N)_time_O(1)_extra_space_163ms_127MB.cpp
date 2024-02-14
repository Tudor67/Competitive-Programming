class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;
        res.reserve(N);

        int posIdx = 0;
        int negIdx = 0;
        for(int step = 1; step <= N / 2; ++step){
            while(nums[posIdx] < 0){
                posIdx += 1;
            }
            while(nums[negIdx] > 0){
                negIdx += 1;
            }
            res.insert(res.end(), {nums[posIdx], nums[negIdx]});
            posIdx += 1;
            negIdx += 1;
        }

        return res;
    }
};