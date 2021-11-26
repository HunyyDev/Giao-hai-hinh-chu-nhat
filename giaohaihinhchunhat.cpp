#include <iostream>
#define ll long long
#define pll pair<ll,ll>

//https://khmt.uit.edu.vn/wecode/truonganpn/assignment/31/126

using namespace std;

struct point {
    ll x, y;
};

struct geo {
    point A, B, C, D;
};

geo h1, h2;
ll area, conflict_area=0;

void rotate90(point& A) {
    A = { -A.y,A.x };
}

void init(geo& h) {
    h.A = { h.D.x,h.B.y };
    h.C = { h.B.x,h.D.y };
}

void rotate90(geo& h1) {
    rotate90(h1.A);
    rotate90(h1.B);
    rotate90(h1.C);
    rotate90(h1.D);
    point temp = h1.A;
    h1.A = h1.B;
    h1.B = h1.C;
    h1.C = h1.D;
    h1.D = temp;
}

void check() {
    if (h2.A.x <= h1.C.x && h1.C.x <= h2.B.x && h2.D.y <= h1.C.y && h1.C.y <= h2.A.y) {
        if (conflict_area==0)  conflict_area = abs(h1.C.x - max(h1.D.x, h2.D.x)) * abs(h1.D.y - min(h1.A.y, h2.A.y));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> h1.D.x >> h1.D.y >> h1.B.x >> h1.B.y >> h2.D.x >> h2.D.y >> h2.B.x >> h2.B.y;
    init(h1); init(h2);
    area = abs(h1.A.x - h1.B.x) * abs(h1.A.y - h1.D.y) + abs(h2.A.x - h2.B.x) * abs(h2.A.y - h2.D.y);
    if (h1.B.y >= h2.B.y && h1.B.x >= h2.B.x && h1.D.y <= h2.D.y && h1.D.x <= h2.D.x) {
        cout << max(abs(h1.A.x - h1.B.x) * abs(h1.A.y - h1.D.y), abs(h2.A.x - h2.B.x) * abs(h2.A.y - h2.D.y));
        return 0;
    }
    swap(h1, h2);
    if (h1.B.y >= h2.B.y && h1.B.x >= h2.B.x && h1.D.y <= h2.D.y && h1.D.x <= h2.D.x) {
        cout << max(abs(h1.A.x - h1.B.x) * abs(h1.A.y - h1.D.y), abs(h2.A.x - h2.B.x) * abs(h2.A.y - h2.D.y));
        return 0;
    }
    check();
    for (int i = 1; i <= 4; i++) {
        if (conflict_area == 0) {
            rotate90(h1), rotate90(h2);
            check();
        }
    }
    swap(h1, h2);
    for (int i = 1; i <= 4; i++) {
        if (conflict_area == 0) {
            rotate90(h1), rotate90(h2);
            check();
        }
    }
    cout << area - conflict_area << "\n";
    return 0;
}
