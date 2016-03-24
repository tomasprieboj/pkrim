#include "Mzda.h"
#include <iostream>
#include <string>

Mzda::Mzda(void)
{
}

Mzda::Mzda(double hrubaMzda){
	this->hrubaMzda = hrubaMzda;
	this->nezanitelnaCast = 316.94;
}

Mzda::~Mzda(){
	
}
void Mzda::calculate(){
	this->setPoistne(this->getHrubaMzda());
	this->setCiastkovyZakladDane(this->getHrubaMzda(), this->getPoistne());
	this->setZdanitelnaMzda(this->getCiastkovyZakladDane(), this->getNezanitelnaCast());
	this->setDan(this->getZdanitelnaMzda());
}
void Mzda::setPoistne(double hruba){
	this->poistne = hruba * 0.134;
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

double Mzda::getPoistne(){
	return this->poistne;
}

double Mzda::getCistaMzda(){
	return (this->getHrubaMzda() - this->getPoistne() - this->getDan());
}

