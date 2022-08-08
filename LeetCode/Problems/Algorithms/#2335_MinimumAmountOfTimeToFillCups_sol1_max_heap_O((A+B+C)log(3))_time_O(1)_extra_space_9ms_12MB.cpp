class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < 3; ++i){
            if(amount[i] > 0){
                maxHeap.push(amount[i]);
            }
        }
        
        int res = 0;
        while((int)maxHeap.size() >= 2){
            int b = maxHeap.top(); maxHeap.pop();
            int a = maxHeap.top(); maxHeap.pop();
            
            res += 1;
            
            if(b - 1 > 0){
                maxHeap.push(b - 1);
            }
            if(a - 1 > 0){
                maxHeap.push(a - 1);
            }
        }
        
        if((int)maxHeap.size() == 1){
            res += maxHeap.top();
            maxHeap.pop();
        }
        
        return res;
    }
};