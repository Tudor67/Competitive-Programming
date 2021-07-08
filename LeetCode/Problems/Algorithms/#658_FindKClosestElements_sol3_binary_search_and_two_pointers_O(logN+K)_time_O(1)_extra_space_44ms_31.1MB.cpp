class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        vector<int> closestElements(k);
        int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        int i = 0;
        int j = k - 1;
        while(i <= j){
            if(l >= 0 && (r == N || abs(arr[l] - x) <= abs(arr[r] - x))){
                closestElements[i++] = arr[l--];
            }else{
                closestElements[j--] = arr[r++];
            }
        }
        reverse(closestElements.begin(), closestElements.begin() + i);
        reverse(closestElements.begin() + i, closestElements.end());
        return closestElements;
    }
};