class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res(N);

        int l = 0;
        int r = N - 1;
        for(int num: nums){
            if(num % 2 == 0){
                res[l] = num;
                l += 1;
            }else{
                res[r] = num;
                r -= 1;
            }
        }

        return res;
    }
};