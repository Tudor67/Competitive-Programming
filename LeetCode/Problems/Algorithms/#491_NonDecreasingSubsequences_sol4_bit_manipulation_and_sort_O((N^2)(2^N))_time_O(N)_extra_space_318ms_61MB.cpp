class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;

        vector<vector<int>> res;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            vector<int> subseq;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    if(subseq.empty() || subseq.back() <= nums[bit]){
                        subseq.push_back(nums[bit]);
                    }else{
                        subseq.clear();
                        break;
                    }
                }
            }
            if((int)subseq.size() >= 2){
                res.push_back(subseq);
            }
        }

        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());

        return res;
    }
};