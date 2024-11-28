#include<iostream>
#include<fstream>
#include<iomanip>

const int N = INT_MAX;

using namespace std;

class Thisinh{
    private:
        string msv, hoten;
        float toan, ly, hoa, trungbinh;

    public:
        void setmsv(string m) {msv = m;}
        string getmsv() {return msv;}

        void sethoten(string n) {hoten = n;}
        string gethoten() {return hoten;}

        void settoan(float t) {toan = t;}
        float gettoan() {return toan;}

        void setly(float t) {ly = t;}
        float getly() {return ly;}

        void sethoa(float t) {hoa = t;}
        float gethoa() {return hoa;}

        void settb() {trungbinh = 1.0*(toan*3 + ly*2 + hoa/6);}
        float gettb() {return trungbinh;}

        Thisinh();
        void Init();
        bool Check();
        void show();
        ~Thisinh();

};

Thisinh::Thisinh(){
    setmsv("N/A");
    sethoten("N/A");
    settoan(-1);
    setly(-1);
    sethoa(-1);
    settb();
}

bool Thisinh::Check(){
    if (trungbinh >=5.0 && toan >0.0 && ly>0.0 && hoa >0.0) 
        return true;
    else    
        return false;
}

void Thisinh::show(){
    cout <<"| " <<setw(10) <<msv 
	<<" | " <<setw(30) <<hoten 
	<<" | " <<setw(4) <<toan 
	<<" | " <<setw(4) <<ly 
	<<" | " <<setw(4) <<hoa 
	<<" |\n";
}
int main(){

    fstream file_in;
    file_in.open("Thisinh.txt", ios::in);
    if (!file_in){
        cout<<"Thisinh.txt : Open fail!\n";
        return 2;
    }

    int n =0;
    string tmp;

    Thisinh * TS = new Thisinh[N];
    while (getline(file_in,tmp)){
        stringstream ss(tmp);
        string ms, name;
        float Toan, Ly, Hoa;

        ss >> ms; TS[n].setmsv(ms);
        ss.ignore();
        getline(ss,name);   TS[n].sethoten(name);
        ss >> Toan >> Ly >> Hoa;
        TS[n].settoan(Toan);
        TS[n].setly(Ly);
        TS[n].sethoa(Hoa);
        n++;
    }
    file_in.close();

    // fstream file_out;
    // file_out.open("Thisinh.dat",ios::binary);
    // for ( int i =0; i<n;i++){
    //     if (TS[i].Check()){
    //         file_out.write((char *)&TS[i], sizeof(Thisinh));
    //     }
    // }
    // file_out.close();
    delete [] TS;
    return 1;

}