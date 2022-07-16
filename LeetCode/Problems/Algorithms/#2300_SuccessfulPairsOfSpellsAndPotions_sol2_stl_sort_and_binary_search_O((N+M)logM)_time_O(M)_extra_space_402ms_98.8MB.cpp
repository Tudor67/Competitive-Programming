class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int N = spells.size();
        const int M = potions.size();
        
        vector<int> sortedPotions = potions;
        sort(sortedPotions.begin(), sortedPotions.end());
        
        vector<int> pairs(N);
        for(int i = 0; i < N; ++i){
            int l = 0;
            int r = M;
            while(l != r){
                int mid = (l + r) / 2;
                if(spells[i] * 1LL * sortedPotions[mid] < success){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            pairs[i] = M - r;
        }
        
        return pairs;
    }
};