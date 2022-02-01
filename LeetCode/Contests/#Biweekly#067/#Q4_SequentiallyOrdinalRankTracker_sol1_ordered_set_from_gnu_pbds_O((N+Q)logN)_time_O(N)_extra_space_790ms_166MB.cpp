#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class SORTracker {
private:
    int q;
    ordered_set<pair<int, string>> locations;
    
public:
    SORTracker() {
        q = 0;
    }
    
    void add(string name, int score) {
        locations.insert({-score, name});
    }
    
    string get() {
        q += 1;
        return locations.find_by_order(q - 1)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */