class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     *
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        int n = matrix.size();
 
    vector< vector<int> > ge(n);
    vector< int > dep(n, -1);
    vector< int > fa(n, -1);
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ( matrix[i][j] == '1' ) {
                ge[i].push_back(j);
                ge[j].push_back(i);
            }
        }
    }
 
    vector<int> stk;
    stk.push_back(0);
    dep[0] = 0;
 
    while ( !stk.empty() )
    {
        int u = stk.back(); stk.pop_back();
        for (int k = 0; k < ge[u].size(); ++k) {
            int v = ge[u][k];
            if ( fa[v] != -1 ) continue;
 
            fa[v] = u;
            dep[v] = dep[u] + 1;
            stk.push_back(v);
        }
    }
 
    int a = indexA, b = indexB;
    while ( dep[a] > dep[b] ) {
        a = fa[a];
    }
    while ( dep[a] < dep[b] ) {
        b = fa[b];
    }
    while ( a != b ) {
        a = fa[a];
        b = fa[b];
    }
    return a;
 
    }
};

class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     *
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        int n = matrix.size();
 
        vector <vector<int>> adjList(n);
        vector <int> parent(n, -1);
        vector <int> depth(n,0);
        int i,j;
        for( i = 0; i < n; i ++ ) {
            for ( j = i + 1; j < n; j++ ) {
                if (matrix[i][j] == '1') {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
 
                }
            }
        }
 
        vector <int> stk;
        stk.push_back(0);
        int cont = 0;
        while ( !stk.empty() && cont < n) {
            int node = stk.back();
            stk.pop_back();
            for ( int k = 0; k < adjList[node].size(); k ++ ) {
                int v = adjList[node][k];
                if ( parent[v] != -1 ) {
                    continue;
                }
 
                parent[v] = node;
                depth[v] = depth[node] + 1;
                stk.push_back(v);
                cont ++;
            }
        }
        int a = indexA;
        int b = indexB;
  //      cout << parent[0] <<endl;
 //       cout << depth[a] << " " << depth[b] <<endl;
//        cout << parent[a] << " " << parent[b] <<endl;
        while(depth[a] > depth[b]) {
            a = parent[a];
        }
        while(depth[a] < depth[b]) {
            b = parent[b];
        }
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        return a;
    }
};


class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     *
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        int n = matrix.size();
 
    vector< vector<int> > ge(n);
    vector< int > dep(n, -1);
    vector< int > fa(n, -1);
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ( matrix[i][j] == '1' ) {
                ge[i].push_back(j);
                ge[j].push_back(i);
            }
        }
    }
 
    vector<int> stk;
    stk.push_back(0);
    dep[0] = 0;
 
    while ( !stk.empty() )
    {
        int u = stk.back(); stk.pop_back();
        for (int k = 0; k < ge[u].size(); ++k) {
            int v = ge[u][k];
            if ( fa[v] != -1 ) continue;
 
            fa[v] = u;
            dep[v] = dep[u] + 1;
            stk.push_back(v);
        }
    }
 
    int a = indexA, b = indexB;
    while ( dep[a] > dep[b] ) {
        a = fa[a];
    }
    while ( dep[a] < dep[b] ) {
        b = fa[b];
    }
    while ( a != b ) {
        a = fa[a];
        b = fa[b];
    }
    return a;
 
    }
};