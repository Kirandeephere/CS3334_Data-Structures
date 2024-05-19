/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237210
 * Submitted at:  2022-12-03 16:35:43
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    749
 * Problem Name:  Tree reconstruction
 */



#include <iostream>
using namespace std;
 
int searchRoot(int a[], int k, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            return i;
    return -1;
}
 
int count=0;
void printPostOrder(int inOrder[], int preOrder[], int n, int num)
{ 
    int root = searchRoot(inOrder, preOrder[0], n);
 
    if (root != 0)
        printPostOrder(inOrder, preOrder + 1, root, num);
 
    if (root != n - 1)
        printPostOrder(inOrder + root + 1, preOrder + root + 1, n - root - 1, num);
 
    if (count != num - 1){
         cout << preOrder[0]<<" ";
         count++;
     
    }
    else {
        cout << preOrder[0];
        count = 0;
    }
   
}

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int num = n;
        int *in= new int[n];
        int *pre=new int[n];
        for(int i=0;i<n;i++)
            cin>>pre[i];
        for(int j=0;j<n;j++)
            cin>>in[j];
    printPostOrder(in, pre, n, num);
    cout << endl;
    }
    return 0;
}