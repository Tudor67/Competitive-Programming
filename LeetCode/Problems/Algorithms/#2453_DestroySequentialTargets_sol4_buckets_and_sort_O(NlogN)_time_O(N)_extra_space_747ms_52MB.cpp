class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        const int N = nums.size();
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](const int& LHS, const int& RHS){
                 return (pair<int, int>{nums[LHS] % space, nums[LHS]} >
                         pair<int, int>{nums[RHS] % space, nums[RHS]});
             });
        
        int resStart = 0;
        int resCount = 0;
        int currentCount = 0;
        for(int i = 0; i < N; ++i){
            currentCount += 1;
            if(i == N - 1 || (nums[p[i]] % space) != (nums[p[i + 1]] % space)){
                if((currentCount > resCount) ||
                   (currentCount == resCount && nums[p[i]] < resStart)){
                    resStart = nums[p[i]];
                    resCount = currentCount;
                }
                currentCount = 0;
            }
        }
        
        return resStart;
    }
};