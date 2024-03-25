class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        const int N = nums.size();

        vector<int> ans;
        vector<int> seen;
        int k = 0;
        
        for(int num: nums){
            if(num > 0){
                seen.push_back(num);
                k = 0;
            }else{
                k += 1;
                if(k <= (int)seen.size()){
                    ans.push_back(seen[(int)seen.size() - k]);
                }else{
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};