class SnapshotArray {
private:
    vector<vector<pair<int, int>>> v;
    int snapId;
    
public:
    SnapshotArray(int length) {
        v.assign(length, {{0, 0}});
        snapId = 0;
    }
    
    void set(int index, int val) {
        if(v[index].back().first == snapId){
            v[index].back().second = val;
        }else{
            v[index].emplace_back(snapId, val);
        }
    }
    
    int snap() {
        snapId += 1;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        int l = 0;
        int r = (int)v[index].size();
        while(l != r){
            int mid = (l + r) / 2;
            if(v[index][mid].first <= snap_id){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return v[index][r - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */