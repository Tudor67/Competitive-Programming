class Solution {
private:
    const int STATE_01 = 0;
    const int STATE_10 = 1;
    
    int solve(int k, int pow2, int state){
        if(k == 1){
            return (state == STATE_10);
        }
        
        int stateIdx = -1;
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
        
        return solve(k, pow2 / 2, state);
    }
    
public:
    int kthGrammar(int n, int k) {
        return solve(k, 1 << n, 0);
    }
};