#ifndef NUAGE_HPP
#define NUAGE_HPP

#include "point.hpp"
#include "cartesien.hpp"
#include <vector>
template <typename T> //On peut l'utiliser avec n'importe quel type soit un catesien ou bien un polaire

class Nuage{
    private :
    //gestion dynamique des points ={polaire,cartesien}
    //acces rapide
        std::vector<T> points;//stockage des points
    public:
        using iterator =typename std::vector<T>::iterator;
        using const_iterator=typename std::vector<T>::const_iterator;
        Nuage()=default;
        //l'ajout des points 
        void ajouter(const T & t) {
            points.push_back(t);
        }
        //la taille
        std::size_t size() const {
            return points.size();
        }
        //le pointeur de debut et de fin :
        //parcourir et modifie les éléments qu'il pointe
        iterator begin() {return points.begin();}
        iterator end() {return points.end();}
        //les points de fin et de debut constante
        //parcourir les elements qu'il pointe sans 
        //modifier ce qu'il pointe
        const_iterator begin() const {return points.begin();}
        const_iterator end() const {return points.end();}
};
template <typename T_points>
T_points barycentre_v1(const Nuage<T_points>& nuage) {
    // Vérifier si le nuage est vide
    if (nuage.size() == 0) {
        // Retourner un point nul
        return T_points(0, 0);
    }

    // Initialiser les sommes des coordonnées
    Cartesien Cartesien_point;
    double sumX = 0.0;
    double sumY = 0.0;
    
    for (const auto& point : nuage) {
        // On vérifie si ce type est polaire, on le convertit
        point.convertir(Cartesien_point);
        sumX += Cartesien_point.getX();
        sumY += Cartesien_point.getY();
        
    }

    double bar_X = sumX / nuage.size();
    double bar_Y = sumY / nuage.size();

    // On retourne avec le même type qu'on veut Polaire
    
   return T_points(Cartesien(bar_X,bar_Y));
}

//Polaire
template <>
Polaire barycentre_v1<Polaire>(const Nuage<Polaire> & nuage) {
    // Vérifier si le nuage est vide
    if (nuage.size() == 0) {
        // Retourner un point nul
        return Polaire(0, 0);
    }
    double a=0;
    double b=0;
    int n=0;
    for (const Polaire &points:nuage) {
        a+=points.getAngle();
        b+=points.getDistance();
        ++n;
        
    }
    return Polaire(a/n,b/n);
    
    
}

#endif

