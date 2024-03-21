class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        unordered_map<int, int> firstIndexOf;
        firstIndexOf[0] = -1;

        int prefBalance = 0;
        for(int i = 0; i < N; ++i){
            prefBalance += 2 * nums[i] - 1;
            if(firstIndexOf.count(prefBalance)){
                res = max(res, i - firstIndexOf[prefBalance]);
            }else{
                firstIndexOf[prefBalance] = i;
            }
        }

        return res;
    }
};