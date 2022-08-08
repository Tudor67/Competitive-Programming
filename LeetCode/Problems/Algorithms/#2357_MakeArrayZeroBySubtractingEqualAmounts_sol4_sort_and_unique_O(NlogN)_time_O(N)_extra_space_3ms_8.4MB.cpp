class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> v = nums;
        
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        if(v.front() == 0){
            v.erase(v.begin());
        }
        
        return v.size();
    }
};