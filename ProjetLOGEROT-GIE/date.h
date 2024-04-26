#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

/**
 * @brief Structure représentant une date.
 */
struct Date
{
    int jour;   /**< Jour. */
    int mois;   /**< Mois. */
    int annee;  /**< Année. */
    int heure;  /**< Heure. */
    int min;    /**< Minute. */

    /**
     * @brief Constructeur par défaut.
     * Initialise la date avec la date actuelle.
     */
    Date()
    {
        this->getCourante();
    }

    /**
     * @brief Obtient la date actuelle du système.
     */
    void getCourante() {
        std::time_t t = std::time(nullptr);
        std::tm* tmPtr = std::localtime(&t);

        this->jour = tmPtr->tm_mday;
        this->mois = tmPtr->tm_mon + 1;
        this->annee = tmPtr->tm_year + 1900;
        this->heure = tmPtr->tm_hour;
        this->min = tmPtr->tm_min;
    }

    /**
     * @brief Constructeur prenant une chaîne de caractères comme paramètre.
     * @param input Chaîne de caractères représentant la date au format "jour/mois/année".
     */
    Date(const std::string& input)
    {
        std::istringstream ss(input);
        std::string token;
        char delimiter = '/';
        int j, m, a;
        ss >> j >> delimiter >> m >> delimiter >> a;
        this->jour = j;
        this->mois = m;
        this->annee = a;
    }
};

#endif // DATE_H
