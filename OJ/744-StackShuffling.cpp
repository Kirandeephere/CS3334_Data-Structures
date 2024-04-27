#include <iostream>
#include <stack>
using namespace std;

void possible(int initial_order[], int final_order[], int n){
    stack<int> a;
    stack<int> b;
    stack<int> s;

    // Push elements of initial_order into stack_a
    for (int i = n - 1; i >= 0; --i) {
        a.push(initial_order[i]);
    }

    // Push elements of final_order into stack_b
    for (int i = n - 1; i >= 0; --i) {
        b.push(final_order[i]);

    }

    while (!a.empty()) {
        if (a.top() == b.top()) {
            a.pop();
            b.pop();

            while (!s.empty() && s.top() == b.top()) {
                s.pop();
                b.pop();
            }
        } else {
            s.push(a.top());
            a.pop();
        }
    }

    if (b.empty()) {
        cout << "Aye" << endl;  // Final order is possible
    } else {
        cout << "Impossible" << endl;  // Final order is not possible
    }

}

int main(){
    // The number of test cases
    int T;
    cin >> T;

    while(T!=0){
        // The number of elements in initial_order;
        int n ;
        cin >> n;
        
        // Get initial_order;
        int initial_order[n];

        for (int i=0; i<n; i++){
            cin >> initial_order[i];
        }

        // The number of permutations to judge
        int m;
        cin >> m;

        while(m!=0){

            // Get final_order to judge
            int final_order[n];

            for (int i=0; i<n; i++){
                cin >> final_order[i];
            }

            possible(initial_order, final_order, n);

            // Permutation completed
            m--;
        }
        // Testcase completed
        T--;
    }
    

}

