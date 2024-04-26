#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <string>
#include "date.h"
#include "todo.h"

/**
 * @brief La classe Interaction représente une interaction avec une date, un contenu et une liste de tâches à faire.
 */
class Interaction {
private:

    std::string contenu; ///< Contenu de l'interaction.
    struct Date date; ///< Date de l'interaction.
    std::vector<Todo> lstTodo; ///< Liste de tâches associées à l'interaction.

public:
    // Constructeurs
    /**
     * @brief Constructeur par défaut.
     * Le contenu est vide et la date est la date courante.
     */
    Interaction();

    /**
     * @brief Constructeur avec contenu et date.
     * @param c Contenu de l'interaction.
     * @param d Objet de type Date représentant la date de l'interaction.
     */
    Interaction(const std::string& c, const struct Date d);

    // Destructeur
    ~Interaction();

    // Accesseurs
    /**
     * @brief Obtient la date de l'interaction.
     * @return Objet de type Date représentant la date de l'interaction.
     */
    struct Date getDate() const;

    /**
     * @brief Obtient le contenu de l'interaction.
     * @return Le contenu de l'interaction sous forme de chaîne de caractères.
     */
    std::string getContenu() const;

    /**
     * @brief Obtient la liste de tâches associées à l'interaction.
     * @return Vecteur contenant des objets de type Todo.
     */
    std::vector<Todo> getListe() const;

    // Mutateurs
    /**
     * @brief Définit la date de l'interaction.
     * @param d Objet de type Date représentant la date de l'interaction à définir.
     */
    void setDate(const struct Date d);

    /**
     * @brief Définit le contenu de l'interaction.
     * @param c Chaîne de caractères représentant le contenu de l'interaction à définir.
     */
    void setContenu(const std::string& c);

    // Méthodes
    /**
     * @brief Ajoute une tâche à faire à l'interaction.
     * @param t Objet de type Todo à ajouter à l'interaction.
     */
    void ajouteTodo(Todo t);

    /**
     * @brief Surcharge de l'opérateur de sortie pour l'affichage de l'interaction.
     * @param os Flux de sortie.
     * @param interaction Objet de type Interaction à afficher.
     * @return Le flux de sortie modifié avec les informations de l'interaction.
     */
    friend std::ostream& operator<<(std::ostream& os, const Interaction& interaction);
};

#endif // INTERACTION_H
