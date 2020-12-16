class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0;
        while(l + 1 < arr.size() && arr[l] < arr[l + 1]){
            l += 1;
        }
        
        int r = l;
        while(r + 1 < arr.size() && arr[r] > arr[r + 1]){
            r += 1;
        }
        
        return (arr.size() >= 3 && 1 <= l && l + 1 < arr.size() && r + 1 == arr.size());
    }
};