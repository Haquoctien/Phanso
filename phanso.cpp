#include <iostream>
using namespace std;

struct phanso
{
    int tu;
    int mau;
};
void xuatmangps(phanso *, int);
phanso nhapps(void);
void xuatps(phanso);
phanso cong(phanso, phanso);
bool amhayduong(phanso);
bool lonhon(phanso, phanso);
phanso dongian(phanso);
int ucln(int a, int b)
{
    while (a * b != 0)
    {
        if (a < b)
            b -= a;
        else
            a -= b;
    }
    return a + b;
}
phanso *nhapmangps(void);
phanso tongmangps(phanso *, int);
/// MAIN FUNCTION
int main(void)
{
    phanso *a = nhapmangps();
    xuatmangps(a, 3);
    cout << "Tong cac ps trong mang la: " << endl;
    xuatps(tongmangps(a, 3));
    return 0;
}

void xuatps(phanso frac)
{
    cout << frac.x << "/" << frac.y << endl;
}
phanso nhapps()
{
    int tu, mau;
    cout << "Nhap tu, mau: ";
    cin >> tu >> mau;
    phanso ans = {tu, mau};
    return ans;
}
phanso cong(phanso a, phanso b)
{
    phanso ans;
    ans.x = a.x*b.y + b.x*a.y;
    ans.y = a.y*b.y;
    return dongian(ans);
}
bool amhayduong(phanso a)
{
    if (a.x*a.y >= 0) return 1;
    else return 0;
}
phanso dongian(phanso a)
{
    int key = ucln(a.x, a.y);
    phanso ans = {a.x/key, a.y/key};
    return ans;
}
int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while(a*b > 0)
    {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return (a + b);
}
phanso* nhapmangps(void)
{
    int n;
    cout << "Nhap so phan so muon nhap vao mang: ";
    cin >> n;
    phanso* ans = new phanso[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap tu : ";
        cin >> (ans + i) -> x;
        cout << "Nhap mau: ";
        cin >> (ans + i) -> y; 
    }
    return ans;
}
void xuatmangps(phanso* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        xuatps(a[i]);
    }
}
phanso tongmangps(phanso* a, int n)
{
    phanso ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = cong(ans, a[i]);
    }
    return ans;
}