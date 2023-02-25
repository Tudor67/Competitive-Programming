class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        const int N = gifts.size();
        
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        for(int i = 1; i <= k; ++i){
            int num = maxHeap.top();
            maxHeap.pop();
            maxHeap.push((int)sqrt(num));
        }
        
        long long res = 0;
        while(!maxHeap.empty()){
            res += maxHeap.top();
            maxHeap.pop();
        }
        
        return res;
    }
};