#ifndef AJOUTERCONTACT_H
#define AJOUTERCONTACT_H

#include "contact.h"
#include <QWidget>
#include <QRegExpValidator>
#include "ui_ajoutercontact.h"

/**
 * @brief La classe AjouterContact gère l'interface pour l'ajout de contacts.
 */
class AjouterContact : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe.
     * @param parent Le widget parent (par défaut, nullptr).
     */
    explicit AjouterContact(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe.
     */
    ~AjouterContact();

    QString img; // Variable pour le chemin de l'image
    bool validImg = false; // Indicateur de validité de l'image

signals:
    /**
     * @brief Signal émis lorsqu'un nouveau contact est prêt à être envoyé.
     * @param c Le contact à envoyer.
     */
    void EnvoieContact(Contact c);

private slots:
    // Méthodes associées aux interactions avec l'interface

    /**
     * @brief Réagit au clic sur le bouton "Ajouter".
     */
    void on_Ajouter_clicked();

    /**
     * @brief Réagit aux changements de texte dans le champ du nom.
     * @param arg1 Le texte actuel dans le champ du nom.
     */
    void on_ENom_textChanged(const QString &arg1);

    /**
     * @brief Réagit aux changements de texte dans le champ du prénom.
     * @param arg1 Le texte actuel dans le champ du prénom.
     */
    void on_EPrenom_textChanged(const QString &arg1);

    /**
     * @brief Réagit aux changements de texte dans le champ de l'entreprise.
     * @param arg1 Le texte actuel dans le champ de l'entreprise.
     */
    void on_EEntreprise_textChanged(const QString &arg1);

    /**
     * @brief Réagit aux changements de texte dans le champ du téléphone.
     * @param arg1 Le texte actuel dans le champ du téléphone.
     */
    void on_ETelephone_textChanged(const QString &arg1);

    /**
     * @brief Réagit aux changements de texte dans le champ de la photo.
     * @param arg1 Le texte actuel dans le champ de la photo.
     */
    void on_EPhoto_textChanged(const QString &arg1);

    /**
     * @brief Réagit aux changements de texte dans le champ de l'e-mail.
     * @param arg1 Le texte actuel dans le champ de l'e-mail.
     */
    void on_EMail_textChanged(const QString &arg1);

    /**
     * @brief Réagit au clic sur le bouton "Annuler".
     */
    void on_Annuler_clicked();

private:
    Ui::AjouterContact *ui; // Interface utilisateur
};

#endif // AJOUTERCONTACT_H
