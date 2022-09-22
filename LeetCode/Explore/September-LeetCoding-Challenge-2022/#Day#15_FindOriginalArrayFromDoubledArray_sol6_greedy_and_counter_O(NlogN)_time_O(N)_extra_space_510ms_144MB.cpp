class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // Step 1: store the frequency/count of each num
        map<int, int> count;
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
        //           * fix the current minNum
        //           * if the counter contains 2 * minNum => remove minNum and 2 * minNum from counter
        //                                                   add minNum to original vector
        //             otherwise => return {}
        //         if the counter is empty => return original vector
        for(const pair<int, int>& P: count){
            int minNum = P.first;
            if(count[minNum] == 0){
                // ok
            }else if(count[minNum] <= count[2 * minNum]){
                original.resize(original.size() + count[minNum], minNum);
                count[2 * minNum] -= count[minNum];
                count[minNum] = 0;
            }else{
                return {};
            }
        }
        
        return original;
    }
};