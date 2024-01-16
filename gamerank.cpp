#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
    cin >> s;
    int rank = 25;
    int rankStars = 1;
    // The key represents the rank, the value the number of stars for this rank
    map<int, int> reqStars;
    for (int i = 25; i >= 0; --i) {
        if (i % 5 == 0 && i > 5) rankStars++;
        reqStars[i] = rankStars;
    }
    int n = s.size();
    int stars = 0;
    int consecutiveWins = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            stars++;
            consecutiveWins++;
            if (consecutiveWins >= 3 && rank > 5) stars++;
        } else if (rank <= 20) {
            stars--;
            consecutiveWins = 0;
        } else consecutiveWins = 0; // Losing with rank larger than 20 does still ruins the streak
        if (stars > reqStars[rank]) {
            stars -= reqStars[rank];
            rank--;
        } else if (stars < 0) {
            if (rank < 20) {
                rank++;
                stars = reqStars[rank] + stars;
            }
            if (rank >= 20) { // Stars can't be negative if rank is 20
                stars = max(stars, 0);
            }
        }
        if (rank == 0) break; // Reached legendary, no need to continue
    }
    if (!rank) {
        cout << "Legend\n";
    } else cout << rank << '\n';
}
