class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        
        unordered_map<int, int> count;
        for(int elem: arr){
            count[elem] += 1;
        }
        
        priority_queue<int> maxHeap;
        for(const pair<int, int>& P: count){
            int elemCount = P.second;
            maxHeap.push(elemCount);
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