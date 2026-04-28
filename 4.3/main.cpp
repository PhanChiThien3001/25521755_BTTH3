

#include <iostream>
#include <algorithm>
using namespace std;

class cPhanSo {
private:
    int tu, mau;

    int UCLN(int a, int b) {
        if (b == 0)
            return a;

        return UCLN(b, a % b);
    }

public:
    cPhanSo(int tu = 0, int mau = 1) {
        this->tu = tu;
        this->mau = mau;
    }

    void nhap() {
        do {
            cin >> tu >> mau;
        } while (mau == 0);

        rutGon();
    }

    void xuat() {
        cout << tu << "/" << mau;
    }

    void rutGon() {
        int u = UCLN(abs(tu), abs(mau));

        tu /= u;
        mau /= u;

        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    double giaTri() {
        return (double)tu / mau;
    }

    int getTu() {
        return tu;
    }

    cPhanSo operator + (cPhanSo b) {
        cPhanSo kq;

        kq.tu = tu * b.mau + b.tu * mau;
        kq.mau = mau * b.mau;

        kq.rutGon();

        return kq;
    }

    bool operator > (cPhanSo b) {
        return giaTri() > b.giaTri();
    }

    bool operator < (cPhanSo b) {
        return giaTri() < b.giaTri();
    }
};

class cDSPhanSo {
private:
    int n;
    cPhanSo *a;

    bool nguyenTo(int x) {
        if (x < 2)
            return false;

        for (int i = 2; i <= x / 2; i++)
            if (x % i == 0)
                return false;

        return true;
    }

public:
    ~cDSPhanSo() {
        delete[] a;
    }

    void nhap() {
        cin >> n;

        a = new cPhanSo[n];

        for (int i = 0; i < n; i++)
            a[i].nhap();
    }

    void xuat() {
        for (int i = 0; i < n; i++) {
            a[i].xuat();
            cout << endl;
        }
    }

    cPhanSo tong() {
        cPhanSo s;

        for (int i = 0; i < n; i++)
            s = s + a[i];

        return s;
    }

    cPhanSo lonNhat() {
        cPhanSo max = a[0];

        for (int i = 1; i < n; i++)
            if (a[i] > max)
                max = a[i];

        return max;
    }

    cPhanSo nhoNhat() {
        cPhanSo min = a[0];

        for (int i = 1; i < n; i++)
            if (a[i] < min)
                min = a[i];

        return min;
    }

    cPhanSo tuNguyenToLonNhat() {
        cPhanSo kq;
        int max = -1;

        for (int i = 0; i < n; i++) {
            if (nguyenTo(abs(a[i].getTu()))
                && abs(a[i].getTu()) > max) {

                max = abs(a[i].getTu());
                kq = a[i];
            }
        }

        return kq;
    }

    void sapXepTang() {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    swap(a[i], a[j]);
    }

    void sapXepGiam() {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] < a[j])
                    swap(a[i], a[j]);
    }
};

int main() {
    cDSPhanSo ds;

    ds.nhap();

    cout << "Danh sach:\n";
    ds.xuat();

    cout << "Tong: ";
    ds.tong().xuat();

    cout << "\nLon nhat: ";
    ds.lonNhat().xuat();

    cout << "\nNho nhat: ";
    ds.nhoNhat().xuat();

    cout << "\nTu nguyen to lon nhat: ";
    ds.tuNguyenToLonNhat().xuat();

    ds.sapXepTang();

    cout << "\nDanh sach tang dan:\n";
    ds.xuat();

    ds.sapXepGiam();

    cout << "Danh sach giam dan:\n";
    ds.xuat();

    return 0;
}
