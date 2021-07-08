class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            maxHeap.push({abs(arr[i] - x), i});
            if((int)maxHeap.size() == k + 1){
                maxHeap.pop();
            }
        }
        
        int r = -1;
        while(!maxHeap.empty()){
            int pos = maxHeap.top().second;
            maxHeap.pop();
            r = max(pos, r);
        }
        
        vector<int> closestElements(arr.begin() + r + 1 - k, arr.begin() + r + 1);
        
        return closestElements;
    }
};