#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct State {
    int m, c, boat;
};

bool valid(int m, int c) {

    if (m < 0 || c < 0 || m > 3 || c > 3)
        return false;

    if (m > 0 && m < c)
        return false;

    if ((3 - m) > 0 && (3 - m) < (3 - c))
        return false;

    return true;
}

void solve() {

    queue<State> q;
    set<string> visited;

    q.push({3,3,1});

    while(!q.empty()) {

        State cur = q.front();
        q.pop();

        cout << "State: (" << cur.m << "," << cur.c << "," << cur.boat << ")" << endl;

        if(cur.m == 0 && cur.c == 0) {
            cout << "Goal reached!" << endl;
            return;
        }

        string key = to_string(cur.m) + to_string(cur.c) + to_string(cur.boat);

        if(visited.count(key))
            continue;

        visited.insert(key);

        int moves[5][2] = {
            {1,0},
            {2,0},
            {0,1},
            {0,2},
            {1,1}
        };

        for(auto &move : moves) {

            int nm, nc, nb;

            if(cur.boat == 1) {
                nm = cur.m - move[0];
                nc = cur.c - move[1];
                nb = 0;
            }
            else {
                nm = cur.m + move[0];
                nc = cur.c + move[1];
                nb = 1;
            }

            if(valid(nm,nc)) {
                q.push({nm,nc,nb});
            }
        }
    }
}

int main() {

    solve();

}