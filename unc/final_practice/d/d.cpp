#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define trav(a, x) for(auto& a: x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

class team {
    public:
    string name;
    int score, gm, gr;
    team(string n, int s, int gma, int gra): name(n), score(s), gm(gma), gr(gra) {}
    bool operator <(const team& other) const {
        if (this->score > other.score) return true;
        if (this->score < other.score) return false;
        if (this->gm - this->gr > other.gm - other.gr) return true;
        if (this->gm - this->gr < other.gm - other.gr) return false;
        if (this->gm > other.gm) return true;
        if (this->gm < other.gm) return false;
        return this->name < other.name;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<team> teams;
    string a, b;
    int ga, gb;
    map<string, int> names;
    forn(i, 6) {
        cin >> a >> ga >> gb >> b;
        if (names.find(a) == names.end()) {
            teams.push_back(team(a, 0, 0, 0));
            names[a] = sz(teams) - 1;
        }
        if (names.find(b) == names.end()) {
            teams.push_back(team(b, 0, 0, 0));
            names[b] = sz(teams) - 1;
        }
        if (ga > gb)
            teams[names[a]].score += 3;
        else if (ga == gb) {
            teams[names[a]].score += 1;
            teams[names[b]].score += 1;
        } else {
            teams[names[b]].score += 3;
        }
        teams[names[a]].gm += ga;
        teams[names[a]].gr += gb;
        teams[names[b]].gm += gb;
        teams[names[b]].gr += ga;
    }
    sort(all(teams));
    trav(t, teams) {
        cout << t.name << " " << t.score << " ";
        cout << t.gm << " " << t.gr << " " << t.gm - t.gr << endl;
    }
    return 0;
}

