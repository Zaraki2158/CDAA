#include "todo.h"
#include <iostream>

/**
 * @brief Constructeur de la classe Todo avec contenu et date.
 *
 * @param c Le contenu du Todo.
 * @param d La date du Todo.
 */
Todo::Todo(std::string c, struct Date d)
{
    setContenu(c);
    setDate(d);
}

/**
 * @brief Constructeur par défaut de la classe Todo.
 *
 * Initialise le contenu à "aucun contenu".
 */
Todo::Todo()
{
    contenu = "aucun contenu";
}

/**
 * @brief Accesseur pour obtenir le contenu du Todo.
 *
 * @return Le contenu du Todo.
 */
std::string Todo::getContenu() const
{
    return contenu;
}

/**
 * @brief Accesseur pour obtenir la date du Todo.
 *
 * @return La date du Todo.
 */
Date Todo::getDate() const
{
    return date;
}

/**
 * @brief Mutateur pour définir le contenu du Todo.
 *
 * @param c Le nouveau contenu du Todo.
 */
void Todo::setContenu(std::string c)
{
    contenu = c;
}

/**
 * @brief Mutateur pour définir la date du Todo.
 *
 * @param d La nouvelle date du Todo.
 */
void Todo::setDate(const struct Date d)
{
    this->date.annee = d.annee;
    this->date.mois = d.mois;
    this->date.jour = d.jour;
    this->date.heure = d.heure;
    this->date.min = d.min;
}

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher un Todo.
 *
 * @param os Le flux de sortie.
 * @param todo Le Todo à afficher.
 * @return Le flux de sortie mis à jour.
 */
std::ostream& operator<<(std::ostream& os, const Todo& todo)
{
    struct Date d = todo.getDate();
    os << "@Todo  " << todo.getContenu() << "  @Date" << d.jour << "/" << d.mois << "/" << d.annee;
    return os;
}
