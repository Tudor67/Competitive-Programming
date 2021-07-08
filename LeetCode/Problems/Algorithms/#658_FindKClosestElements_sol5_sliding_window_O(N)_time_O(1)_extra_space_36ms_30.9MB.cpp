class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        
        // compute distance of range [0, k - 1]
        // distance = abs(arr[0] - x) + abs(arr[1] - x) + ... + abs(arr[k - 1] - x)
        int distance = 0;
        for(int r = 0; r <= k - 1; ++r){
            distance += abs(arr[r] - x);
        }
        
        // select the range [r - k + 1, r] with min distance
        int minR = k - 1;
        int minDistance = distance;
        for(int r = k; r < N; ++r){
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