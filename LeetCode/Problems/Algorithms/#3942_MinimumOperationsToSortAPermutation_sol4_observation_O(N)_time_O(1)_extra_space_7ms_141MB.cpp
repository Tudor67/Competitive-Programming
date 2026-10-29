class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int INF = INT_MAX;

        int minOps = INF;

        // Case 1: nums[indexOfMin .. indexOfMin + N - 1] is strictly increasing
        //         when nums is viewed cyclically
        bool isIncreasing = true;
        int indexOfMin = min_element(nums.begin(), nums.end()) - nums.begin();
        for(int i = indexOfMin; i + 1 < indexOfMin + N; ++i){
            if(nums[i % N] >= nums[(i + 1) % N]){
                isIncreasing = false;
                break;
            }
        }

        if(isIncreasing){
            minOps = min(minOps, indexOfMin);
            minOps = min(minOps, N - indexOfMin + 2);
        }

        // Case 2: nums[indexOfMax .. indexOfMax + N - 1] is strictly decreasing
        //         when nums is viewed cyclically
        bool isDecreasing = true;
        int indexOfMax = max_element(nums.begin(), nums.end()) - nums.begin();
        for(int i = indexOfMax; i + 1 < indexOfMax + N; ++i){
            if(nums[i % N] <= nums[(i + 1) % N]){
                isDecreasing = false;
                break;
            }
        }

        if(isDecreasing){
            minOps = min(minOps, indexOfMax + 1);
            minOps = min(minOps, N - indexOfMax + 1);
        }

        if(minOps == INF){
            minOps = -1;
        }

        return minOps;
    }
};