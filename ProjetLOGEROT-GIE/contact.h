#ifndef CONTACT_H
#define CONTACT_H

#include <list>
#include "interaction.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QSqlError>

/**
 * @brief Classe représentant un contact.
 */
class Contact {
private:
    std::string nom; /**< Nom du contact. */
    std::string prenom; /**< Prénom du contact. */
    std::string entreprise; /**< Entreprise du contact. */
    std::string mail; /**< Adresse e-mail du contact. */
    std::string telephone; /**< Numéro de téléphone du contact. */
    std::string urlphoto; /**< URL de la photo du contact. */
    std::list<Interaction> linteractions; /**< Liste des interactions du contact. */

public:
    struct Date date; /**< Date du contact. */

    /**
     * @brief Constructeur par défaut.
     */
    Contact();

    /**
     * @brief Constructeur prenant des paramètres pour initialiser un contact.
     * @param n Nom du contact.
     * @param p Prénom du contact.
     * @param e Entreprise du contact.
     * @param m Adresse e-mail du contact.
     * @param t Numéro de téléphone du contact.
     * @param ph URL de la photo du contact.
     */
    Contact(const std::string& n, const std::string& p, const std::string& e, const std::string& m, const std::string& t, const std::string& ph);

    /**
     * @brief Destructeur de la classe Contact.
     */
    ~Contact();

    // Getters et setters
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getEntreprise() const;
    std::string getMail() const;
    std::string getDate() const;
    std::string getTelephone() const;
    std::string getPhoto() const;
    void setNom(const std::string& n);
    void setPrenom(const std::string& p);
    void setEntreprise(const std::string& e);
    void setMail(const std::string& m);
    void setTelephone(const std::string& t);
    void setPhoto(const std::string& photo);

    // Méthodes
    void ajoutInteraction(const Interaction& interaction);

    // Surcharge d'opérateurs
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
    bool operator==(const Contact& ) const;
};

#endif // CONTACT_H
