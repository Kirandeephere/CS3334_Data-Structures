/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 222811
 * Submitted at:  2022-10-19 17:07:08
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    744
 * Problem Name:  Stack Shuffling
 */

#include <iostream>
#include <stack>

using namespace std;

int check(stack < int > a, int arr[], int n) {
  int i = 0;
  stack < int > b, s;

  while (!a.empty()) {
    if (a.top() == arr[i]) {
      s.push(a.top());
      a.pop();
      while (!s.empty() && s.top() == arr[i]) {
        b.push(s.top());
        s.pop();
        i++;
      }
    } else {
      s.push(a.top());
      a.pop();
    }
  }

  if (b.size() == n) {
    return 1;
  }

  return 0;
}

int main() {
  int T, N, m, count = 0;
  cin >> T;

  int res[10000];

  stack < int > a;

  for (int i = 0; i < T; i++) {
    cin >> N;

    for (int j = 0; j < N; j++) {
      int temp;
      cin >> temp;
      a.push(temp);
    }

    cin >> m;
    int * arr = new int[N];

    for (int j = 0; j < m; j++) {
      for (int k = 0; k < N; k++) {
        cin >> arr[k];
      }
      res[count++] = check(a, arr, N);
    }
    
    delete[] arr;
    while (!a.empty()) a.pop();
  }

  for (int j = 0; j < count; j++) {
    if (res[j] == 0)
      cout << "Impossible" << endl;
    else
      cout << "Aye" << endl;
  }

  return 0;
}