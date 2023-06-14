class Solution {
private:
    void updateRes(vector<string>& res, pair<int, int>& r){
        if(r.first == r.second){
            res.push_back(to_string(r.first));
        }else{
            res.push_back(to_string(r.first) + "->" + to_string(r.second));
        }
    }

public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int N = nums.size();

        if(nums.empty()){
            return {};
        }

        vector<string> res;
        pair<int, int> prevRange = {nums[0], nums[0]};
        for(int i = 1; i < N; ++i){
            if(prevRange.second + 1 == nums[i]){
                prevRange.second += 1;
            }else{
                updateRes(res, prevRange);
                prevRange = {nums[i], nums[i]};
            }
        }

        updateRes(res, prevRange);

        return res;
    }
};