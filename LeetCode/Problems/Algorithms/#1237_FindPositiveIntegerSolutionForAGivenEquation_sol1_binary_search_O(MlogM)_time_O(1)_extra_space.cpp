/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customFunction, int z) {
        const int MAX_VAL = 1000;
        vector<vector<int>> answer;
        
        for(int x = 1; x <= MAX_VAL; ++x){
            int l = 1;
            int r = MAX_VAL;
            while(l != r){
                int mid = (l + r) / 2;
                if(customFunction.f(x, mid) < z){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            int y = r;
            
            // update answer if z is found
            if(customFunction.f(x, y) == z){
                answer.push_back({x, y});
            }
        }
        
        return answer;
    }
};