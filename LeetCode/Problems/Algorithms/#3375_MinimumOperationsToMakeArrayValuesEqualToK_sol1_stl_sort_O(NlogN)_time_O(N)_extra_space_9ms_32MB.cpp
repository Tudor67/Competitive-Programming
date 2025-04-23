class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        if(v[0] < k){
            return -1;
        }

        if(v[0] == k){
            return (int)v.size() - 1;
        }

        return (int)v.size();
    }
};