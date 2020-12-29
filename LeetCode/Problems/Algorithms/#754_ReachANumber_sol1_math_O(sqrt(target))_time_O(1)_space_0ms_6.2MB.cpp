class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        
        int k = 0;
        int s = 0;
        while(s < target){
            k += 1;
            s += k;
        }
        
        int delta = s - target;
        int answer = 0;
        if(delta % 2 == 0){
            answer = k;
        }else if((delta + k + 1) % 2 == 0){
            answer = k + 1;
        }else if((delta + k + 1 + k + 2) % 2 == 0){
            answer = k + 2;
        }
        
        return answer;
    }
};