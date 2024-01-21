class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();
        
        map<int, int> fl;
        map<int, int> fr;
        for(int num: nums){
            fr[num] += 1;
        }
        
        set<pair<int, int>> sl;
        set<pair<int, int>> sr;
        for(const pair<const int, int>& P: fr){
            sr.insert({P.second, P.first});
        }
        
        for(int i = 0; i < N - 1; ++i){
            sr.erase({fr[nums[i]], nums[i]});
            fr[nums[i]] -= 1;
            sr.insert({fr[nums[i]], nums[i]});
            
            sl.erase({fl[nums[i]], nums[i]});
            fl[nums[i]] += 1;
            sl.insert({fl[nums[i]], nums[i]});
            
            int lSize = i + 1;
            int rSize = N - lSize;
            
            if(sl.rbegin()->first * 2 > lSize && sr.rbegin()->first * 2 > rSize){
                if(sl.rbegin()->second == sr.rbegin()->second){
                    return i;
                }
            }
        }

        return -1;
    }
};