class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> res(N);
        int l = -1;
        int r = N;
        for(int num: nums){
            if(num % 2 == 0){
                res[++l] = num;
            }else{
                res[--r] = num;
            }
        }
        
        return res;
    }
};