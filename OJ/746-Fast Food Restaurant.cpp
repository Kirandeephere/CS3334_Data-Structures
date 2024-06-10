/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293011
 * Submitted at:  2024-06-10 20:05:01
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    746
 * Problem Name:  Fast Food Restaurant
 */

#include <iostream>
#include <queue>
using namespace std;

struct Customer {
    int arrival;
    int order;
    int patience;
};

int process_customers(int N) {
    queue<int> q;  // Queue to store end times of orders
    int current_time = 0;
    int server_available_time = 0;
    int result = -1;
    
    for (int i = 0; i < N; ++i) {
        Customer customer;
        cin >> customer.arrival >> customer.order >> customer.patience;
        
        // Update current time to arrival time of the current customer
        current_time = customer.arrival;
        
        // Remove finished customers from the queue
        while (!q.empty() && q.front() <= current_time) {
            q.pop();
        }
        
        // Check the current queue length
        int current_queue_length = q.size();
        
        if (current_queue_length > customer.patience) {
            // This customer gives up
            if (i == N - 1) {
                return -1;
            }
            continue;
        }
        
        // Customer stays, add them to the queue
        int start_time = max(server_available_time, current_time);
        q.push(start_time + customer.order);
        server_available_time = start_time + customer.order;
        
        if (i == N - 1) {
            result = start_time;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        int result = process_customers(N);
        cout << result << "\n";
    }
    
    return 0;
}