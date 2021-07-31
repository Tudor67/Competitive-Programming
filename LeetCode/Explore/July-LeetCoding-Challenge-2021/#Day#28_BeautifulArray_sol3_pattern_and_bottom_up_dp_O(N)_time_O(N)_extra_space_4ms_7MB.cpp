class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> p = {1};
        while((int)p.size() < n){
            vector<int> nextP;
            // odd part
            for(int elem: p){
                if(2 * elem - 1 <= n){
                    nextP.push_back(2 * elem - 1);
                }
            }
            // even part
            for(int elem: p){
                if(2 * elem <= n){
                    nextP.push_back(2 * elem);
                }
            }
            p = nextP;
        }
        return p;
    }
};