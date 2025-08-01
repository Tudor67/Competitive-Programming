class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        const int N = arr.size();

        unordered_set<int> orSet;
        deque<int> dq;

        for(int i = N - 1; i >= 0; --i){
            int currOR = arr[i];
            dq.push_back(currOR);
            orSet.insert(currOR);
            for(int j = (int)dq.size() - 1; j >= 1; --j){
                int newOR = arr[i] | dq.front();
                dq.pop_front();
                if(currOR != newOR){
                    dq.push_back(newOR);
                    orSet.insert(newOR);
                    currOR = newOR;
                }
            }
        }

        return orSet.size();
    }
};