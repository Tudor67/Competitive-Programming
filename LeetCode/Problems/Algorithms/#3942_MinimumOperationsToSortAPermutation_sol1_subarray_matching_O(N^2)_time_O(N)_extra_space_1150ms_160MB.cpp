class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int INF = INT_MAX;

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);

        vector<int> nums2(2 * N - 1);
        copy(nums.begin(), nums.end(), nums2.begin());
        copy(nums.begin(), nums.end() - 1, nums2.begin() + N);

        int minOps = INF;
        for(int startIndex = 0; startIndex < N; ++startIndex){
            if(equal(nums2.begin() + startIndex, nums2.begin() + startIndex + N, p.begin())){
                minOps = min(minOps, startIndex);
                minOps = min(minOps, N - startIndex + 2);
            }
            if(equal(nums2.begin() + startIndex, nums2.begin() + startIndex + N, p.rbegin())){
                minOps = min(minOps, startIndex + 1);
                minOps = min(minOps, N - startIndex + 1);
            }
        }

        if(minOps == INF){
            minOps = -1;
        }

        return minOps;
    }
};