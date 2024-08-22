class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> freq;

        for(int b: bills){
            if(b == 10){
                if(freq[5] >= 1){
                    freq[5] -= 1;
                }else{
                    return false;
                }
            }else if(b == 20){
                if(freq[10] >= 1 && freq[5] >= 1){
                    freq[10] -= 1;
                    freq[5] -= 1;
                }else if(freq[5] >= 3){
                    freq[5] -= 3;
                }else{
                    return false;
                }
            }
            freq[b] += 1;
        }

        return true;
    }
};