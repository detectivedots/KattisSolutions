#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, set<int>> cardToPosition;
    int faceDown = n;
    set<string> alreadyFoundCards;
    for (int i = 0; i < m; ++i){
        int a, b;
        string s, t;
        cin >> a >> b >> s >> t;
        if (s == t){
            faceDown -= 2;
            cardToPosition.erase(s);
            alreadyFoundCards.insert(s);
            continue;
        }
        if (!alreadyFoundCards.count(s))
            cardToPosition[s].insert(a);
        if (!alreadyFoundCards.count(t))
            cardToPosition[t].insert(b);
    }
    int ans = 0;
    vector<string> tbr;
    for (const auto &card: cardToPosition){
        faceDown -= card.second.size();
        // If card is known to be at 2 different positions, then it can be found
        if (card.second.size() == 2){
            tbr.push_back(card.first);
            ans++;
        }
    }
    for (const auto &item: tbr){
        cardToPosition.erase(item);
    }
    // If the number of undiscovered cards is the same to that of the discovered unpaired cards,
    // then each undiscovered card can be paired with a discovered card
    if (cardToPosition.size() == faceDown){
        ans += faceDown;
        faceDown = 0;
    }
    if (cardToPosition.empty() && faceDown == 2) ans++;
    cout << ans << endl;
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--){
        solve();
    }
}
