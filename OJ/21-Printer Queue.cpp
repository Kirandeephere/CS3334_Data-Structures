/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 235697
 * Submitted at:  2022-12-02 09:58:54
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    21
 * Problem Name:  Printer Queue
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct pq        // Created structure for priority queue
{
	int priority;
	int num;
	pq(int p, int n){priority = p; num = n;}
	pq(){}
};

int main()
{
	queue<pq> queue;
	int n, m, t;
	cin >> t;   // input for test cases
	while (t--)
	{
		cin >> n >> m; // input for n and m
    		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			queue.push(pq(arr[i], i + 1));   //push the integer along with its priority in pq
		}   
		sort(arr,arr + n);
		int max_p = n - 1;
		int completetime = 0;
		while (!queue.empty())
		{
			pq head = queue.front();
			queue.pop();
			if (head.priority < arr[max_p]) 
				queue.push(head);   //If priority of head is less than maximum priority, push the head to the pq.
			else
			{
				completetime++;
				if (head.num == m + 1)
					cout << completetime << endl;
				max_p--;
			}
		}
	}
	return 0;
}