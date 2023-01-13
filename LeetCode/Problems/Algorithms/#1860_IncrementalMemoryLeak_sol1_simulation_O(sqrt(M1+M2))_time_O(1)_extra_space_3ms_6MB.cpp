class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while(i <= max(memory1, memory2)){
            if(memory1 >= memory2){
                memory1 -= i;
            }else{
                memory2 -= i;
            }
            i += 1;
        }
        return {i, memory1, memory2};
    }
};