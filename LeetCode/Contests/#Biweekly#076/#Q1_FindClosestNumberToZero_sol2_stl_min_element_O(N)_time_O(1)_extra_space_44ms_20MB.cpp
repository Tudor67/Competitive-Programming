class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end(),
                            [](const int& LHS, const int& RHS){
                                return (abs(LHS) < abs(RHS) || (abs(LHS) == abs(RHS) && LHS > RHS));
                            });
    }
};