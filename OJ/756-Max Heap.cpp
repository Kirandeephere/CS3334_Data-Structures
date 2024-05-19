/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 234021
 * Submitted at:  2022-11-30 21:08:02
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    756
 * Problem Name:  Max-Heap
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v;
        while(n--)
        {
            char c;
            cin>>c;
            if(c=='a')
            {
                int x;
                cin>>x;
                v.push_back(x);
                push_heap(v.begin(),v.end());
            }
            else if(c=='p')
            {
                pop_heap(v.begin(),v.end());
                v.pop_back();
            }
            else
            {
                int sum=0;
                for(int i=0;i<v.size();i++)
                {
                    sum+=v[i];
                }
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}