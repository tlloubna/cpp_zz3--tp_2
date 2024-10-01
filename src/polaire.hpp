#ifndef POLAIRE_HPP
#define POLAIRE_HPP
#include "point.hpp"
#include <ostream>   

class Cartesien;

class Polaire:public Point{
    private:
        double angle;
        double rayon;
    public :
        Polaire();
        Polaire(double angle,double rayon);
        Polaire(const Cartesien & c);
        double getAngle() const ;
        void setAngle(double Anlge2);
        double getDistance()const ;
        void setDistance(double d);
        void afficher(std::ostream & os) const override ;
        friend std::ostream & operator<<(std::ostream & os ,Polaire & p) {
            p.afficher(os);
            return os;
        } 
       void convertir(Cartesien & c )const override ;
        void convertir(Polaire & p) const override{
            p.setAngle(angle);
            p.setDistance(rayon);
        }  
        Point * clone() const{ 
            return new Polaire(*this);
        } 
        
};

#endif