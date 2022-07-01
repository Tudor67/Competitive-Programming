class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        
        priority_queue<int> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);
        
        while((int)maxHeap.size() >= 2){
            int y = maxHeap.top();
            maxHeap.pop();
            
            int x = maxHeap.top();
            maxHeap.pop();
            
            score += 1;
            
            if(x >= 2){
                maxHeap.push(x - 1);
            }
            if(y >= 2){
                maxHeap.push(y - 1);
            }
        }
        
        return score;
    }
};