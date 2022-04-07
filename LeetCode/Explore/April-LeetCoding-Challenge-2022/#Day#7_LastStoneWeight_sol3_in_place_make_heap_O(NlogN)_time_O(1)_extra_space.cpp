class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        
        make_heap(stones.begin(), stones.begin() + size);
        
        while(size >= 2){
            int y = stones.front();
            pop_heap(stones.begin(), stones.begin() + size);
            size -= 1;
            
            int x = stones.front();
            pop_heap(stones.begin(), stones.begin() + size);
            size -= 1;
            
            if(x != y){
                stones[size] = y - x;
                size += 1;
                push_heap(stones.begin(), stones.begin() + size);
            }
        }
        
        if(size == 1){
            return stones.front();
        }
        
        return 0;
    }
};