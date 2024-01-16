#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[109];
    vector<string> board;
    int i = 0;
    map<char, pair<int, int>> dotToIndex;
    vector<char> dots;
    while (1) {
        auto term = scanf("%[^\n]", s);
        if (!term || term == EOF) {
            // Solve and free the vector;
            sort(dots.begin(), dots.end(), [](char a, char b) {
                if ((isdigit(a) && isdigit(b)) || (islower(a) && islower(b)) || (isupper(a) && isupper(b)))
                    return a < b;
                else if (isdigit(a) && !isdigit(b)) return true;
                else if (isdigit(b) && !isdigit(a)) return false;
                else if (islower(a) && isupper(b)) return true;
                else return false;
            });
            int n = dots.size();
            if (n < 2){
                for (const auto &item: board) {
                    puts(item.c_str());
                }
                char dummy;
                scanf("%c", &dummy);
                puts("");
                if (term == EOF) break;
                dotToIndex.clear();
                dots.clear();
                board.clear();
                i = 0;
                continue;
            }
            pair<int, int> cur = dotToIndex[dots[0]];
            for (int j = 1; j < n; ++j) {
                pair<int, int> dest = dotToIndex[dots[j]];
                while (cur != dest) {
                    if (cur.first != dest.first) {
                        if (board[cur.first][cur.second] == '.') {
                            board[cur.first][cur.second] = '|';
                        } else if (board[cur.first][cur.second] == '-') {
                            board[cur.first][cur.second] = '+';
                        }
                        cur.first += ((cur.first > dest.first) ? -1 : 1);
                    } else if (cur.second != dest.second) {
                        if (board[cur.first][cur.second] == '.') {
                            board[cur.first][cur.second] = '-';
                        } else if (board[cur.first][cur.second] == '|') {
                            board[cur.first][cur.second] = '+';
                        }
                        cur.second += ((cur.second > dest.second) ? -1 : 1);
                    }
                }
            }
            for (const auto &item: board) {
                puts(item.c_str());
            }
            char dummy;
            scanf("%c", &dummy);
            puts("");
            if (term == EOF) break;
            dotToIndex.clear();
            dots.clear();
            board.clear();
            i = 0;
        } else {
            board.push_back(string(s));
            for (int j = 0; j < strlen(s); ++j) {
                if (s[j] != '.') {
                    dotToIndex[s[j]] = make_pair(i, j);
                    dots.push_back(s[j]);
                }
            }
            char dummy;
            scanf("%c", &dummy);
            i++;
        }

    }
}
