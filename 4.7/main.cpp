// ======================= BÀI 7 HOÀN CHỈNH =======================

#include <iostream>
#include <algorithm>
using namespace std;

class cNhanVienVP {
private:
    string ma, ten, ns;
    double luong;

public:

    void nhap() {

        cin.ignore();

        cout << "Nhap ma: ";
        getline(cin, ma);

        cout << "Nhap ten: ";
        getline(cin, ten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ns);

        cout << "Nhap luong: ";
        cin >> luong;
    }

    void xuat() {

        cout << ma << " - "
             << ten << " - "
             << ns << " - "
             << luong << endl;
    }

    double getLuong() {
        return luong;
    }

    string getNS() {
        return ns;
    }
};

class cListNhanVienVP {
private:
    int n;
    cNhanVienVP *a;

public:

    ~cListNhanVienVP() {
        delete[] a;
    }

    void nhap() {

        cout << "Nhap so nhan vien: ";
        cin >> n;

        a = new cNhanVienVP[n];

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
            tong += a[i].getLuong();

        return tong;
    }

    void luongCaoNhat() {

        double max = a[0].getLuong();

        for (int i = 1; i < n; i++)
            if (a[i].getLuong() > max)
                max = a[i].getLuong();

        for (int i = 0; i < n; i++)
            if (a[i].getLuong() == max)
                a[i].xuat();
    }

    void sapXepTangLuong() {

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i].getLuong() > a[j].getLuong())
                    swap(a[i], a[j]);
    }
};

int main() {

    cListNhanVienVP ds;

    ds.nhap();

    cout << "\nDanh sach nhan vien:\n";
    ds.xuat();

    cout << "\nTong luong cong ty phai tra: ";
    cout << ds.tongLuong();

    cout << "\n\nNhan vien co luong cao nhat:\n";
    ds.luongCaoNhat();

    ds.sapXepTangLuong();

    cout << "\nDanh sach sau sap xep tang luong:\n";
    ds.xuat();

    return 0;
}
