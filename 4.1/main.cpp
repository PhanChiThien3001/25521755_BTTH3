#include <iostream>
#include <cmath>
using namespace std;

class cDiem {
private:
    double x, y;

public:
    cDiem(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    void nhap() {
        cin >> x >> y;
    }

    void xuat() {
        cout << "(" << x << ", " << y << ")";
    }

    double getX() { return x; }
    double getY() { return y; }

    void tinhTien(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void phongTo(double k) {
        x *= k;
        y *= k;
    }

    void thuNho(double k) {
        x /= k;
        y /= k;
    }
};

class cTamGiac {
private:
    cDiem A, B, C;

    double tinhCanh(cDiem P1, cDiem P2) {
        return sqrt(pow(P1.getX() - P2.getX(), 2) +
                    pow(P1.getY() - P2.getY(), 2));
    }

public:
    void nhap() {
        cout << "Nhap diem A: ";
        A.nhap();
        cout << "Nhap diem B: ";
        B.nhap();
        cout << "Nhap diem C: ";
        C.nhap();
    }

    void xuat() {
        cout << "Tam giac: ";
        A.xuat();
        cout << " ";
        B.xuat();
        cout << " ";
        C.xuat();
        cout << endl;
    }

    double chuVi() {
        double a = tinhCanh(B, C);
        double b = tinhCanh(A, C);
        double c = tinhCanh(A, B);
        return a + b + c;
    }

    double dienTich() {
        double a = tinhCanh(B, C);
        double b = tinhCanh(A, C);
        double c = tinhCanh(A, B);
        double p = chuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void loaiTamGiac() {
        double a = tinhCanh(B, C);
        double b = tinhCanh(A, C);
        double c = tinhCanh(A, B);

        if (a == b && b == c)
            cout << "Tam giac deu\n";
        else if (a == b || a == c || b == c)
            cout << "Tam giac can\n";
        else if (a*a + b*b == c*c ||
                 a*a + c*c == b*b ||
                 b*b + c*c == a*a)
            cout << "Tam giac vuong\n";
        else
            cout << "Tam giac thuong\n";
    }

    void tinhTien(double dx, double dy) {
        A.tinhTien(dx, dy);
        B.tinhTien(dx, dy);
        C.tinhTien(dx, dy);
    }

    void phongTo(double k) {
        A.phongTo(k);
        B.phongTo(k);
        C.phongTo(k);
    }

    void thuNho(double k) {
        A.thuNho(k);
        B.thuNho(k);
        C.thuNho(k);
    }
};

int main() {
    cTamGiac tg;
    tg.nhap();

    tg.xuat();

    cout << "Chu vi: " << tg.chuVi() << endl;
    cout << "Dien tich: " << tg.dienTich() << endl;

    tg.loaiTamGiac();

    tg.tinhTien(2, 3);
    cout << "Sau tinh tien:\n";
    tg.xuat();

    return 0;
}
