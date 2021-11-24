class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int N = changed.size();
        const int ZEROS = count(changed.begin(), changed.end(), 0);
        
        // special case (odd size or odd number of zeros)
        if(N % 2 == 1 || ZEROS % 2 == 1){
            return {};
        }
        
        unordered_map<int, int> count;
        for(int num: changed){
            count[num] += 1;
        }
        
        // add all (0, 2 * 0) pairs and remove {0, count[0]} from count
        vector<int> original(count[0] / 2, 0);
        count.erase(0);
        
        // for a given x from a chain [y, 2 * y, 2 * (2 * y), ..., x, 2 * x, 2 * (2 * x), ...]
        // remove all pairs (num, 2 * num) starting from the smallest num of the chain
        for(int num: changed){
            if(!count.count(num)){
                continue;
            }else{
                int x = num;
                while(x % 2 == 0 && count.count(x / 2)){
                    x /= 2;
                }
                while(count.count(2 * x) && count[2 * x] >= count[x]){
                    original.resize((int)original.size() + count[x], x);
                    count[2 * x] -= count[x];
                    count.erase(x);
                    x *= 2;
                }
                if(count[x] == 0){
                    count.erase(x);
                }else{
                    original.clear();
                    break;
                }
            }
        }
        
        return original;
    }
};