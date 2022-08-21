class Solution {
public:
    bool isPossible(vector<int>& nums) {
        const int N = nums.size();
        
        map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        bool isPossible = true;
        while(isPossible && !count.empty()){
            int len = 0;
            int prevNum = count.begin()->first - 1;
            int prevNumCount = 0;
            
            map<int, int>::iterator it = count.begin();
            while(it != count.end()){
                int num = it->first;
                int numCount = it->second;
                if(prevNum + 1 == num && prevNumCount <= numCount){
                    it->second -= 1;
                    if(it->second == 0){
                        it = count.erase(it);
                    }else{
                        it = next(it);
                    }
                    len += 1;
                    prevNum = num;
                    prevNumCount = numCount;
                }else{
                    break;
                }
            }
            
            if(len < 3){
                isPossible = false;
            }
        }
        
        return isPossible;
    }
};