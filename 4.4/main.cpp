// ======================= BÀI 4 HOÀN CHỈNH =======================

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

class cArray {
private:
    int n;
    int *a;

    bool nguyenTo(int x) {
        if (x < 2)
            return false;

        for (int i = 2; i <= x / 2; i++)
            if (x % i == 0)
                return false;

        return true;
    }

public:
    ~cArray() {
        delete[] a;
    }

    void taoMangNgauNhien(int n) {
        this->n = n;

        a = new int[n];

        srand(time(0));

        for (int i = 0; i < n; i++)
            a[i] = rand() % 100;
    }

    void xuat() {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }

    int demX(int x) {
        int dem = 0;

        for (int i = 0; i < n; i++)
            if (a[i] == x)
                dem++;

        return dem;
    }

    bool tangDan() {
        for (int i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1])
                return false;

        return true;
    }

    int leNhoNhat() {
        int min = 1e9;

        for (int i = 0; i < n; i++)
            if (a[i] % 2 != 0 && a[i] < min)
                min = a[i];

        return min;
    }

    int nguyenToLonNhat() {
        int max = -1;

        for (int i = 0; i < n; i++)
            if (nguyenTo(a[i]) && a[i] > max)
                max = a[i];

        return max;
    }

    void sapXepTang() {
        sort(a, a + n);
    }

    void sapXepGiam() {
        sort(a, a + n, greater<int>());
    }
};

int main() {
    cArray a;

    a.taoMangNgauNhien(10);

    cout << "Mang:\n";
    a.xuat();

    cout << "\nSo lan xuat hien cua 5: ";
    cout << a.demX(5);

    cout << "\nMang tang dan? ";

    if (a.tangDan())
        cout << "Co";
    else
        cout << "Khong";

    cout << "\nLe nho nhat: ";
    cout << a.leNhoNhat();

    cout << "\nSo nguyen to lon nhat: ";
    cout << a.nguyenToLonNhat();

    a.sapXepTang();

    cout << "\nMang tang dan:\n";
    a.xuat();

    a.sapXepGiam();

    cout << "\nMang giam dan:\n";
    a.xuat();

    return 0;
}
