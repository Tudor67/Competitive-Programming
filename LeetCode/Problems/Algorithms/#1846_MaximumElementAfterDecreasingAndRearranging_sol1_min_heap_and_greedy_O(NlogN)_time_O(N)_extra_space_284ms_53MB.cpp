class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        const int N = arr.size();

        int maxElem = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
        while(!minHeap.empty()){
            while(!minHeap.empty() && maxElem + 1 > minHeap.top()){
                minHeap.pop();
            }
            if(!minHeap.empty()){
                minHeap.pop();
                maxElem += 1;
            }
        }
        
        return maxElem;
    }
};