class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        const int N = products.size();
        const int L = searchWord.length();
        
        vector<string> sortedProducts = products;
        sort(sortedProducts.begin(), sortedProducts.end());
        
        vector<vector<string>> res(L);
        int i = 0;
        for(int j = 0; j < L; ++j){
            while(i < N && sortedProducts[i].compare(0, j + 1, searchWord, 0, j + 1) < 0){
                i += 1;
            }
            for(int k = i; k < min(i + 3, N); ++k){
                if(sortedProducts[k].compare(0, j + 1, searchWord, 0, j + 1) == 0){
                    res[j].push_back(sortedProducts[k]);
                }
            }
        }
        
        return res;
    }
};