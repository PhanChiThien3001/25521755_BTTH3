#include <iostream>
#include <cmath>
using namespace std;

class cDiem {
private:
    double x, y;

public:
    void nhap() {
        cin >> x >> y;
    }

    void xuat() {
        cout << "(" << x << ", " << y << ") ";
    }

    double getX() { return x; }
    double getY() { return y; }
};

class cDaGiac {
private:
    int n;
    cDiem *a;

    double khoangCach(cDiem p1, cDiem p2) {
        return sqrt(pow(p1.getX() - p2.getX(), 2) +
                    pow(p1.getY() - p2.getY(), 2));
    }

public:
    cDaGiac() {
        n = 0;
        a = NULL;
    }

    ~cDaGiac() {
        delete[] a;
    }

    void nhap() {
        cout << "Nhap so dinh: ";
        cin >> n;

        a = new cDiem[n];

        for (int i = 0; i < n; i++) {
            cout << "Nhap dinh " << i + 1 << ": ";
            a[i].nhap();
        }
    }

    void xuat() {
        for (int i = 0; i < n; i++)
            a[i].xuat();
        cout << endl;
    }

    double chuVi() {
        double cv = 0;

        for (int i = 0; i < n; i++) {
            cv += khoangCach(a[i], a[(i + 1) % n]);
        }

        return cv;
    }
};

int main() {
    cDaGiac dg;
    dg.nhap();

    cout << "Da giac: ";
    dg.xuat();

    cout << "Chu vi: " << dg.chuVi() << endl;

    return 0;
}
