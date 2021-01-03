#include <iostream>
#include "Odjel.h"
using std::cout;
using std::cin;

int main() {
	Odjel o;
	o.PostaviOdjel();
	int izbor;
	do {
		system("cls");
		cout << "Odjel: " << o.getNaziv() << "\n";
		cout << "\t1. Ispis odjela\n";
		cout << "\t2. Prijava pacijenta\n";
		cout << "\t3. Rezervacija\n";
		cout << "\t4. Oslobodi krevet\n";
		cout << "\t5. Kraj\n";
		cout << "\t\tIzbor: ";
		cin >> izbor;
		cin.ignore();
		switch (izbor)
		{
		case 1:
			system("cls");
			o.ispisKreveta();
			system("pause");
			break;
		case 2:
			o.smjestiPacijenta();
			system("pause");
			break;
		case 3:
			o.rezervisiKrevet();
			system("pause");
			break;
		case 4:
			system("cls");
			o.ispisKreveta();
			int n;
			cout << "Unesite broj kreveta za odjavu: ";
			cin >> n;
			cin.ignore();
			o.oslobodiKrevet(n);
			system("pause");
			break;
		case 5:
			cout << "Hvala i dovidjena!\n";
			system("pause");
			break;
		default:
			cout << "Pogresan odabir\n";
			system("pause");
		}
	} while (izbor != 5);

	return 0;
}