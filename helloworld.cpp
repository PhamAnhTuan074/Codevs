#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

const int N = 10000;

using namespace std;
ifstream file_in;
ofstream file_out;

class Thisinh
{
private:
    string msv, hoten;
    float toan, ly, hoa, trungbinh;

public:
    void setmsv(string m)
    {
        if (m.length() > 10)
            msv = m.substr(0, 10);
        else
            msv = m;
    }
    string getmsv() { return msv; }

    void sethoten(string n)
    {
        if (n.length() > 25)
            hoten = n.substr(0, 25);
        else
            hoten = n;
    }
    string gethoten() { return hoten; }

    void settoan(float t) { toan = t; }
    float gettoan() { return toan; }

    void setly(float t) { ly = t; }
    float getly() { return ly; }

    void sethoa(float t) { hoa = t; }
    float gethoa() { return hoa; }

    void settb() { trungbinh = 1.0 * (toan * 3 + ly * 2 + hoa) / 6; }
    float gettb() { return trungbinh; }

    Thisinh();
    void Init();
    bool Check();
    void show();
    ~Thisinh();
};

Thisinh::Thisinh()
{
    setmsv("N/A");
    sethoten("N/A");
    settoan(-1);
    setly(-1);
    sethoa(-1);
    settb();
}

bool Thisinh::Check()
{
    if (gettb() >= 5.0 && gettoan() > 0.0 && getly() > 0.0 && gethoa() > 0.0)
        return true;
    else
        return false;
}

void Thisinh::show()
{
    file_out << left << "| " << setw(10) << getmsv()
             << " | " << setw(30) << gethoten()
             << " | " << setw(4) << gettoan()
             << " | " << setw(4) << getly()
             << " | " << setw(4) << gethoa()
             << " |\n";
}

Thisinh::~Thisinh() {}

int main()
{

    file_in.open("Thisinh.txt", ios::in);
    if (!file_in)
    {
        cout << "Thisinh.txt : Open fail!\n";
        return 2;
    }

    int n = 0;
    string tmp;

    Thisinh *TS = new Thisinh[N];

    while (getline(file_in, tmp))
    {
        stringstream ss(tmp);
        string ms, name;
        float Toan, Ly, Hoa;

        ss >> ms;
        TS[n].setmsv(ms);

        string temp;

        while (ss >> temp)
        {

            if (isdigit(temp[0]))
            {
                Toan = stof(temp);
                break;
            }

            name += temp;
            name += ' ';
        }

        TS[n].sethoten(name);

        ss >> Ly >> Hoa;

        TS[n].settoan(Toan);
        TS[n].setly(Ly);
        TS[n].sethoa(Hoa);

        n++;
    }

    file_in.close();

    file_out.open("Thisinh.dat", ios::binary);
    for (int i = 0; i < n; i++)
    {
        TS[i].settb();
        if (TS[i].Check())
            TS[i].show();
    }

    file_out.close();
    delete[] TS;

    return 0;
}