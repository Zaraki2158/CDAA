#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include "contact.h"
#include "historique.h"
#include<algorithm>

/**
 * @brief La classe GestionContact gère les contacts et les historiques associés.
 */
class GestionContact {
private:
    std::list<Contact> Contacts; ///< Liste des contacts gérés.
    std::list<Historique> Histo; ///< Liste des historiques des modifications.
public:
    /**
     * @brief Constructeur par défaut de GestionContact.
     */
    GestionContact();

    /**
     * @brief Destructeur de GestionContact.
     */
    ~GestionContact();

    /**
     * @brief Affiche la liste des contacts.
     * @return Chaîne de caractères représentant la liste des contacts.
     */
    std::string afficheListe();

    /**
     * @brief Affiche la liste des historiques.
     * @return Chaîne de caractères représentant la liste des historiques.
     */
    std::string afficheHisto();

    /**
     * @brief Modifie un contact existant.
     * @param nom Nom du contact à modifier.
     * @param c Nouvel objet Contact pour la modification.
     */
    void modifContact(const std::string&, Contact c);

    /**
     * @brief Ajoute une interaction à un contact existant.
     * @param c Contact auquel ajouter l'interaction.
     * @param i Interaction à ajouter.
     */
    void addInteraction(Contact c, Interaction i);

    /**
     * @brief Récupère la liste des contacts.
     * @return Liste des contacts.
     */
    std::list<Contact> getListe() const;

    /**
     * @brief Renvoie la taille de la liste des contacts.
     * @return Taille de la liste des contacts.
     */
    inline unsigned getSize() {return Contacts.size();}

    /**
     * @brief Trie la liste des contacts par ordre alphabétique croissant.
     */
    void trierParNomAZ();

    /**
     * @brief Trie la liste des contacts par ordre alphabétique décroissant.
     */
    void trierParNomZA();

    /**
     * @brief Ajoute un contact à la liste.
     * @param c Contact à ajouter.
     * @param b (Facultatif) Booléen pour une action spécifique lors de l'ajout.
     */
    void addContact(const Contact&, bool b=false);

    /**
     * @brief Supprime le premier contact portant un nom spécifique.
     * @param Nom du contact à supprimer.
     */
    void removeFirstByName(const std::string&);

    /**
     * @brief Supprime tous les contacts portant un nom spécifique.
     * @param Nom du contact à supprimer.
     */
    void removeByName(const std::string&);

    /**
     * @brief Supprime un contact par nom et prénom.
     * @param n Nom du contact à supprimer.
     * @param p Prénom du contact à supprimer.
     */
    void removeBy_N_And_P(const std::string& n, const std::string& p);

    /**
     * @brief Ajoute un historique avec un message spécifique.
     * @param m Message à ajouter à l'historique.
     */
    void ajouteHisto(std::string m);

    /**
     * @brief Ajoute un historique complet à la liste d'historique.
     * @param h Historique à ajouter.
     */
    void ajouteHisto(Historique h);

    /**
     * @brief Trie la liste des contacts par date récente.
     */
    void trierParDateRecent();

    /**
     * @brief Trie la liste des contacts par date ancienne.
     */
    void trierParDateAncien();

    /**
     * @brief Ajoute un historique dans la base de données.
     * @param h Historique à ajouter dans la base de données.
     */
    void ajoutHistoSQL(Historique h);


    // Surcharges
    GestionContact operator+(const Contact &);
    void operator=(const GestionContact &);
    GestionContact operator-(const Contact &);
    friend std::ostream& operator<<(std::ostream& os, const GestionContact& gestioncontact);
};

#endif // GESTIONCONTACT_H
