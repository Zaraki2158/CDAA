#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include "date.h"

/**
 * @brief La classe Historique représente un enregistrement d'une modification avec une date associée.
 */
class Historique {
private:
    struct Date date; ///< Date de l'enregistrement.
    std::string modif; ///< Description de la modification.

public:
    /**
     * @brief Constructeur prenant en paramètre une description de modification.
     * @param m Chaîne de caractères représentant la modification enregistrée.
     */
    Historique(std::string m);

    /**
     * @brief Constructeur prenant en paramètres une description de modification et une date.
     * @param m Chaîne de caractères représentant la modification enregistrée.
     * @param date Objet de type Date représentant la date de l'enregistrement.
     */
    Historique(std::string m, Date date);

    /**
     * @brief Obtient une représentation textuelle de l'enregistrement.
     * @return Chaîne de caractères décrivant l'enregistrement.
     */
    std::string Affichage();

    /**
     * @brief Obtient la date de l'enregistrement.
     * @return Objet de type Date représentant la date de l'enregistrement.
     */
    struct Date getDate() const { return date; }

    /**
     * @brief Obtient la description de la modification enregistrée.
     * @return Chaîne de caractères décrivant la modification enregistrée.
     */
    std::string getModif() const { return modif; }
};

#endif // HISTORIQUE_H
