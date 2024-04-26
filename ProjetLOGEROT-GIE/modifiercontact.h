#ifndef MODIFIERCONTACT_H
#define MODIFIERCONTACT_H

#include <QWidget>
#include "gestioncontact.h"
#include <QRegExpValidator>
#include <QFile>
#include "ui_modifiercontact.h"

/**
 * @brief La classe ModifierContact permet de modifier des contacts.
 *
 * Elle hérite de QWidget.
 */
class ModifierContact : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe ModifierContact.
     *
     * @param parent Widget parent (par défaut nullptr).
     * @param g Objet de type GestionContact (par défaut GestionContact()).
     */
    explicit ModifierContact(QWidget *parent = nullptr, GestionContact g = GestionContact());

    /**
     * @brief Destructeur de la classe ModifierContact.
     */
    ~ModifierContact();

    GestionContact tempgs; ///< Gestionnaire de contacts temporaire.
    GestionContact gs;     ///< Gestionnaire de contacts.

    bool validImg = false; ///< Indique si l'image est valide.

signals:
    /**
     * @brief Signal émis pour envoyer un contact modifié.
     *
     * @param c Contact d'origine.
     * @param modif Contact modifié.
     */
    void envoiModif(Contact c, Contact modif);

private slots:
    /**
     * @brief Méthode appelée lors de la modification du champ de nom.
     *
     * Elle recherche les correspondances dans la liste de contacts en fonction du nom et du prénom (s'il est renseigné).
     * Affiche les correspondances trouvées et pré-remplit les champs si une seule correspondance est trouvée.
     * Efface les champs si aucune ou plus d'une correspondance n'est trouvée.
     *
     * @param arg1 Nouvelle valeur du champ de texte du nom.
     */
    void on_NomE_textChanged(const QString &arg1);

    /**
     * @brief Méthode appelée lors de la modification du champ de prénom.
     *
     * Recherche les correspondances dans la liste de contacts en fonction du prénom et du nom (s'il est renseigné).
     * Affiche les correspondances trouvées et pré-remplit les champs si une seule correspondance est trouvée.
     * Efface les champs si aucune ou plus d'une correspondance n'est trouvée.
     *
     * @param arg1 Nouvelle valeur du champ de texte du prénom.
     */
    void on_PrenomE_textChanged(const QString &arg1);

    /**
     * @brief Méthode appelée lors du clic sur le bouton "Annuler".
     *
     * Ferme la fenêtre actuelle.
     */
    void on_Annuler_clicked();

    /**
     * @brief Méthode appelée lors du clic sur le bouton "Modifier".
     *
     * Récupère les informations des champs de texte pour créer un nouvel objet Contact.
     * Si une seule correspondance est sélectionnée, émet un signal pour modifier le contact et ferme la fenêtre.
     * Sinon, affiche un message demandant de sélectionner un seul contact.
     */
    void on_Modifier_clicked();

    /**
     * @brief Méthode appelée lors de la modification du champ de texte de la photo.
     *
     * Vérifie si l'image existe et l'affiche dans un label.
     * Si l'image n'existe pas ou n'est pas valide, affiche une image par défaut.
     *
     * @param arg1 Nouveau texte du champ de texte de la photo.
     */
    void on_EPhoto_textChanged(const QString &arg1);

private:
    Ui::ModifierContact *ui; ///< Interface utilisateur pour la classe ModifierContact.
};

#endif // MODIFIERCONTACT_H
