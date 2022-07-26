class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int N = nums1.size();
        
        map<int, int> count;
        for(int i = 0; i < N; ++i){
            int diff = abs(nums1[i] - nums2[i]);
            if(diff > 0){
                count[diff] += 1;
            }
        }
        
        set<pair<int, int>> diffCountSet;
        for(const pair<int, int>& P: count){
            int diff = P.first;
            int diffCount = P.second;
            diffCountSet.emplace(diff, diffCount);
        }
        
        int k = k1 + k2;
        while(!diffCountSet.empty() && k > 0){
            int diff = prev(diffCountSet.end())->first;
            int diffCount = prev(diffCountSet.end())->second;
            diffCountSet.erase(prev(diffCountSet.end()));
            
            int take = min(k, diffCount);
            diffCount -= take;
            k -= take;
            
            if(diff - 1 > 0 && take > 0){
                int prevDiffCount = take;
                if(!diffCountSet.empty() && prev(diffCountSet.end())->first == diff - 1){
                    prevDiffCount += prev(diffCountSet.end())->second;
                    diffCountSet.erase(prev(diffCountSet.end()));
                }
                diffCountSet.emplace(diff - 1, prevDiffCount);
            }
            
            if(diffCount > 0){
                diffCountSet.emplace(diff, diffCount);
            }
        }
        
        long long res = 0;
        for(const pair<int, int>& P: diffCountSet){
            int diff = P.first;
            int diffCount = P.second;
            
            res += (diffCount * 1LL * diff * 1LL * diff);
        }
        
        return res;
    }
};