class Solution {
private:
    bool isValid(vector<int>& sortedNums, int p, int maxDist){
        const int N = sortedNums.size();
        int i = 0;
        while(i + 1 < N && p >= 1){
            if(sortedNums[i + 1] - sortedNums[i] <= maxDist){
                p -= 1;
                i += 2;
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
        int r = sortedNums.back() - sortedNums.front();
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(sortedNums, p, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};