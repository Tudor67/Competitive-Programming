class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);
        for(int i = 0, j = n - 1; i < j; ++i, --j){
            arr[i] = -(i + 1);
            arr[j] =  (i + 1);
        }
        return arr;
    }
};