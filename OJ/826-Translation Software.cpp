/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 223465
 * Submitted at:  2022-10-28 10:07:06
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    826
 * Problem Name:  Translation Software
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int m, n, val;

  cin >> m >> n;
  int words[n];
  int memoryRef = 0;
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  unordered_set < int > s;
  queue < int > q;
  for (int i = 0; i < n; i++) {
    if (s.size() < m) {
      if (s.find(words[i]) == s.end()) {
        s.insert(words[i]);
        memoryRef++;
        q.push(words[i]);
      }
    } else {

      if (s.find(words[i]) == s.end()) {
        int val = q.front();
        q.pop();
        s.erase(val);
        s.insert(words[i]);
        q.push(words[i]);

        memoryRef++;
      }
    }
  }

  cout << memoryRef << endl;

}