#include <iostream>
#include <queue>

using namespace std;

void playCardGame(int s, int n, int playerHands[][10], int rounds) {
    queue<int> cardQueue;
    bool activePlayers[10] = {true};

    for (int r = 0; r < rounds; r++) {
        for (int player = 0; player < n; player++) {
            if (!activePlayers[player]) {
                continue;
            }

            int card = playerHands[player][r];
            cardQueue.push(card);

            bool collectCards = false;
            if (card == s && cardQueue.size() > 1) {
                int prevCard = cardQueue.front();
                cardQueue.pop();
                collectCards = true;

                while (!cardQueue.empty() && cardQueue.front() != prevCard) {
                    cardQueue.pop();
                }
            } else if (cardQueue.size() > 1 && cardQueue.front() == card) {
                collectCards = true;
            }

            if (collectCards) {
                while (!cardQueue.empty()) {
                    int collectedCard = cardQueue.front();
                    cardQueue.pop();
                    playerHands[player][r] = collectedCard;
                    r++;
                }
                r--;
            }
        }

        int activeCount = 0;
        for (int player = 0; player < n; player++) {
            if (activePlayers[player]) {
                activeCount++;
            }
        }

        if (activeCount <= 1) {
            break;
        }
    }

    for (int player = 0; player < n; player++) {
        if (activePlayers[player]) {
            cout << n << endl;
            for (int i = 0; i < rounds; i++) {
                if (playerHands[player][i] == 0) {
                    break;
                }
                cout << playerHands[player][i] << " ";
            }
            cout << endl;
        } else {
            cout << "out" << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int s, n, rounds;
        cin >> s >> n >> rounds;
        int playerHands[10][10] = {};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rounds; j++) {
                cin >> playerHands[i][j];
            }
        }

        playCardGame(s, n, playerHands, rounds);
    }

    return 0;
}