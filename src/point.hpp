#ifndef POINT_HPP
#define POINT_HPP
class Polaire;
class Cartesien;
#include <ostream>   

class Point{
    public:
        virtual void  afficher(std::ostream & os) const=0;
        
        virtual void convertir(Cartesien & c) const=0;
        virtual void convertir(Polaire & p) const=0;
        virtual Point * clone() const =0;
        friend std::ostream &  operator<<(std::ostream & os,const Point &p){
            p.afficher(os);
            return os;
        }
        virtual~ Point(){} 
        
        
};

#endif
