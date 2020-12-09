class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        const int N = A.size();
        const int MAX_BIT = 30;
        
        unordered_set<int> distinctResults;
        vector<int> closestPos(MAX_BIT + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = N - 1; i >= 0; --i){
            int num = A[i];
            distinctResults.insert(num);
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if(closestPos[bit] != -1 && ((num >> bit) & 1) == 0){
                    minHeap.push({closestPos[bit], bit});
                }
            }
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    closestPos[bit] = i;
                }
            }
            while(!minHeap.empty()){
                int pos = minHeap.top().first;
                int bit = minHeap.top().second;
                minHeap.pop();
                num |= A[pos];
                distinctResults.insert(num);
            }
        }
        
        return distinctResults.size();
    }
};