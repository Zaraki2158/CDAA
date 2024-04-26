#ifndef INTERACTIONSTODO_H
#define INTERACTIONSTODO_H

#include <QWidget>
#include "gestioncontact.h"

/**
 * @brief La classe InteractionsTodo gère l'interface pour créer des interactions avec des contacts.
 */
namespace Ui {
class InteractionsTodo;
}

class InteractionsTodo : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe InteractionsTodo.
     * @param parent Le widget parent.
     * @param g Objet de type GestionContact utilisé pour initialiser l'objet InteractionsTodo.
     */
    explicit InteractionsTodo(QWidget *parent = nullptr, GestionContact g = GestionContact());

    GestionContact tempgs; ///< Gestion temporaire des contacts.
    GestionContact gs; ///< Gestion des contacts.
    int nbTodo = 0; ///< Compteur de tâches à faire.
    std::list<Todo> lstTodo; ///< Liste des tâches à faire.

    ~InteractionsTodo();

signals:
    /**
     * @brief Signal émis lorsqu'une interaction avec un contact est envoyée.
     * @param c Objet de type Contact concerné par l'interaction.
     * @param i Objet de type Interaction à envoyer.
     */
    void EnvoiInteract(Contact c, Interaction i);

private slots:
    /**
     * @brief Méthode appelée lors du changement de texte dans le champ NomE_3.
     * @param arg1 Le texte modifié.
     */
    void on_NomE_3_textChanged(const QString &arg1);

    /**
     * @brief Méthode appelée lors du changement de texte dans le champ PrenomE_3.
     * @param arg1 Le texte modifié.
     */
    void on_PrenomE_3_textChanged(const QString &arg1);

    /**
     * @brief Méthode appelée lors du clic sur le bouton AjoutTodo.
     * Ajoute un élément Todo à une liste.
     */
    void on_AjoutTodo_clicked();

    /**
     * @brief Méthode appelée lors du clic sur le bouton Interact.
     * Émet un signal si un seul contact est sélectionné et qu'un texte est présent dans InteractionsE.
     * Sinon, affiche un message d'erreur.
     */
    void on_Interact_clicked();

private:
    Ui::InteractionsTodo *ui; ///< Interface utilisateur associée à la classe InteractionsTodo.
};

#endif // INTERACTIONSTODO_H
