class Solution {
private:
    static bool parityValComp(const int& LHS, const int& RHS){
        return pair<int, int>{LHS % 2, LHS} <
               pair<int, int>{RHS % 2, RHS};
    }
    
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end(), parityValComp);
        sort(target.begin(), target.end(), parityValComp);
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res += max(0, (nums[i] - target[i]) / 2);
        }
        
        return res;
    }
};