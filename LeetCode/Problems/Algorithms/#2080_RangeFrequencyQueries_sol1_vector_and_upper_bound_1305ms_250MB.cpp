class RangeFreqQuery {
private:
    vector<vector<int>> posOf;
    
public:
    RangeFreqQuery(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_VAL = *max_element(arr.begin(), arr.end());
        posOf.resize(MAX_VAL + 1);
        for(int i = 0; i < N; ++i){
            posOf[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if((int)posOf.size() <= value){
            return 0;
        }
        auto it1 = lower_bound(posOf[value].begin(), posOf[value].end(), left);
        auto it2 = upper_bound(it1, posOf[value].end(), right);
        return it2 - it1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */