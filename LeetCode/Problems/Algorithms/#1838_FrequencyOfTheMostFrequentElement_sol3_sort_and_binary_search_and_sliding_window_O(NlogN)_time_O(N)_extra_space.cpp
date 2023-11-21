class Solution {
private:
    bool isValid(vector<int>& sortedNums, int k, long long wSize){
        const int N = sortedNums.size();

        long long wSum = 0;
        for(int i = 0; i < N; ++i){
            wSum += sortedNums[i];
            if(i >= wSize){
                wSum -= sortedNums[i - wSize];
            }
            if(i >= wSize - 1){
                if(sortedNums[i] * wSize - wSum <= k){
                    return true;
                }
            }
        }

        return false;
    }

public:
    int maxFrequency(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(sortedNums, k, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};