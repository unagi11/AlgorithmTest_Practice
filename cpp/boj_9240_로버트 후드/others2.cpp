#include <bits/stdc++.h>

using namespace std;

struct pt
{
    int x, y;
    bool operator<(pt &b) const
    {
        return x < b.x || x == b.x && y < b.y;
    }
};

int ccw(pt &a, pt &b, pt &c)
{
    return (a.x - b.x) * (b.y - c.y) + (b.x - c.x) * (b.y - a.y);
}

int dist(pt &a, pt &b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pt> p(n);
    for (pt &i : p)
        cin >> i.x >> i.y;

    swap(p[0], *min_element(p.begin(), p.end()));
    sort(p.begin() + 1, p.end(), [&](pt &a, pt &b)
         {
        int cw = ccw(p[0], a, b);
        if (cw) return cw > 0;
        return dist(p[0], a) < dist(p[0], b); });

    printf("bottom (%d, %d)\n", p[0].x, p[0].y);

    vector<pt> h;
    for (pt &i : p)
    {
        while (h.size() > 1 && ccw(h[h.size() - 2], h[h.size() - 1], i) <= 0)
            h.pop_back();
        h.push_back(i);
    }

    printf("dd%d\n", h.size());
    for (int i = 0; i < h.size(); i++)
    {
        printf("%d %d\n", h[i].x, h[i].y);
    }

    int ans = 0;
    for (int i = 0; i < h.size(); ++i)
    {
        for (int j = 0; j < h.size(); ++j)
        {
            ans = max(ans, dist(h[i], h[j]));
        }
    }
    cout.precision(10);
    cout << fixed << (ans);
}