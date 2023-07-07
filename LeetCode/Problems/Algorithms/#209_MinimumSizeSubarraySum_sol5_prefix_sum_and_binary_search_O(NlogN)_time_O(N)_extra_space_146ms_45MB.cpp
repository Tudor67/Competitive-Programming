class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        int minLen = INF;
        map<int, int> maxIndexOf;
        maxIndexOf[0] = -1;

        int prefixSum = 0;
        for(int i = 0; i < N; ++i){
            prefixSum += nums[i];
            map<int, int>::iterator it = maxIndexOf.upper_bound(prefixSum - target);
            if(it != maxIndexOf.begin()){
                minLen = min(minLen, i - prev(it)->second);
            }
            maxIndexOf[prefixSum] = i;
        }

        if(minLen != INF){
            return minLen;
        }

        return 0;
    }
};