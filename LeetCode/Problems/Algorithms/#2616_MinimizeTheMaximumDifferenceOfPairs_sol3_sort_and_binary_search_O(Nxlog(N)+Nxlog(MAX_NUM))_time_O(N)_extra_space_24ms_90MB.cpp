class Solution {
private:
    int countValidPairs(vector<int>& sortedNums, int maxDiffThreshold){
        const int N = sortedNums.size();

        int validPairs = 0;
        int i = 0;
        while(i + 1 < N){
            if(sortedNums[i + 1] - sortedNums[i] <= maxDiffThreshold){
                validPairs += 1;
                i += 2;
            }else{
                i += 1;
            }
        }

        return validPairs;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int l = 0;
        int r = sortedNums.back() - sortedNums.front();
        while(l != r){
            int mid = (l + r) / 2;
            if(countValidPairs(sortedNums, mid) < p){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};