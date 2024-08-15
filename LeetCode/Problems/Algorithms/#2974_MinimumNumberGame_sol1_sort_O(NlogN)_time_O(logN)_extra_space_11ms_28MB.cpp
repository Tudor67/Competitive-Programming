class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> res = nums;
        sort(res.begin(), res.end());
        
        for(int i = 0; i < N; i += 2){
            swap(res[i], res[i + 1]);
        }
        
        return res;
    }
};