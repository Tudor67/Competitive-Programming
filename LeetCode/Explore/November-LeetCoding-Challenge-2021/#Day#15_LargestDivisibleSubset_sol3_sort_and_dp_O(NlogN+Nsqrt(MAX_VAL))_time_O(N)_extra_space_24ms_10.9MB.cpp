class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        // At step i:
        // maxSize[nums[i]]: size of the largest valid subset from nums[0 .. i] which ends with nums[i]
        unordered_map<int, int> maxSize;
        unordered_map<int, int> prev;
        for(int i = 0; i < N; ++i){
            if(!maxSize.count(nums[i])){
                maxSize[nums[i]] = 1;
                prev[nums[i]] = nums[i];
            }
            for(int x = 1; x * x <= nums[i]; ++x){
                if(nums[i] % x == 0){
                    for(int divisor: {x, nums[i] / x}){
                        if(divisor != nums[i] && maxSize.count(divisor) && maxSize[divisor] + 1 > maxSize[nums[i]]){
                            maxSize[nums[i]] = maxSize[divisor] + 1;
                            prev[nums[i]] = divisor;
                        }
                    }
                }
            }
        }
        
        int num = -1;
        int size = 0;
        for(const pair<int, int>& P: maxSize){
            int currentNum = P.first;
            int currentSize = P.second;
            if(currentSize > size){
                num = currentNum;
                size = currentSize;
            }
        }
        
        vector<int> numsSubset;
        while(num != prev[num]){
            numsSubset.push_back(num);
            num = prev[num];
        }
        numsSubset.push_back(num);
        
        return numsSubset;
    }
};