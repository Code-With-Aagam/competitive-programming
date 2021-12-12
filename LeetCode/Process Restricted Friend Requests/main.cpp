class Solution {
    vector<int> parent;

    void init(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int representative(int u) {
        while (u != parent[u]) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }

    void merge(int u, int v) {
        int ru = representative(u);
        int rv = representative(v);
        if (ru != rv) {
            parent[ru] = rv;
        }
    }

public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        init(n);
        vector<bool> ans;
        for (const auto &request : requests) {
            int u = request[0];
            int v = request[1];
            int pu = representative(u);
            int pv = representative(v);
            bool good = true;
            if (pu != pv) {
                for (const auto &restriction : restrictions) {
                    int a = restriction[0];
                    int b = restriction[1];
                    int pa = representative(a);
                    int pb = representative(b);
                    if ((pa == pu and pb == pv) or (pa == pv and pb == pu)) {
                        good = false;
                        break;
                    }
                }
            }
            if (good) {
                merge(u, v);
            }
            ans.push_back(good);
        }
        return ans;
    }
};