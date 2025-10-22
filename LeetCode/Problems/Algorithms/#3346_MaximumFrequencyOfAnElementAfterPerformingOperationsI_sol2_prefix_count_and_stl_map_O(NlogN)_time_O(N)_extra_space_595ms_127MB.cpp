class Solution {
private:
    int getRangeCount(map<int, int>& prefCount, int l, int r){
        int rangeCount = 0;

        auto rIt = prefCount.upper_bound(r);
        if(rIt != prefCount.begin()){
            rangeCount += prev(rIt)->second;
        }

        auto lIt = prefCount.lower_bound(l);
        if(lIt != prefCount.begin()){
            rangeCount -= prev(lIt)->second;
        }

        return rangeCount;
    }

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> prefCount;
        for(int num: nums){
            prefCount[num] += 1;
        }

        for(auto it = next(prefCount.begin()); it != prefCount.end(); it = next(it)){
            it->second += prev(it)->second;
        }

        int res = 0;
        for(auto& [num, _]: prefCount){
            for(int target: {num - k, num, num + k}){
                int count0 = getRangeCount(prefCount, target, target);
                int count01 = getRangeCount(prefCount, target - k, target + k);
                res = max(res, count0 + min(count01 - count0, numOperations));
            }
        }

        return res;
    }
};