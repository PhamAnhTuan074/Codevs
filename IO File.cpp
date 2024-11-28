#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Thisinh {
	private:
		string msv;
		string hoten;
		float toan, ly, hoa, trungbinh;
	public:
		void setmsv(string m){ msv = m; }
		string getmsv(){ return msv; }
		void sethoten(string ht){ hoten = ht; }
		string gethoten(){ return hoten; }
		
		void settoan(float d){ toan = d; }
		float gettoan(){ return toan; }
		void setly(float d){ ly = d; }
		float getly(){ return ly; }
		void sethoa(float d){ hoa = d; }
		float gethoa(){ return hoa; }
		void settb(){ trungbinh = (toan*3 + ly*2 + hoa)/6; }
		float gettrungbinh(){ return trungbinh;}
		
		Thisinh(){
			setmsv("N/A");
			sethoten("N/A");
			settoan(-1);
			setly(-1);
			sethoa(-1);
			settb();
		}
		void Init(string m="N/A", string h="N/A", float t=-1, float l=-1,float hh=-1);
		void show();
};

void Thisinh::Init(string m, string h, float t, float l,float hh){
	setmsv(m);
	sethoten(h);
	settoan(t);
	setly(l);
	sethoa(hh);
	settb();
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
	int n=0;
	fstream sfile;
	sfile.open("N03.dat", ios::in);
	if (!sfile) {
		cout <<"N03.dat: Open fail!\n";
		return 2;
	}

	string myText;
	n = 0;
	while (getline (sfile, myText)) {
		n++;
		cout <<n <<": " << myText <<"\n";
	}
	Thisinh * ts = new Thisinh[n];
	int i=0;
	sfile.seekg(0,ios::beg);
	
	
	while (getline (sfile, myText)) {
		n++;
		cout <<n <<": " << myText <<"\n";
	}
cout <<n;
	
	sfile.close();

	delete [] ts;
	return 0;
}
