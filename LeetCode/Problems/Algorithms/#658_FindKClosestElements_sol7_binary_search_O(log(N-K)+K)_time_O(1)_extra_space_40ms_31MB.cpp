class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search the leftmost l of arr[l], arr[l + 1], ... , arr[l + k - 1]
        // which covers the closest k elements to x
        const int N = arr.size();
        int l = 0;
        int r = N - k;
        while(l != r){
            int mid = (l + r) / 2;
            if(arr[mid] == arr[mid + k]){
                if(arr[mid] < x){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }else if(abs(arr[mid] - x) <= abs(arr[mid + k] - x)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};