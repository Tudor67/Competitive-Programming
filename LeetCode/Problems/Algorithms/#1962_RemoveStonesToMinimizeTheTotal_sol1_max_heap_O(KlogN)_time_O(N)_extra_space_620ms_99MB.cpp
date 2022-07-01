class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        const int N = piles.size();
        
        priority_queue<int> maxHeap(piles.begin(), piles.end());
        int sum = accumulate(piles.begin(), piles.end(), 0);
        while(k > 0 && !maxHeap.empty()){
            int stones = maxHeap.top();
            maxHeap.pop();
            
            sum -= (stones / 2);
            stones -= (stones / 2);
            
            if(stones >= 2){
                maxHeap.push(stones);
            }
            
            k -= 1;
        }
        
        return sum;
    }
};