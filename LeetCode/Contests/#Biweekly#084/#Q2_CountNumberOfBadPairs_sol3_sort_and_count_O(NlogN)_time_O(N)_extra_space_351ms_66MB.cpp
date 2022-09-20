class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const long long N = nums.size();
        
        vector<int> diffs(N);
        for(int i = 0; i < N; ++i){
            diffs[i] = nums[i] - i;
        }
        
        sort(diffs.begin(), diffs.end());
        
        long long totalPairs = (N - 1) * N / 2;
        long long goodPairs = 0;
        long long sameDiffs = 1;
        for(int i = 0; i < N; ++i){
            if(i < N - 1 && diffs[i] == diffs[i + 1]){
                sameDiffs += 1;
            }else{
                goodPairs += (sameDiffs - 1) * sameDiffs / 2;
                sameDiffs = 1;
            }
        }
        
        return totalPairs - goodPairs;
    }
};