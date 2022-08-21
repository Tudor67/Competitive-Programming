class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        priority_queue<int> maxHeap;
        int elemCount = 0;
        for(int i = 0; i < N; ++i){
            elemCount += 1;
            if(i == N - 1 || sortedArr[i] != sortedArr[i + 1]){
                maxHeap.push(elemCount);
                elemCount = 0;
            }
        }
        
        int uniqueRemoved = 0;
        int totalRemoved = 0;
        while(totalRemoved < N / 2){
            int elemCount = maxHeap.top();
            maxHeap.pop();
            
            uniqueRemoved += 1;
            totalRemoved += elemCount;
        }
        
        return uniqueRemoved;
    }
};