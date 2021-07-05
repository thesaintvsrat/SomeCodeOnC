#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

class point
{
public:
    double x, y;
    point(double x1 = 0, double y1 = 0)
    {
        x = x1;
        y = y1;
    }
    void print()
    {
        cout << "(" << x << ", " << y << endl;
    }
};

class Triangle
{
private:
    char *objID;
    char *name;
    point v1, v2, v3;
    double a;
    double b;
    double c;

public:
    static int count;
    Triangle(point var1, point var2, point var3, const char *id)
    {
        v1 = var1;
        v2 = var2;
        v3 = var3;
        char buf[16];
        objID = new char[strlen(id) + 1];
        strcpy(objID, id);
        ++count;
        cout << buf << "Triangle #" << count;
        a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
        b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
        c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));
        cout << " Constructor_1 for: " << objID << " (" << name << ") " << endl;
    }
    Triangle(const char *ident)
    {
        char buf[16];
        objID = new char[strlen(ident) + 1];
        strcpy(objID, ident);
        count++;
        cout << "Triangle #" << count;
        name = new char[strlen(ident) + 1];
        strcpy(name, ident);
        a = b = c = 0;
        cout << "Constructor_2 for: " << objID << "(" << name << ")" << endl;
    }
    ~Triangle()
    {
        cout << "Destructor for: " << objID << endl;
        delete[] objID;
        delete[] name;
    }
    void print()
    {
        cout << name << ":" << endl;
        v1.print();
        v2.print();
        v3.print();
    }
    void ShowSideAndArea()
    {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << " --- " << endl;
        cout << name << ":";
        cout.precision(4);
        cout << " a= " << setw(5) << a;
        cout << ". b= " << setw(5) << b;
        cout << ". c= " << setw(5) << c;
        cout << ";\ts= " << s << endl;
    }
    void move()
    {
        int xin, yin;
        xin = yin = 0;
        cout << "Enter x, y: \n";
        cin >> xin >> yin;
        v1.x += xin;
        v1.y += yin;
        v2.x += xin;
        v2.y += yin;
        v3.x += xin;
        v3.y += yin;
    }
    void move(int xin, int yin)
    {
        v1.x += xin;
        v1.y += yin;
        v2.x += xin;
        v2.y += yin;
        v3.x += xin;
        v3.y += yin;
    }
};
int Triangle::count = 0;
int Menu();
int GetNumber(int, int);
void ExitBack();
void Show(Triangle[], int);
void FindMax(Triangle *[], int);
void IsIncluded(Triangle *[], int);
int main()
{
    point p1(0, 0);
    point p2(0.5, 1);
    point p3(1, 0);
    point p4(0, 4.5);
    point p5(2, 1);
    point p6(2, 0);
    point p7(2, 2);
    point p8(3, 0);
    Triangle triaA(p1, p2, p3, "triaA");
    Triangle triaB(p1, p4, p8, "triaB");
    Triangle triaC(p1, p5, p6, "triaC");
    Triangle triaD(p1, p7, p8, "triaD");
    Triangle pTria[] = {triaA, triaB, triaC, triaD};
    int n = sizeof(pTria) / sizeof(pTria[0]);
    int x = 0;
    char a = 'a';
    while (x != 5)
    {
        switch (Menu())
        {
        case 1:
            Show(pTria, n);
            break;
        case 2:
            cout << "Apply to all? (y/n)\n";
            cin >> a;
            switch (a)
            {
            case 'y':
                int xin, yin, ind;
                cout << "Enter x, y: \n";
                cin >> xin >> yin;
                cout << "Enter triangle ind:\n";
                cin >> ind;
                if (ind < 1 || ind > 5)
                {
                    cout << "Incorrect ind.\n";
                    break;
                }
                else
                    pTria[ind].move(xin, yin);
                break;
            case 'n':
                for (int i = 0; i < n; ++i)
                    pTria[i].move();
                break;
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            exit(1);
            break;
        }
    }
}

int Menu()
{
    int a = 0;
    while (a < 1 || a > 5)
    {
        cout << "1.Print.\n2.Shift.\n3.FindMax.\n4.IsIncluded.\n5.Exit.\n\n";
        cin >> a;
    }
    return a;
}
void Show(Triangle *p_tria, int k)
{
    for (int i = 0; i < k; ++i)
        p_tria[i].print();
    for (int i = 0; i < k; ++i)
        p_tria[i].ShowSideAndArea();
}