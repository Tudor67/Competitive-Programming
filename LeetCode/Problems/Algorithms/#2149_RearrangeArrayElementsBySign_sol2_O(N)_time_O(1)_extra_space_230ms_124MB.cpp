class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> res(N);
        int posIdx = 0;
        int negIdx = 1;
        for(int num: nums){
            if(num > 0){
                res[posIdx] = num;
                posIdx += 2;
            }else{
                res[negIdx] = num;
                negIdx += 2;
            }
        }
        
        return res;
    }
};