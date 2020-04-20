class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // generate all positive integers with sequential digits
        // (~ 50 numbers in the range [0, 10^9])
        vector<int> v;
        for(int i = 1; i <= 9; ++i){
            v.push_back(i);
        }
        
        int prev_size = 0;
        for(int step = 2; step <= 9; ++step){
            int cur_size = v.size();
            for(int i = prev_size; i < cur_size; ++i){
                if(v[i] % 10 < 9){
                    v.push_back(v[i] * 10 + v[i] % 10 + 1);
                }
            }
            prev_size = cur_size;
        }
        
        vector<int> ans;
        for(int elem: v){
            if(low <= elem && elem <= high){
                ans.push_back(elem);
            }
        }
        
        return ans;
    }
};