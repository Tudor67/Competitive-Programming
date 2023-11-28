class Solution {
private:
    bool canFormAnArithmeticSequence(vector<int>& nums, const int L, const int R){
        const int RANGE_SIZE = R - L + 1;
        const int MIN_NUM = *min_element(nums.begin() + L, nums.begin() + R + 1);
        const int MAX_NUM = *max_element(nums.begin() + L, nums.begin() + R + 1);
        const int TARGET_DIFF = (MAX_NUM - MIN_NUM) / (RANGE_SIZE - 1);

        if((MAX_NUM - MIN_NUM) % (RANGE_SIZE - 1) != 0){
            return false;
        }

        unordered_set<int> numsSet(nums.begin() + L, nums.begin() + R + 1);
        for(int num = MIN_NUM; num < MAX_NUM; num += TARGET_DIFF){
            if(!numsSet.count(num)){
                return false;
            }
        }

        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int N = nums.size();
        const int M = l.size();

        vector<bool> answer(M, false);
        for(int i = 0; i < M; ++i){
            answer[i] = canFormAnArithmeticSequence(nums, l[i], r[i]);
        }

        return answer;
    }
};