#include "historique.h"

/**
 * @brief Constructeur de la classe Historique.
 * @param m La description de la modification.
 */
Historique::Historique(std::string m)
{
    this->date = Date(); // Initialise la date de l'historique.
    this->modif = m;    // Initialise la description de la modification.
}

/**
 * @brief Constructeur de la classe Historique.
 * @param m La description de la modification.
 * @param date la date de l'historique
 */

Historique::Historique(std::string m, Date date)
{
    this->date.jour = date.jour;
    this->date.mois = date.mois;
    this->date.annee = date.annee;// Initialise la date de l'historique.
    this->modif = m;    // Initialise la description de la modification.
}

/**
 * @brief Affiche les détails de l'historique, y compris la date et la description de la modification.
 */
std::string Historique::Affichage()
{
    std::stringstream ss;
    // Affiche la date au format jour/mois/année heure:minute, suivi de la description de la modification.
    ss << this->date.jour << "/" << this->date.mois << "/" << this->date.annee << " "<< this->date.heure << ":" << this->date.min << "  :  " << this->modif << std::endl;
    return ss.str();
}
