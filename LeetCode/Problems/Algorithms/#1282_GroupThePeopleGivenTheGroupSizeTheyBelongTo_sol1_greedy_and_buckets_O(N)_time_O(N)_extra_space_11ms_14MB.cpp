class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        const int N = groupSizes.size();

        vector<vector<int>> groups(N + 1);
        for(int i = 0; i < N; ++i){
            groups[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> res;
        for(int size = 1; size <= N; ++size){
            if(!groups[size].empty()){
                res.push_back({});
                for(int i: groups[size]){
                    if((int)res.back().size() + 1 > size){
                        res.push_back({i});
                    }else{
                        res.back().push_back(i);
                    }
                }
            }
        }

        return res;
    }
};