class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        unordered_map<int, int> rightOf;
        for(int i = 0; i < N; ++i){
            rightOf[nums[i]] = i;
        }

        int res = 1;
        int r = rightOf[nums[0]];
        for(int i = 1; i < N; ++i){
            if(r < i){
                res = (res * 2) % MODULO;
            }
            r = max(r, rightOf[nums[i]]);
        }

        return res;
    }
};