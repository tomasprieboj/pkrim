#include "Mzda.h"

/*
double hrubaDobule = Convert::ToDouble(hruba_mzda->Text);
				double poistne = hrubaDobule * 0.134;
				double ciastkovyZakladDane = hrubaDobule - poistne;
				double nezanitelnaCast = 316.94;
				double zdanitelnaMzda = ciastkovyZakladDane - nezanitelnaCast;
				double dan = zdanitelnaMzda * 0.19;
				double cistaMzda = hrubaDobule - poistne - dan;

*/
Mzda::Mzda(void)
{
}

Mzda::Mzda(double hrubaMzda){
	this->hrubaMzda = hrubaMzda;
	this->nezanitelnaCast = 316.94;
}

void Mzda::calculate(){
	this->setPoistne(this->getHrubaMzda());
	this->setCiastkovyZakladDane(this->getHrubaMzda(), this->getPoistne());
	this->setZdanitelnaMzda(this->getCiastkovyZakladDane(), this->getNezanitelnaCast());
	this->setDan(this->getZdanitelnaMzda());
}
void Mzda::setPoistne(double hruba){
	this->poistenie = hruba * 0.134;
}

void Mzda::setCiastkovyZakladDane(double hruba, double poistne){
	this->ciastkovyZakladDane = hruba - poistne;
}
void Mzda::setZdanitelnaMzda(double ciastkovyZakladDane, double nezanitelnaCast){
	this->zdanitelnaMzda = ciastkovyZakladDane - nezanitelnaCast;
}

void Mzda::setDan(double zdanitelnaMzda){
	this->dan = zdanitelnaMzda * 0.19;
}

double Mzda::getHrubaMzda(){
	return this->hrubaMzda;
}

double Mzda::getCiastkovyZakladDane(){
	return this->ciastkovyZakladDane;
}

double Mzda::getNezanitelnaCast(){
	return this->nezanitelnaCast;
}

double Mzda::getZdanitelnaMzda(){
	return this->zdanitelnaMzda;
}

double Mzda::getDan(){
	return this->dan;
}

double Mzda::getCistaMzda(){
	return (this->getHrubaMzda() - this->getPoistne() - this->getDan());
}

