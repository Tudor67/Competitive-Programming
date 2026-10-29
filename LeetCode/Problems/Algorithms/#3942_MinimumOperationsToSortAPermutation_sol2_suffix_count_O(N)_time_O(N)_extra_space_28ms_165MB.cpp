class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int INF = INT_MAX;

        vector<int> nums2(2 * N - 1);
        copy(nums.begin(), nums.end(), nums2.begin());
        copy(nums.begin(), nums.end() - 1, nums2.begin() + N);

        vector<int> suffCountIncNeighbors(2 * N - 1);
        for(int i = 2 * N - 3; i >= 0; --i){
            suffCountIncNeighbors[i] = (int)(nums2[i] < nums2[i + 1]) + suffCountIncNeighbors[i + 1];
        }

        int minOps = INF;
        for(int startIndex = 0; startIndex < N; ++startIndex){
            if(suffCountIncNeighbors[startIndex] - suffCountIncNeighbors[startIndex + N - 1] == N - 1){
                minOps = min(minOps, startIndex);
                minOps = min(minOps, N - startIndex + 2);
            }
            if(suffCountIncNeighbors[startIndex] - suffCountIncNeighbors[startIndex + N - 1] == 0){
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