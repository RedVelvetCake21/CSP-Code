#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Action {
    int room,time;
    int type; // 0:put, 1:get
    Action(int r, int t, int p) : room(r), time(t), type(p) {}
    bool operator<(const Action &other) const {
        if(time<other.time) return true;
        else if(time==other.time && type<other.type) return true;
        else if(time==other.time && type==other.type && room<other.room) return true;
        return false;
    }
};

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<Action> actions;
    vector<int> key(N+1);
    for(int i=1; i<=N; i++) key[i] = i;
    for(int k=0; k<K; k++) {
        int room, begin, length;
        scanf("%d%d%d", &room, &begin, &length);
        actions.push_back(Action(room, begin, 1));
        actions.push_back(Action(room, begin+length, 0));
    }
    sort(actions.begin(), actions.end());
    for(int i=0; i<actions.size(); i++) {
        Action &act = actions[i];
        if(act.type == 0) { // put
            for(int n=1; n<=N; n++) {
                if(key[n] == -1) {
                    key[n] = act.room;
                    break;
                }
            }
        }
        else { // get
            for(int n=1; n<=N; n++) {
                if(key[n] == act.room) {
                    key[n] = -1;
                    break;
                }
            }
        }
    }
    for(int n=1; n<=N; n++) {
        printf("%d ", key[n]);
    }
}
