#ifndef TODO_H
#define TODO_H

#include "date.h"

/**
 * @brief La classe Todo représente une tâche avec un contenu et une date associée.
 */
class Todo
{
private:
    std::string contenu; ///< Contenu de la tâche.
    Date date;           ///< Date associée à la tâche.

public:
    /**
     * @brief Constructeur par défaut de la classe Todo.
     */
    Todo();

    /**
     * @brief Constructeur de la classe Todo prenant un contenu et une date.
     *
     * @param c Contenu de la tâche.
     * @param d Date associée à la tâche.
     */
    Todo(std::string c, struct Date d);

    /**
     * @brief Obtient le contenu de la tâche.
     *
     * @return Le contenu de la tâche.
     */
    std::string getContenu() const;

    /**
     * @brief Obtient la date associée à la tâche.
     *
     * @return La date associée à la tâche.
     */
    Date getDate() const;

    /**
     * @brief Modifie le contenu de la tâche.
     *
     * @param c Nouveau contenu de la tâche.
     */
    void setContenu(const std::string c);

    /**
     * @brief Modifie la date associée à la tâche.
     *
     * @param d Nouvelle date associée à la tâche.
     */
    void setDate(const struct Date d);

    /**
     * @brief Surcharge de l'opérateur de flux pour afficher une tâche.
     *
     * @param os Flux de sortie.
     * @param Todo Tâche à afficher.
     * @return Le flux de sortie mis à jour.
     */
    friend std::ostream& operator<<(std::ostream& os, const Todo& Todo);
};

#endif // TODO_H
