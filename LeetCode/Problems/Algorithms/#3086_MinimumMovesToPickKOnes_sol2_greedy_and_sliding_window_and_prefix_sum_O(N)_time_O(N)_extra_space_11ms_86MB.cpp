class Solution {
private:
    long long getRangeSum(vector<long long>& prefSum, int l, int r){
        if(l > r) return 0;
        if(l == 0) return prefSum[r];
        return prefSum[r] - prefSum[l - 1];
    }

public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        const int N = nums.size();
        const long long INF = 1e18;

        // Case 0: special case (only zeros)
        if(count(nums.begin(), nums.end(), 1) == 0){
            return 2 * k;
        }

        // Case 1: try to collect k ones from a window of size at most 3: [aliceIndex - 1, aliceIndex + 1]
        //         using at most maxChanges additional operations of type 1 and maxChanges operations of type 2
        long long res = INF;
        for(int i = 0; i < N; ++i){
            int collectedOnes = 0;
            long long cost = 0;
            for(int j = max(0, i - 1); j <= min(i + 1, N - 1); ++j){
                if(nums[j] == 1 && collectedOnes < k){
                    collectedOnes += 1;
                    cost += abs(i - j);
                }
            }
            if(k - collectedOnes <= maxChanges){
                res = min(res, cost + (k - collectedOnes) * 2);
            }
        }

        if(res != INF){
            return res;
        }

        // Case 2: collect maxChanges ones:
        //                 use maxChanges operations of type 1 and maxChanges operations of type 2
        //         collect the remaining (k - maxChanges) ones:
        //                 store the indices of ones in a separate vector indices
        //                 compute the minimum cost to collect all ones from indices[i .. i + k - maxChanges - 1]
        //                 the minimum cost is the sum of distances between indices[medianIndex] and
        //                                                                  indices[i .. i + k - maxChanges - 1]
        vector<int> indices;
        for(int i = 0; i < N; ++i){
            if(nums[i] == 1){
                indices.push_back(i);
            }
        }

        const int M = indices.size();
        const int TARGET_ONES = k - maxChanges;
        vector<long long> prefDist(M);
        prefDist[0] = indices[0];
        for(int i = 1; i < M; ++i){
            prefDist[i] = prefDist[i - 1] + indices[i];
        }

        for(int i = 0; i + TARGET_ONES - 1 < M; ++i){
            int j = i + TARGET_ONES - 1;
            int mid = (i + j) / 2;
            long long leftCost = (mid - i) * (long long)indices[mid] - getRangeSum(prefDist, i, mid - 1);
            long long rightCost = getRangeSum(prefDist, mid + 1, j) - (j - mid) * (long long)indices[mid];
            long long maxChangesCost = 2 * maxChanges;
            res = min(res, maxChangesCost + leftCost + rightCost);
        }

        return res;
    }
};