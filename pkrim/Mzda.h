#pragma once
#include <iostream>
#include <string>

using namespace std;

class Mzda{
public:
	Mzda(void);
	Mzda(double hrubaMzda);
	double getCistaMzda();
	void calculate();
	double getHrubaMzda();
	double getPoistne();
	double getCiastkovyZakladDane();
	double getNezanitelnaCast();
	double getZdanitelnaMzda();
	double getDan();
	void setPoistne(double val);
	void setCiastkovyZakladDane(double hruba, double poistne);
	void setZdanitelnaMzda(double ciastkovyZakladDane, double nezanitelnaCast);
	void setDan(double val);

private:
	
	double hrubaMzda;
	double ciastkovyZakladDane;
	double poistenie;
	double nezanitelnaCast;
	double zdanitelnaMzda;
	double dan;
	double cistaMzda;
};


