#pragma once

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
	~Mzda();

private:
	
	double hrubaMzda;
	double ciastkovyZakladDane;
	double poistne;
	double nezanitelnaCast;
	double zdanitelnaMzda;
	double dan;
	double cistaMzda;
};


