class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int N = fruits.size();

        int res = 0;
        int l = 0;
        unordered_map<int, int> freq;
        
        for(int r = 0; r < N; ++r){
            freq[fruits[r]] += 1;
            while((int)freq.size() > 2){
                freq[fruits[l]] -= 1;
                if(freq[fruits[l]] == 0){
                    freq.erase(fruits[l]);
                }
                l += 1;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};