class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        const int N = arr.size();
        
        int l = 0;
        while(l + 1 < N && arr[l] < arr[l + 1]){
            l += 1;
        }
        
        int r = N - 1;
        while(0 <= r - 1 && arr[r - 1] > arr[r]){
            r -= 1;
        }
        
        return (l > 0 && l == r && r < N - 1);
    }
};