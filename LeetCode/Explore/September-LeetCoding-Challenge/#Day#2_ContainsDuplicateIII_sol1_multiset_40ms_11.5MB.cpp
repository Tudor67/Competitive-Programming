class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        bool found = false;
        
        multiset<long long> values;
        for(int i = 0; !found && i < nums.size(); ++i){
            // keep a sliding window of size k + 1
            if(i >= k + 1){
                values.erase(values.find(nums[i - k - 1]));
            }
            
            // search (case 1)
            multiset<long long>::iterator it = values.upper_bound(1LL * nums[i] + t);
            if(it != values.begin() && abs(*prev(it) - 1LL * nums[i]) <= t){
                found = true;
            }
            
            // search (case 2)
            it = values.upper_bound(1LL * nums[i] - t);
            if(it != values.end() && abs(*it - 1LL * nums[i]) <= t){
                found = true;
            }
            
            // update values
            values.insert(nums[i]);
        }
        
        return found;
    }
};