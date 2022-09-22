class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // Step 1: store the frequency/count of each num
        unordered_map<int, int> count;
        for(int num: changed){
            count[num] += 1;
        }
        
        // Step 2: (num == 0) is a special case
        vector<int> original;
        if(count[0] % 2 == 0){
            original.resize(count[0] / 2, 0);
            count.erase(0);
        }else{
            return {};
        }
        
        // Step 3: main idea of the greedy approach:
        //         repeat until there is no num in the counter:
        //           * fix the current num
        //           * find the chain x, 2 * x, 4 * x, ..., num, 2 * num, 4 * num, ...
        //             such that count[x] >= 1 and count[2 * x] >= 1 ... and count[num] >= 1, ...
        //           * remove x and 2 * x from counter (i.e., update their count), add x to original vector
        //           * remove 2 * x and 4 * x from counter (i.e., update their count), add 2 * x to original vector
        //           * ...
        //           * if at some point count[current x] > count[2 * current x] => return {}
        //         if the counter is empty => return original vector
        for(int num: changed){
            if(!count.count(num)){
                // ok
            }else{
                int x = num;
                while(x % 2 == 0 && count.count(x / 2)){
                    x /= 2;
                }
                int y = num;
                while(count.count(2 * y)){
                    y *= 2;
                }
                while(x <= y){
                    if(count[x] == 0){
                        count.erase(x);
                        x *= 2;
                    }else if(count.count(2 * x) && count[x] <= count[2 * x]){
                        original.resize(original.size() + count[x], x);
                        count[2 * x] -= count[x];
                        count.erase(x);
                        x *= 2;
                    }else{
                        return {};
                    }
                }
            }
        }
        
        return original;
    }
};