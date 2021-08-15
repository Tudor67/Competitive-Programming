class Solution {
private:
    static bool incAbsValComp(const int& LHS, const int& RHS){
        return (abs(LHS) < abs(RHS));
    }
    
public:
    bool canReorderDoubled(vector<int>& arr) {
        const int N = arr.size();
        
        unordered_map<int, int> count;
        for(int elem: arr){
            count[elem] += 1;
        }
        
        vector<int> arrSorted = arr;
        sort(arrSorted.begin(), arrSorted.end(), incAbsValComp);
        
        for(int elem: arrSorted){
            if(count[elem] == 0){
                continue;
            }
            count[elem] -= 1;
            if(count.find(2 * elem) == count.end() || count[2 * elem] <= 0){
                return false;
            }
            count[2 * elem] -= 1;
        }
        
        return true;
    }
};