class Solution {
public:
    double trimMean(vector<int>& arr) {
        const int N = arr.size();

        int extraElems = N / 20;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int elem: arr){
            minHeap.push(elem);
            maxHeap.push(elem);
            if((int)minHeap.size() > extraElems){
                minHeap.pop();
                maxHeap.pop();
            }
        }

        double totalSum = accumulate(arr.begin(), arr.end(), 0.0);
        double extraMinSum = 0;
        double extraMaxSum = 0;
        for(int i = 0; i < extraElems; ++i){
            extraMinSum += maxHeap.top(); maxHeap.pop();
            extraMaxSum += minHeap.top(); minHeap.pop();
        }

        return (totalSum - extraMinSum - extraMaxSum) / (N - 2 * extraElems);
    }
};