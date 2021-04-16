class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int N = arr.size();
        int l = 1;
        int r = N - 2;
        while(l != r){
            int mid = (l + r) / 2;
            if(arr[mid] < arr[mid + 1]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};