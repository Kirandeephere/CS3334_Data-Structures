/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 234085
 * Submitted at:  2022-11-30 21:45:48
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    832
 * Problem Name:  Chicago in the 1920s: a battlefield of gangsters
 */

#include <iostream>
using namespace std;
int n, m, ans;
int fa[1001], e[1001], v[1001];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void unionn(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
}

int main()
{
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int p, q;
        char ch;
        cin >> ch >> p >> q;
        if (ch == 'F')
            unionn(p, q);
        if (ch == 'E')
        {
            if (!e[p])
                e[p] = q;
            else
                unionn(e[p], q);
            if (!e[q])
                e[q] = p;
            else
                unionn(e[q], p);
        }
    }

    for (int i = 1; i <= n; i++)
        v[find(i)] = 1;

    for (int i = 1; i <= n; i++)
        if (v[i] == 1)
            ans++;

    cout << ans << endl;

    return 0;
}