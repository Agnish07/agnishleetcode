class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findUParent(parent[n]);
    }

    void unionBySize(int u, int v){
        int up_u = findUParent(u);
        int up_v = findUParent(v);

        if(up_u == up_v) return;

        int size_u = size[up_u];
        int size_v = size[up_v];

        if(size_u < size_v){
            parent[up_u] = up_v;
            size[up_u] += size_v;
        }else{
            parent[up_v] = up_u;
            size[up_v] += size_u;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n+1);
        unordered_map<string, int> mpp;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionBySize(mpp[mail], i);
                }
            }
        }

        vector<vector<string>> mails(n);

        for(auto it : mpp){
            string m = it.first;
            int node = ds.findUParent(it.second);
            mails[node].push_back(m);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            if(mails[i].size() == 0) continue;
            sort(mails[i].begin(), mails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};