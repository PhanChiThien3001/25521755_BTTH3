// ======================= BÀI 5 HOÀN CHỈNH =======================

#include <iostream>
#include <cmath>
using namespace std;

class cDaThuc {
private:
    int bac;
    int *a;

public:
    cDaThuc(int bac = 0) {
        this->bac = bac;
        a = new int[bac + 1];
    }

    ~cDaThuc() {
        delete[] a;
    }

    void nhap() {
        cout << "Nhap bac da thuc: ";
        cin >> bac;

        a = new int[bac + 1];

        for (int i = bac; i >= 0; i--) {
            cout << "He so bac " << i << ": ";
            cin >> a[i];
        }
    }

    void xuat() {
        for (int i = bac; i >= 0; i--) {

            if (a[i] == 0)
                continue;

            if (i != bac && a[i] > 0)
                cout << " + ";

            if (i == 0)
                cout << a[i];
            else if (i == 1)
                cout << a[i] << "x";
            else
                cout << a[i] << "x^" << i;
        }
    }

    int tinhGiaTri(int x) {
        int tong = 0;

        for (int i = 0; i <= bac; i++)
            tong += a[i] * pow(x, i);

        return tong;
    }

    cDaThuc cong(cDaThuc b) {

        int maxBac;

        if (bac > b.bac)
            maxBac = bac;
        else
            maxBac = b.bac;

        cDaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {

            int hs1 = 0;
            int hs2 = 0;

            if (i <= bac)
                hs1 = a[i];

            if (i <= b.bac)
                hs2 = b.a[i];

            kq.a[i] = hs1 + hs2;
        }

        return kq;
    }

    cDaThuc tru(cDaThuc b) {

        int maxBac;

        if (bac > b.bac)
            maxBac = bac;
        else
            maxBac = b.bac;

        cDaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {

            int hs1 = 0;
            int hs2 = 0;

            if (i <= bac)
                hs1 = a[i];

            if (i <= b.bac)
                hs2 = b.a[i];

            kq.a[i] = hs1 - hs2;
        }

        return kq;
    }
};

int main() {

    cDaThuc A, B;

    cout << "Nhap da thuc A:\n";
    A.nhap();

    cout << "\nNhap da thuc B:\n";
    B.nhap();

    cout << "\nDa thuc A: ";
    A.xuat();

    cout << "\nDa thuc B: ";
    B.xuat();

    cDaThuc tong = A.cong(B);

    cout << "\nTong 2 da thuc: ";
    tong.xuat();

    cDaThuc hieu = A.tru(B);

    cout << "\nHieu 2 da thuc: ";
    hieu.xuat();

    cout << "\nGia tri A tai x = 2: ";
    cout << A.tinhGiaTri(2);

    return 0;
}
