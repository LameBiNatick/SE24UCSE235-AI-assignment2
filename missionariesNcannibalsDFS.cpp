#include <iostream>
#include <set>
using namespace std;

struct State {
    int m, c, boat;
};

set<string> visited;

bool valid(int m, int c) {

    if(m < 0 || c < 0 || m > 3 || c > 3)
        return false;

    if(m > 0 && m < c)
        return false;

    if((3-m) > 0 && (3-m) < (3-c))
        return false;

    return true;
}

bool dfs(int m, int c, int boat) {

    cout << "(" << m << "," << c << "," << boat << ")" << endl;

    if(m == 0 && c == 0) {
        cout << "Goal reached!" << endl;
        return true;
    }

    string key = to_string(m) + to_string(c) + to_string(boat);

    if(visited.count(key))
        return false;

    visited.insert(key);

    int moves[5][2] = {
        {1,0},
        {2,0},
        {0,1},
        {0,2},
        {1,1}
    };

    for(int i=0;i<5;i++) {

        int nm, nc, nb;

        if(boat == 1) {
            nm = m - moves[i][0];
            nc = c - moves[i][1];
            nb = 0;
        }
        else {
            nm = m + moves[i][0];
            nc = c + moves[i][1];
            nb = 1;
        }

        if(valid(nm,nc)) {
            if(dfs(nm,nc,nb))
                return true;
        }
    }

    return false;
}

int main() {

    dfs(3,3,1);

} //BFS explores the search space level by level and guarantees the shortest solution, whereas DFS explores one path deeply before backtracking and may not produce the optimal solution.
