class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        const int N = grades.size();
        
        int x = sqrt(2 * N);
        if(x * (x + 1) > 2 * N){
            x -= 1;
        }
        
        return x;
    }
};