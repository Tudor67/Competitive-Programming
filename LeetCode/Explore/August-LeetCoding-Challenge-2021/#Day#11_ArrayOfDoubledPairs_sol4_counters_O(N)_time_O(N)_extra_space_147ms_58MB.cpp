class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int elem: arr){
            count[elem] += 1;
        }
        
        bool isPossible = true;
        if(count.count(0)){
            if(count[0] % 2 == 0){
                count.erase(0);
            }else{
                isPossible = false;
            }
        }
        
        while(isPossible && !count.empty()){
            int startElem = count.begin()->first;
            while(startElem % 2 == 0 && count.count(startElem / 2)){
                startElem /= 2;
            }
            int elem = startElem;
            while(isPossible && count.count(elem)){
                if(count[elem] == 0){
                    count.erase(elem);
                    elem *= 2;
                    continue;
                }
                if(count.count(2 * elem) && count[elem] <= count[2 * elem]){
                    count[2 * elem] -= count[elem];
                    count.erase(elem);
                    elem *= 2;
                }else{
                    isPossible = false;
                }
            }
        }
        
        return isPossible;
    }
};