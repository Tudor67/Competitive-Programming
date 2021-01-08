class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int N = arr.size();
        arr.push_back(2001);
        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            int missing = arr[mid] - mid - 1;
            if(missing >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r + k;
    }
};