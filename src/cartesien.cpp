#include <iostream>
#include <cmath>
#include "cartesien.hpp"


Cartesien::Cartesien():x(0),y(0){}
Cartesien::Cartesien(double x,double y):x(x),y(y){}

double Cartesien::getX() const {return x;}
void Cartesien::setX(double  c){ x=c;}

double Cartesien::getY() const {return y;}
void Cartesien::setY(double  d){y=d; }

void Cartesien::afficher(std::ostream & os ) const {
    os << "(x=" << x<< ";y=" << y <<")"; // Implémentation de la méthode
}

void Cartesien::convertir(Polaire & p) const{
    p.setAngle(std::atan2(getY(),getX())*180/M_PI);
    
    p.setDistance(std::hypot(getX(),getY()));
} 
Cartesien::Cartesien(const Polaire & p){
     x=p.getDistance()*std::cos(p.getAngle()*M_PI/180);
     y=p.getDistance()*std::sin(p.getAngle()*M_PI/180);
} 