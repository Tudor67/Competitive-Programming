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
        auto it = upper_bound(v[index].begin(), v[index].end(), pair<int, int>{snap_id, INT_MIN});
        if(it != v[index].end() && it->first == snap_id){
            return it->second;
        }
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */