class Solution {
private:
    int countPairsWithDistanceAtMostThr(vector<int>& sortedNums, const int MAX_DIST_THRESHOLD){
        const int N = sortedNums.size();

        int pairs = 0;
        for(int i = 0, j = 0; i < N; ++i){
            while(j < N && sortedNums[j] - sortedNums[i] <= MAX_DIST_THRESHOLD){
                j += 1;
            }
            pairs += (j - i - 1);
        }

        return pairs;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int l = 0;
        int r = sortedNums.back() - sortedNums.front();
        while(l != r){
            int mid = (l + r) / 2;
            if(countPairsWithDistanceAtMostThr(sortedNums, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};