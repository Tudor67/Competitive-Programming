class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int N = changed.size();
        const int ZEROS = count(changed.begin(), changed.end(), 0);
        
        // Case 1: special case (odd size or odd number of zeros)
        if(N % 2 == 1 || ZEROS % 2 == 1){
            return {};
        }
        
        // Case 2: try to find the pair of each num (starting from the smallest num)
        map<int, int> count;
        for(int num: changed){
            count[num] += 1;
        }
        
        vector<int> original;
        for(const pair<int, int>& P: count){
            int num = P.first;
            if(count[num] == 0){
                continue;
            }else if(num == 0){
                original.resize((int)original.size() + count[0] / 2, 0);
                count[0] = 0;
            }else if(count.count(2 * num) && count[2 * num] >= count[num]){
                original.resize((int)original.size() + count[num], num);
                count[2 * num] -= count[num];
                count[num] = 0;
            }else{
                original.clear();
                break;
            }
        }
        
        return original;
    }
};