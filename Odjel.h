#pragma once
#include <vector>
#include "Krevet.h"
class Odjel
{
private:
	char naziv[50];
	std::vector<Krevet> kreveti;
	static int maxBrKreveta;
public:
	Odjel();
	void setNaziv();
	void setKreveti();
	void setMaxBrKreveta();
	static int getMaxBrKreveta();
	char* getNaziv();
	void getKreveti();
	void PostaviOdjel();
	void smjestiPacijenta();
	void rezervisiKrevet();
	void oslobodiKrevet(int n);
	void ispisKreveta();
	~Odjel();

};

