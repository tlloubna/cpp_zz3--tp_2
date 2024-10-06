#include <iostream>
#include "polaire.hpp"
#include <cmath>
#include "cartesien.hpp"
Polaire::Polaire():angle(0),rayon(0){}
Polaire::Polaire(double angle,double rayon):angle(angle),rayon(rayon){}

double Polaire::getAngle() const {return angle;}
void Polaire::setAngle(double angle2){ angle=angle2;}

double Polaire::getDistance() const {return rayon;}
void Polaire::setDistance(double d){rayon=d; }

void Polaire::afficher(std::ostream & os ) const {
    os << "(a=" << angle << ";d=" << rayon <<")"; // Implémentation de la méthode
}

void Polaire::convertir(Cartesien & c) const{
    c.setX(getDistance()*std::cos(getAngle()*M_PI/180));
    c.setY(getDistance()*std::sin(getAngle()*M_PI/180));
}  
Polaire::Polaire(const Cartesien & c){
    angle=std::atan2(c.getY(),c.getX())*180/M_PI;
    rayon=std::hypot(c.getX(),c.getY());
} 