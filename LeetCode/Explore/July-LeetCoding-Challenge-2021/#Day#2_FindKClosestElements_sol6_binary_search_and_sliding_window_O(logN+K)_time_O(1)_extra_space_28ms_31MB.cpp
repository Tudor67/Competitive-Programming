class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        
        // compute pos: position of closest (to the left) element to x
        int pos = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        
        // compute distance of range [l, r], where l = max(0, pos - k + 1) and r = l + k - 1
        // distance = abs(arr[l] - x) + abs(arr[l + 1] - x) + ... + abs(arr[r] - x)
        int l = max(0, pos - k + 1);
        int distance = 0;
        for(int r = l; r <= l + k - 1; ++r){
            distance += abs(arr[r] - x);
        }
        
        // select the range [r - k + 1, r] with min distance
        int minR = l + k - 1;
        int minDistance = distance;
        for(int r = l + k; r <= min(N - 1, pos + k); ++r){
            distance -= abs(arr[r - k] - x);
            distance += abs(arr[r] - x);
            if(distance < minDistance){
                minDistance = distance;
                minR = r;
            }
        }
        
        vector<int> closestElements(arr.begin() + minR + 1 - k, arr.begin() + minR + 1);
        
        return closestElements;
    }
};