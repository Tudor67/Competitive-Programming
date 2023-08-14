class Solution {
private:
    bool isPossible(vector<int>& sortedNums, int p, int maxDist){
        const int N = sortedNums.size();

        int i = 0;
        while(i + 1 < N && p > 0){
            if(sortedNums[i + 1] - sortedNums[i] <= maxDist){
                i += 2;
                p -= 1;
            }else{
                i += 1;
            }
        }

        return (p <= 0);
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int l = 0;
        int r = sortedNums[N - 1] - sortedNums[0];
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(sortedNums, p, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};