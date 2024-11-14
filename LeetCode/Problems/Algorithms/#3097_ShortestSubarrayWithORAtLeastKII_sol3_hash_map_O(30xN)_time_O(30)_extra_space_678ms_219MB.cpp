class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;

        int minLen = INF;
        unordered_map<int, int> prevStartOf;
        unordered_map<int, int> startOf;

        for(int i = 0; i < N; ++i){
            startOf.clear();
            for(const auto& [prevSubarrayOR, startIndex]: prevStartOf){
                int subarrayOR = prevSubarrayOR | nums[i];
                if(startOf.count(subarrayOR)){
                    startOf[subarrayOR] = max(startOf[subarrayOR], startIndex);
                }else{
                    startOf[subarrayOR] = startIndex;
                }
            }
            startOf[nums[i]] = i;

            for(const auto& [subarrayOR, startIndex]: startOf){
                if(subarrayOR >= k){
                    minLen = min(minLen, i - startIndex + 1);
                }
            }

            prevStartOf = startOf;
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};