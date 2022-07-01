class Solution {
private:
    static bool comp(const string& LHS, const string& RHS){
        if(LHS.length() == RHS.length()){
            return (LHS < RHS);
        }
        return (LHS.length() < RHS.length());
    }
    
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        const int N = nums.size();
        sort(nums.begin(), nums.end(), comp);
        return nums[N - k];
    }
};