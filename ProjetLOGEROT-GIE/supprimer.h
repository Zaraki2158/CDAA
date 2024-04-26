#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include "gestioncontact.h"
#include <QWidget>

namespace Ui {
class Supprimer;
}

/**
 * @brief La classe Supprimer est utilisée pour supprimer des contacts.
 *
 * Elle hérite de QWidget.
 */
class Supprimer : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe Supprimer.
     *
     * @param parent Widget parent (par défaut nullptr).
     * @param g Objet de type GestionContact (par défaut GestionContact()).
     */
    explicit Supprimer(QWidget *parent = nullptr, GestionContact g = GestionContact());

    /**
     * @brief Destructeur de la classe Supprimer.
     */
    ~Supprimer();

    GestionContact tempgs; ///< Stocke temporairement les contacts.
    GestionContact gs;     ///< Gestionnaire de contacts.

signals:
    /**
     * @brief Signal émis pour supprimer un contact.
     *
     * @param c Contact à supprimer.
     */
    void envoiSupr(Contact c);

private slots:
    /**
     * @brief Méthode appelée lors de la modification du champ du nom.
     *
     * @param arg1 Nouvelle valeur du champ de texte.
     */
    void on_NomE_textChanged(const QString &arg1);

    /**
     * @brief Méthode appelée lors de la modification du champ du prénom.
     *
     * @param arg1 Nouvelle valeur du champ de texte.
     */
    void on_PrenomE_textChanged(const QString &arg1);

    /**
     * @brief Méthode appelée lors du clic sur le bouton "Supprimer".
     *
     * Si un seul contact est sélectionné, l'événement envoie ce contact et ferme la fenêtre.
     * Sinon, un message est affiché demandant de choisir un seul contact.
     */
    void on_Supprimer_2_clicked();

    /**
     * @brief Méthode appelée lors du clic sur le bouton "Annuler".
     *
     * Ferme la fenêtre actuelle.
     */
    void on_Annuler_clicked();

private:
    Ui::Supprimer *ui; ///< Interface utilisateur pour la classe Supprimer.
};

#endif // SUPPRIMER_H
