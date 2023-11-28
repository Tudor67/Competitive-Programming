class Solution {
private:
    bool canFormAnArithmeticSequence(vector<int>& nums, const int L, const int R){
        vector<int> v(nums.begin() + L, nums.begin() + R + 1);
        
        sort(v.begin(), v.end());

        const int V_SIZE = v.size();
        for(int i = 2; i < V_SIZE; ++i){
            if(v[1] - v[0] != v[i] - v[i - 1]){
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