#include <iostream>
#include <cstring>
#include <cmath>

class point
{
public:
	double x, y;
	point(double a = 0.0, double b = 0.0)
	{
		x = a;
		y = b;
	}
	point(const point &r)
	{
		x = r.x;
		y = r.y;
	}
	point operator=(const point &r)
	{
		x = r.x;
		y = r.y;
	}
	void set()
	{
		std::cin >> x >> y;
	}
	void print()
	{
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}
};

class trn
{
	point A, B, C;
	double xin, yin;
	static int count;
	char ID;
	float S, P;
	int tcount;

public:
	trn(point v1, point v2, point v3, char id)
	{
		A = v1;
		B = v2;
		C = v3;
		++count;
		ID = id;
		tcount = count;
	}
	trn(const point &v1, const point &v2, const point &v3)
	{
		A = v1;
		B = v2;
		C = v3;
		++count;
		tcount = count;
	}
	trn()
	{
		A = (0.0, 0.0);
		B = (0.0, 0.0);
		C = (0.0, 0.0);
		++count;
		ID = 'N';
		tcount = count;
	}
	~trn()
	{
	}
	void settrn()
	{
		std::cout << "Triangle " << ID << "\n";
		std::cout << "Enter coords: " << std::endl;
		std::cout << "A: ";
		std::cin >> xin >> yin;
		A.x = xin;
		A.y = yin;
		std::cout << "B: ";
		std::cin >> xin >> yin;
		B.x = xin;
		B.y = yin;
		std::cout << "C: ";
		std::cin >> xin >> yin;
		C.x = xin;
		C.y = yin;
	}
	double d(point &obj1, point &obj2)
	{
		double tmp = 0;
		tmp = sqrt(abs(pow(abs((obj2.x - obj1.x)), 2) - pow(abs((obj2.y - obj1.y)), 2)));
		return tmp;
	}
	void print()
	{
		std::cout << "Triangle " << ID << ": " << std::endl;
		A.print();
		B.print();
		C.print();
		par();
		std::cout << "P (" << ID << ") " << P << std::endl;
		std::cout << "S (" << ID << ") " << S << std::endl;
		std::cout << "\nCount = " << tcount << std::endl;
	}
	void move(int xin, int yin)
	{
		A.x += xin;
		A.y += yin;
		B.x += xin;
		B.y += yin;
		C.x += xin;
		C.y += yin;
	}
	void par()
	{
		double a, b, c;
		float p;
		a = sqrt(abs((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)));
		b = sqrt(abs((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y)));
		c = sqrt(abs((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y)));
		P = (a + b + c) / 3;
		p = P / 2;
		S = sqrt(abs(p * (p - a) * (p - b) * (p - c)));
	}
	void printpar()
	{
		std::cout << ID << ": P=" << P << ", S=" << S << "\n";
	}
	void type()
	{
		double a, b, c;
		if ((d(A, B)) > (d(B, C)) && (d(A, B) > (d(A, C))))
		{
			c = d(A, B);
			a = d(B, C);
			b = d(A, C);
		}
		if ((d(B, C)) > (d(A, B)) && (d(B, C) > (d(A, C))))
		{
			c = d(B, C);
			a = d(A, B);
			b = d(A, C);
		}
		if ((d(A, C)) > (d(A, B)) && (d(A, C) > (d(B, C))))
		{
			c = d(A, C);
			a = d(A, B);
			b = d(B, C);
		}
		if ((pow(c, 2) > (pow(a, 2) + pow(b, 2))))
			std::cout << ID << ": Obtuse triangle.\n";
		if ((pow(c, 2) == (pow(a, 2) + pow(b, 2))))
			std::cout << ID << ": Right triangle.\n";
		if ((pow(c, 2) < (pow(a, 2) + pow(b, 2))))
			std::cout << ID << ": Acute-angle triangle.\n";
	}
	bool check(const point &c)
	{
		trn d1(A, B, c);
		trn d2(B, C, c);
		trn d3(A, C, c);
		double s = S;
		d1.par();
		d2.par();
		d3.par();
		double s1 = d1.S;
		double s2 = d2.S;
		double s3 = d3.S;
		if (abs(s - (s1 + s2 + s3)) <= 0.01)
			return 1;
		return 0;
	}
	void isincluded(trn &obj)
	{
		if (check(obj.A) && check(obj.B) && check(obj.C))
			std::cout << ID << " include " << obj.ID << "\n";
		else
		{
			std::cout << ID << " not include " << obj.ID << "\n";
		}
	}
};

int trn::count = 0;

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
	trn tA(p1, p2, p3, 'A');
	trn tB(p1, p4, p8, 'B');
	trn tC(p1, p5, p6, 'C');
	trn tD(p1, p7, p8, 'D');
	trn pTria[] = {tA, tB, tC, tD};
	int x = 1;
	char a = 'a';
	while (x != 0)
	{
		std::cout << "1.Print.\n2.Shift.\n3.Parameters.\n4.IsIncluded.\n5.Types.\n6.Enter.\n0.Exit.\n\n";
		std::cin >> x;
		switch (x)
		{
		case 0:
			exit(1);
			break;
		case 1:
			for (int i = 0; i < 4; ++i)
				pTria[i].print();
			break;
		case 2:
			int xin, yin;
			std::cout << "Enter xin, yin: \n";
			std::cin >> xin >> yin;
			std::cout << "Apply to all? (y/n)\n";
			std::cin >> a;
			switch (a)
			{
			case 'y':
				for (int i = 0; i < 4; ++i)
					pTria[i].move(xin, yin);
				break;
			case 'n':
				int ind;
				std::cout << "Enter triangle ind:\n";
				std::cin >> ind;
				if (ind < 0 || ind > 3)
				{
					std::cout << "Incorrect ind.\n";
					break;
				}
				else
				{
					pTria[ind].move(xin, yin);
					break;
				}
			}
			break;
		case 3:
			for (int i = 0; i < 4; ++i)
				pTria[i].printpar();
			break;
		case 4:
			int ind, subind;
			std::cout << "Enter triangle ind:\n";
			std::cin >> ind;
			if (ind < 0 || ind > 3)
			{
				std::cout << "Incorrect ind.\n";
				break;
			}
			else
			{
				std::cout << "Enter subtriangle ind: \n";
				std::cin >> subind;
				pTria[ind].isincluded(pTria[subind]);
				break;
			}
			break;
		case 5:
			for (int i = 0; i < 4; ++i)
				pTria[i].type();
			break;
		case 6:
			std::cout << "Apply to all? (y/n)\n";
			std::cin >> a;
			switch (a)
			{
			case 'y':
				for (int i = 0; i < 4; ++i)
					pTria[i].settrn();
				break;
			case 'n':
				int ind;
				std::cout << "Enter triangle ind:\n";
				std::cin >> ind;
				if (ind < 0 || ind > 3)
				{
					std::cout << "Incorrect ind.\n";
					break;
				}
				else
				{
					pTria[ind].settrn();
					break;
				}
			}
			break;
		default:
			std::cout << "Error.\n";
			break;
		}
	}
	system("pause");
	return 0;
}