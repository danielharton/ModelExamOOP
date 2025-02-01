#include<iostream>
#include <fstream>
using namespace std;

class Locuinta {
public:
	int nameLength = 100;
	char* numeClient=NULL;
	
	int suprafataUtila=0;
	float discount=0;
public:

	Locuinta() {
		this->numeClient = new char[this->nameLength];
	}
	~Locuinta() {
		delete[]this->numeClient;
	}
	//pre incrementation
	Locuinta& operator++() {
		if (this->discount < 10)
			this->discount++;
		return *this;
	}
	//post incrementation
	Locuinta& operator++(int) {
		Locuinta temp = *this;
		if (this->discount < 10)
			this->discount++;
		
		return temp;
	}
	//pre decrementation
	Locuinta& operator--() {
		if (this->discount > 0)
			this->discount--;
		return *this;
	}
	//post decrementation
	Locuinta& operator--(int) {
		Locuinta temp = *this;
		if (this->discount > 0)
			this->discount--;
		return temp;
	}
	explicit operator int () {
		return this->suprafataUtila;
	}
};

class Apartament : public Locuinta {
	private:
	int etaj;
	
public:
	int getEtaj() {
		return this->etaj;
	}
	void setEtaj(const int& etaj) {
		if (etaj > 0)
			this->etaj = etaj;
		else
			throw exception("asdsa");
		
	}
};
class Casa : public Locuinta {
	public:
	int suprafataCurte=20;
	int nrEtaje=10;
	float* suprafataEtaje;

public:
	Casa():Locuinta() {
		this->suprafataEtaje = new float[this->nrEtaje];
	}
	~Casa() {
		delete[]this->suprafataEtaje;
	}
};

int main() {
	Locuinta l;
	cout<<(l++).discount;
	cout<<(++l).discount;
	cout<<(l--).discount;
	cout<<(--l).discount;
	cout << (int)l;
	
	Apartament a;
	Casa c;
	ifstream aFin("flats.txt");
	
	
	while (!aFin.eof()) {
		aFin.getline(a.numeClient, a.nameLength);
		aFin >> a.discount;
		aFin >> a.suprafataUtila;
		int etaj;
		aFin >>  etaj;
		a.setEtaj(etaj);
	}
	aFin.close();
	ifstream cFin("houses.txt");
	while (!cFin.eof()) {
		cFin.getline(c.numeClient, c.nameLength);
		cFin >> c.discount;
		cFin >> c.suprafataUtila;
		cFin >> c.suprafataCurte;
		cFin >> c.nrEtaje;
		for (int i = 0; i < c.nrEtaje; i++) {
			cFin >> c.suprafataEtaje[i];
		}
	}
	cFin.close();

	return 0;
}