// ======================= BÀI 8 HOÀN CHỈNH =======================

#include <iostream>
#include <algorithm>
using namespace std;

class cNhanVienSX {
private:
    string ma, ten, ns;
    int soSP;
    double donGia;

public:

    void nhap() {

        cin.ignore();

        cout << "Nhap ma: ";
        getline(cin, ma);

        cout << "Nhap ten: ";
        getline(cin, ten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ns);

        cout << "Nhap so san pham: ";
        cin >> soSP;

        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    double luong() {
        return soSP * donGia;
    }

    void xuat() {

        cout << ma << " - "
             << ten << " - "
             << ns << " - "
             << luong() << endl;
    }
};

class cListNhanVienSX {
private:
    int n;
    cNhanVienSX *a;

public:

    ~cListNhanVienSX() {
        delete[] a;
    }

    void nhap() {

        cout << "Nhap so nhan vien: ";
        cin >> n;

        a = new cNhanVienSX[n];

        for (int i = 0; i < n; i++) {

            cout << "\nNhan vien " << i + 1 << ":\n";
            a[i].nhap();
        }
    }

    void xuat() {

        for (int i = 0; i < n; i++)
            a[i].xuat();
    }

    double tongLuong() {

        double tong = 0;

        for (int i = 0; i < n; i++)
            tong += a[i].luong();

        return tong;
    }

    void luongThapNhat() {

        double min = a[0].luong();

        for (int i = 1; i < n; i++)
            if (a[i].luong() < min)
                min = a[i].luong();

        for (int i = 0; i < n; i++)
            if (a[i].luong() == min)
                a[i].xuat();
    }

    void sapXepTangLuong() {

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i].luong() > a[j].luong())
                    swap(a[i], a[j]);
    }
};

int main() {

    cListNhanVienSX ds;

    ds.nhap();

    cout << "\nDanh sach nhan vien san xuat:\n";
    ds.xuat();

    cout << "\nTong luong cong ty phai tra: ";
    cout << ds.tongLuong();

    cout << "\n\nNhan vien luong thap nhat:\n";
    ds.luongThapNhat();

    ds.sapXepTangLuong();

    cout << "\nDanh sach sau sap xep tang luong:\n";
    ds.xuat();

    return 0;
}
