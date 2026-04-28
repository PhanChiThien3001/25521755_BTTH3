// ======================= BÀI 6 HOÀN CHỈNH =======================

#include <iostream>
#include <algorithm>
using namespace std;

class cCandidate {
private:
    string ma, ten, ns;
    float toan, van, anh;

public:
    void nhap() {

        cin.ignore();

        cout << "Nhap ma: ";
        getline(cin, ma);

        cout << "Nhap ten: ";
        getline(cin, ten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ns);

        cout << "Nhap diem Toan Van Anh: ";
        cin >> toan >> van >> anh;
    }

    void xuat() {

        cout << ma << " - "
             << ten << " - "
             << ns << " - "
             << tongDiem() << endl;
    }

    float tongDiem() {
        return toan + van + anh;
    }
};

class cListCandidate {
private:
    int n;
    cCandidate *a;

public:

    ~cListCandidate() {
        delete[] a;
    }

    void nhap() {

        cout << "Nhap so thi sinh: ";
        cin >> n;

        a = new cCandidate[n];

        for (int i = 0; i < n; i++) {

            cout << "\nThi sinh " << i + 1 << ":\n";
            a[i].nhap();
        }
    }

    void xuat() {

        for (int i = 0; i < n; i++)
            a[i].xuat();
    }

    void xuatLonHon15() {

        for (int i = 0; i < n; i++)
            if (a[i].tongDiem() > 15)
                a[i].xuat();
    }

    void diemCaoNhat() {

        float max = a[0].tongDiem();

        for (int i = 1; i < n; i++)
            if (a[i].tongDiem() > max)
                max = a[i].tongDiem();

        for (int i = 0; i < n; i++)
            if (a[i].tongDiem() == max)
                a[i].xuat();
    }

    void sapXepTang() {

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i].tongDiem() > a[j].tongDiem())
                    swap(a[i], a[j]);
    }
};

int main() {

    cListCandidate ds;

    ds.nhap();

    cout << "\nDanh sach thi sinh:\n";
    ds.xuat();

    cout << "\nThi sinh co tong diem > 15:\n";
    ds.xuatLonHon15();

    cout << "\nThi sinh co diem cao nhat:\n";
    ds.diemCaoNhat();

    ds.sapXepTang();

    cout << "\nDanh sach sau sap xep tang:\n";
    ds.xuat();

    return 0;
}
