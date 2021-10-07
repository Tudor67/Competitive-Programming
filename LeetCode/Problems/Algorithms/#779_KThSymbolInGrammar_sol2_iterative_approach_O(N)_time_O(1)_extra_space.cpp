class Solution {
public:
    int kthGrammar(int n, int k) {
        const int STATE_01 = 0;
        const int STATE_10 = 1;
        
        int pow2 = (1 << n);
        int state = 0;
        int stateIdx = 0;
        
        while(k > 1){
            if(k <= pow2 / 2){
                stateIdx = 0;
            }else{
                stateIdx = 1;
                k -= (pow2 / 2);
            }

            if((state == STATE_01 && stateIdx == 0) ||
               (state == STATE_10 && stateIdx == 1)){
                state = STATE_01;
            }else{
                state = STATE_10;
            }
            
            pow2 /= 2;
        }
        
        return (state == STATE_10);
    }
};