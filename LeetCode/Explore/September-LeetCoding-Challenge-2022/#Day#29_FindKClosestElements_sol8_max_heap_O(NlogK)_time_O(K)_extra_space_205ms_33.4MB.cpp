class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            maxHeap.emplace(abs(arr[i] - x), i);
            if((int)maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        int lastPos = 0;
        while(!maxHeap.empty()){
            int pos = maxHeap.top().second;
            maxHeap.pop();
            
            lastPos = max(lastPos, pos);
        }
        
        return vector<int>(arr.begin() + lastPos + 1 - k, arr.begin() + lastPos + 1);
    }
};