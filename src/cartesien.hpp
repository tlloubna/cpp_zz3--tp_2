#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP
#include "point.hpp"
#include "polaire.hpp"
#include <ostream>   

//class Polaire
class Cartesien:public Point{
    private:
        double x;
        double y;
    public :
        Cartesien();
        Cartesien(double x,double y);
        Cartesien(const Polaire & p);
        double getX() const ;
        void setX(double x);
        double getY()const ;
        void setY(double y);
        void afficher(std::ostream & os) const override ;
        friend std::ostream & operator<<(std::ostream & os ,Cartesien & c){
            c.afficher(os);
            return os;
        } 
       void convertir(Polaire &  ) const override ;
       void convertir(Cartesien & c) const override{
        c.setX(x);
        c.setY(y);
       } 
        Point * clone() const{ 
            return new Cartesien(*this);
        } 
};

#endif