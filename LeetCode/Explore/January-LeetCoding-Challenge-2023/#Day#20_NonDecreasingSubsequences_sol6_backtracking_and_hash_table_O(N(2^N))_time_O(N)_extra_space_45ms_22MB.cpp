class Solution {
private:
    void back(int startPos, vector<int>& nums, vector<int>& subseq, vector<vector<int>>& res){
        const int N = nums.size();

        if((int)subseq.size() >= 2){
            res.push_back(subseq);
        }

        unordered_set<int> usedNums;
        for(int pos = startPos; pos < N; ++pos){
            if(usedNums.count(nums[pos])){
                // avoid duplicates
                continue;
            }
            if(subseq.empty() || subseq.back() <= nums[pos]){
                usedNums.insert(nums[pos]);
                subseq.push_back(nums[pos]);
                back(pos + 1, nums, subseq, res);
                subseq.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int N = nums.size();

        vector<int> subseq;
        vector<vector<int>> res;
        back(0, nums, subseq, res);

        return res;
    }
};