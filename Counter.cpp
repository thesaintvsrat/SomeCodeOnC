#include <iostream>
#include <vector>
#include <string>
using namespace std;

void enter(vector<string> &v)
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    v.push_back(name);
}

void printvec(vector<string> &v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << '\n';
}

void counter(vector<string> &v, int s)
{
    while (v.size() > 1)
        for (int i = 0; i < v.size(); ++i)
            if (s < v.size())
            {
                cout << v[s] << " left.\n";
                v.erase(v.begin() + s);
            }
            else
            {
                int s1 = s - v.size();
                if (s1 == 0)
                {
                    cout << v[s1] << " left.\n";
                    v.erase(v.begin());
                }
                else
                {
                    --s1;
                    cout << v[s1] << " left.\n";
                    v.erase(v.begin() + s1);
                }
            }
}

int main()
{
    vector<string> C;
    int k;
    char a;
    while (a != 'n')
    {
        cout << "Enter? (y/n)\n";
        cin >> a;
        switch (a)
        {
        case 'y':
            enter(C);
            break;
        case 'n':
            break;
        default:
            cout << "Error.\n";
            break;
        }
    }
    printvec(C);
    cout << "Enter k (step): ";
    cin >> k;
    counter(C, k);
    printvec(C);
    system("pause");
    return 0;
}