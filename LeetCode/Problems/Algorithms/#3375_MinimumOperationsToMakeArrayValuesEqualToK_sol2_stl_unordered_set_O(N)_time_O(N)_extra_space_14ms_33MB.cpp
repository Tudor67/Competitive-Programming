class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int MIN_NUM = *min_element(nums.begin(), nums.end());

        if(MIN_NUM < k){
            return -1;
        }

        unordered_set<int> s(nums.begin(), nums.end());
        if(MIN_NUM == k){
            return (int)s.size() - 1;
        }

        return (int)s.size();
    }
};