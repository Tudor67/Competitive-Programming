#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 5;

int n, x, y;
vector <int> a[MAX_N];
int prev[MAX_N], d[MAX_N];

char* get_new_c_string(const char* a, const char* b){
    char* c_s = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    strcpy(c_s, a);
    strcat(c_s, b);
    return c_s;
}

void bfs(const vector<int>& src_nodes, int* d, const int& n){
    for(int i = 1; i <= n; ++i){
        d[i] = -1;
    }

    queue <int> q;

    for(int node: src_nodes){
        q.push(node);
        d[node] = 0;
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int y: a[x]){
            if(d[y] == -1){
                d[y] = 1 + d[x];
                q.push(y);
            }
        }
    }
}

pair <int, int> get_max(int* d, const int& n, const int& ignored_node1, const int& ignored_node2){
    pair <int, int> mx = make_pair(-1, -1); // (max_value, pos_of_max_value)
    for(int i = 1; i <= n; ++i){
        if(d[i] > mx.first && i != ignored_node1 && i != ignored_node2){
            mx = make_pair(d[i], i);
        }
    }
    return mx;
}

vector <int> get_nodes_from_path(const int& src, const int& dest, int* d, const int& n){
    vector <int> nodes;

    bfs({src}, d, n);

    int y = dest;
    nodes.push_back(y);
    while(y != src){
        for(int x: a[y]){
            if(d[x] + 1 == d[y]){
                nodes.push_back(x);
                y = x;
            }
        }
    }

    reverse(nodes.begin(), nodes.end());

    return nodes;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        freopen(get_new_c_string(argv[1], ".in"), "r", stdin);
        freopen(get_new_c_string(argv[1], ".out"), "w", stdout);
    #endif
    
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
        scanf("%d %d\n", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    // a - first node
    bfs({1}, d, n);
    int a = get_max(d, n, -1, -1).second;

    // b - second node
    bfs({a}, d, n);
    int b = get_max(d, n, -1, -1).second;

    // c - third node
    vector <int> nodes_from_a_to_b = get_nodes_from_path(a, b, d, n);
    bfs(nodes_from_a_to_b, d, n);
    int c = get_max(d, n, a, b).second;

    printf("%d\n", (int)nodes_from_a_to_b.size() - 1 + d[c]);
    printf("%d %d %d", a, b, c);
    
    return 0;
}