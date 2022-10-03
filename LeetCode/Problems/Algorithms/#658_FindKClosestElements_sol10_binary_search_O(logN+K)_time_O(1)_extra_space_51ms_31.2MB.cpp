class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        int l = 0;
        int r = N - k;
        while(l != r){
            int mid = (l + r) / 2;
            if(arr[mid] + arr[mid + k] < 2 * x){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};