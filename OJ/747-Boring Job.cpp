/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237627
 * Submitted at:  2022-12-03 20:47:23
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    747
 * Problem Name:  Boring job
 */

#include <iostream>
#include <queue>
using namespace std;

struct structure{
    long long x;
    long long y;
};

int main() {
    int n;
    cin>>n;
    while(n!=0){
        n--;
        long N,K;
        cin>>N>>K;
        queue <structure> list, magic;
        for(long i=1;i<=N;i++){
            long a;
            cin>>a;
            structure n;
            n.x = a;
            n.y = i;
            list.push(n);
        }
        while(true){
            long max = (K>list.size()) ? list.size():K;
            long m2 = -999999;
            if(list.size()==1){
                cout<<list.front().y<<endl;
                list.pop();
                break;
            }
            if(max==1){
                cout<<list.front().y<<" ";
                list.pop();
                continue;
            }
            for(long i=0;i<max;i++){
                magic.push(list.front());
                list.pop();
                if(magic.back().x>m2)
                    m2 = magic.back().x;
            }
            bool flag = true;
            for(long i=0;i<max;i++){
                if((magic.front().x==m2)&&(flag)){
                    cout<<magic.front().y<<" ";
                    magic.pop();
                    flag = false;
                    continue;
                }
                magic.front().x -= 1;
                list.push(magic.front());
                magic.pop();
            }
            if(max==0)
                break;
        }
    }
    return 0;
}