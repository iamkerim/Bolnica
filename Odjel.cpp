#include "Odjel.h"
#include <iostream>
#include <vector>
using std::cout;
using std::cin;

int Odjel::maxBrKreveta = 0;

Odjel::Odjel()
{
	strcpy_s(this->naziv, "Novi odjel");
	Odjel::maxBrKreveta = 0;
}

void Odjel::setNaziv()
{
	cout << "Unesite naziv odjela: ";
	cin.getline(this->naziv, 50);
}

void Odjel::setKreveti()
{	
	std::shared_ptr<Krevet> temp = std::make_shared<Krevet>();

	for (int i = 0; i < Odjel::maxBrKreveta; i++) {
		temp->postaviKrevet(i, slobodno);
		this->kreveti.push_back(*temp);
	}
}

void Odjel::setMaxBrKreveta()
{
	cout << "Unesite broj kreveta na odjelu: ";
	cin >> Odjel::maxBrKreveta;
	cin.ignore();
}

int Odjel::getMaxBrKreveta()
{
	return Odjel::maxBrKreveta;
}

char* Odjel::getNaziv()
{
	return this->naziv;
}

void Odjel::getKreveti()
{
}

void Odjel::PostaviOdjel()
{
	setNaziv();
	setMaxBrKreveta();
	setKreveti();
}

void Odjel::smjestiPacijenta()
{
	bool smjesten = false;
	try {
		for (int i = 0; i < this->kreveti.size(); i++) {
			if (this->kreveti[i].getStatus() == slobodno && !smjesten) {
				this->kreveti[i].setStatus(zauzeto);
				cout << "Pacijent je uspjesno smjesten.\n";
				smjesten = true;
			}
		}
		if (!smjesten) {
			throw "Svi kreveti zauzeti!\n";
		}
	}
	catch (const char* Greska) {
		cout << "[GRESKA] " << Greska << "\n";
	}
	catch (...) {
		cout << "[GRESKA] Nepoznata greska!\n";
	}
}

void Odjel::rezervisiKrevet()
{

	bool smjesten = false;
	try {
		for (int i = 0; i < this->kreveti.size(); i++) {
			if (this->kreveti[i].getStatus() == slobodno && !smjesten) {
				this->kreveti[i].setStatus(rezervisano);
				cout << "Krevet je uspjesno rezervisan.\n";
				smjesten = true;
			}
		}
		if (!smjesten) {
			throw "Svi kreveti zauzeti!\n";
		}
	}
	catch (const char* Greska) {
		cout << "[GRESKA] " << Greska << "\n";
	}
	catch (...) {
		cout << "[GRESKA] Nepoznata greska!\n";
	}
}

void Odjel::oslobodiKrevet(int n)
{
	try {
		if (n > Odjel::getMaxBrKreveta() || n < 1) {
			throw n;
		}
		else if (this->kreveti[n-1].getStatus() == slobodno) {
			throw "Taj krevet je vec slobodan!\n";
		}
		else if (this->kreveti[n-1].getStatus() == rezervisano) {
			throw "Taj krevet je rezervisan!\n";
		}
		else {
			this->kreveti[n-1].setStatus(slobodno);
			cout << "Krevet broj " << n << " je sada slobodan!\n";
		}
	}

	catch (int n) {
		cout << "[GRESKA] Ne postoji krevet sa brojem " << n << "!\n";
	}

	catch (const char* Greska) {
		cout << "[GRESKA] " << Greska << "\n";
	}

	catch (...) {
		cout << "[GRESKA] Nepoznata greska!\n";
	}
}

void Odjel::ispisKreveta() {
	cout << "Odjel " << this->getNaziv() << "\n";
	cout << "Broj\t\tStatus\n";
	cout << "kreveta\t\tkreveta\n";
	cout << "--------------------------------------\n";
	for (int i = 0; i < this->kreveti.size(); i++) {
		cout << i + 1 << "\t\t";
		if (this->kreveti[i].getStatus() == slobodno) {
			cout << "Slobodan\n";
		}else if(this->kreveti[i].getStatus() == slobodno) {
			cout << "Zauzet\n";
		}
		else {
			cout << "Rezervisan\n";
		}
	}
}

Odjel::~Odjel()
{
}
