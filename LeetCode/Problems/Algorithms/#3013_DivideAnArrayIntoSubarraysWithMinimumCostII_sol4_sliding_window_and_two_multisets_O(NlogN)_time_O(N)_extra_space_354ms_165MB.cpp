class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int N = nums.size();

        long long minCost = accumulate(nums.begin(), nums.end(), (long long)0);
        long long lSum = 0;
        multiset<int> lMS;
        multiset<int> rMS;

        for(int i = N - 1; i >= 1; --i){
            int j = i + dist + 1;
            if(j < N){
                auto it = rMS.find(nums[j]);
                if(it != rMS.end()){
                    rMS.erase(it);
                }else{
                    it = lMS.find(nums[j]);
                    lSum -= *it;
                    lMS.erase(it);
                }
            }

            lSum += nums[i];
            lMS.insert(nums[i]);
            if((!rMS.empty() && *prev(lMS.end()) > *rMS.begin()) || ((int)lMS.size() == k)){
                auto it = prev(lMS.end());
                rMS.insert(*it);
                lSum -= *it;
                lMS.erase(it);
            }

            if(!rMS.empty() && (int)lMS.size() == k - 2){
                auto it = rMS.begin();
                lSum += *it;
                lMS.insert(*it);
                rMS.erase(it);
            }

            if((int)lMS.size() == k - 1){
                long long currCost = nums[0] + lSum;
                minCost = min(minCost, currCost);
            }
        }

        return minCost;
    }
};