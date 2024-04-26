#include "interaction.h"

/**
 * @brief Constructeur par défaut de la classe Interaction.
 */
Interaction::Interaction()
{
    date.getCourante();
}

/**
 * @brief Constructeur surchargé de la classe Interaction.
 *
 * @param c Le contenu de l'interaction.
 * @param d La date de l'interaction.
 */
Interaction::Interaction(const std::string& c, const struct Date d)
{
    this->setDate(d);
    this->setContenu(c);
}

/**
 * @brief Destructeur de la classe Interaction.
 *
 * Ici, vous pourriez désallouer des ressources si nécessaire.
 */
Interaction::~Interaction()
{
}

/**
 * @brief Accesseur pour obtenir la date de l'interaction.
 *
 * @return La date de l'interaction.
 */
struct Date Interaction::getDate() const { return date; }

/**
 * @brief Accesseur pour obtenir le contenu de l'interaction.
 *
 * @return Le contenu de l'interaction.
 */
std::string Interaction::getContenu() const { return contenu; }

/**
 * @brief Accesseur pour obtenir la liste de Todos de l'interaction.
 *
 * @return La liste de Todos de l'interaction.
 */
std::vector<Todo> Interaction::getListe() const { return lstTodo; }

/**
 * @brief Mutateur pour définir la date de l'interaction.
 *
 * @param d La nouvelle date de l'interaction.
 */
void Interaction::setDate(const struct Date d) { date = d; }

/**
 * @brief Mutateur pour définir le contenu de l'interaction.
 *
 * @param c Le nouveau contenu de l'interaction.
 */
void Interaction::setContenu(const std::string& c) { contenu = c; }

/**
 * @brief Ajoute un Todo à la liste de Todos de l'interaction.
 *
 * @param t Le Todo à ajouter.
 */
void Interaction::ajouteTodo(Todo t)
{
   lstTodo.push_back(t);
}

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher une Interaction.
 *
 * @param os Le flux de sortie.
 * @param i L'interaction à afficher.
 * @return Le flux de sortie mis à jour.
 */
std::ostream& operator<<(std::ostream& os, const Interaction& i)
{
    struct Date d = i.getDate();
    os << "Interaction : " << d.jour << "/" << d.mois << "/" << d.annee << " " << i.getContenu() << std::endl << "(" << std::endl;
    int j=0;
    for(const Todo& Todo : i.lstTodo)
    {
        j++;
        os << "Todo " << j << ": " << Todo << std::endl;
    }
    os << ")" << std::endl;
    return os;
}
