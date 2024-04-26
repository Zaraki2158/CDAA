#include "gestioncontact.h"

/**
 * @file gestioncontact.cpp
 * @brief Implémentation de la classe GestionContact pour gérer une liste de contacts.
 */

/**
 * @brief Constructeur par défaut de la classe GestionContact.
 */
GestionContact::GestionContact()
{

}

/**
 * @brief Destructeur de la classe GestionContact.
 */
GestionContact::~GestionContact()
{
    Contacts.clear(); /**< Nettoie la liste de contacts */
}

/**
 * @brief Ajoute une personne à la liste de contacts.
 * @param p Contact à ajouter.
 * @param b Indique s'il faut ajouter l'ajout du contact à l'historique.
 */
void GestionContact::addContact(const Contact &p, bool b)
{
    Contacts.push_back(p);
    if(b==true)
    ajouteHisto("ajout du contact " + p.getNom() + " " + p.getPrenom());
}

/**
 * @brief Récupère la liste de contacts.
 * @return Une liste de contacts.
 */
std::list<Contact> GestionContact::getListe() const
{
    return Contacts;
}

/**
 * @brief Ajoute un élément à l'historique.
 * @param m Message à ajouter à l'historique.
 */
void GestionContact::ajouteHisto(std::string m)
{
    Historique histo(m);
    this->Histo.push_back(histo);
    ajoutHistoSQL(histo);
}

void GestionContact::ajouteHisto(Historique h)
{
    this->Histo.push_back(h);
}

/**
 * @brief Modifie un contact existant en remplaçant l'ancien contact par un nouveau.
 * @param n Nom du contact à modifier.
 * @param c Nouveau contact.
 */
void GestionContact::modifContact(const std::string &n, Contact c)
{
    auto it = Contacts.begin();
    bool found = false;
    while ((it != Contacts.end()) && (found == false))
    {
        if (it->getNom() == n)
        {
            found = true;
            ajouteHisto("modification du contact " + it->getNom() + " " + it->getPrenom() + " en " + c.getNom() + " " + c.getPrenom());
            it = Contacts.emplace(it, c);
            it++;
            it = Contacts.erase(it);
        }
        else
            ++it;
    }
}

void GestionContact::addInteraction(Contact c, Interaction i)
{
    c.ajoutInteraction(i);
    auto it = Contacts.begin();
    bool found = false;
    while ((it != Contacts.end()) && (found == false))
    {
        if (it->getNom() == c.getNom() and it->getPrenom()==c.getPrenom())
        {
            found = true;
            it = Contacts.emplace(it, c);
            it++;
            it = Contacts.erase(it);
        }
        else
            ++it;
    }
    ajouteHisto("ajout de l'interaction "+ i.getContenu()+ " à " + c.getNom() + " " + c.getPrenom());
}

/**
 * @brief Supprime le premier contact ayant un nom spécifique.
 * @param n Nom du contact à supprimer.
 */
void GestionContact::removeFirstByName(const std::string &n)
{
    auto it = Contacts.begin();
    bool found = false;
    while ((it != Contacts.end()) && (found == false))
    {
        if (it->getNom() == n)
        {
            ajouteHisto("suppression du contact " + it->getNom() + " " + it->getPrenom());
            found = true;
            it = Contacts.erase(it);
        }
        else
            ++it;
    }
}

/**
 * @brief Supprime tous les contacts ayant un nom spécifique.
 * @param n Nom du contact à supprimer.
 */
void GestionContact::removeByName(const std::string &n)
{
    for (auto it = Contacts.begin(); it != Contacts.end();)
        if (it->getNom() == n)
        {
            ajouteHisto("suppression du contact " + it->getNom() + " " + it->getPrenom());
            it = Contacts.erase(it);
        }
        else
            ++it;
}

void GestionContact::removeBy_N_And_P(const std::string &n, const std::string &p)
{
    for (auto it = Contacts.begin(); it != Contacts.end();)
        if (it->getNom() == n and it->getPrenom() == p)
        {
            ajouteHisto("suppression du contact " + it->getNom() + " " + it->getPrenom());
            it = Contacts.erase(it);
        }
        else
            ++it;
}

/**
 * @brief Surcharge de l'opérateur + pour ajouter un contact à la liste.
 * @param p Contact à ajouter.
 * @return Une référence vers l'objet GestionContact.
 */
GestionContact GestionContact::operator+(const Contact &p)
{
    ajouteHisto("ajout du contact " + p.getNom() + " " + p.getPrenom());
    Contacts.push_back(p);
    return *this;
}

/**
 * @brief Surcharge de l'opérateur = pour copier les contacts d'un autre GestionContact.
 * @param gp GestionContact à copier.
 */
void GestionContact::operator=(const GestionContact &gp)
{
    Contacts.clear();
    Contacts = gp.Contacts;
    Histo.clear();
    Histo = gp.Histo;
}

/**
 * @brief Surcharge de l'opérateur - pour supprimer un contact de la liste.
 * @param p Contact à supprimer.
 * @return Une référence vers l'objet GestionContact.
 */
GestionContact GestionContact::operator-(const Contact &p)
{
    auto it = Contacts.begin();
    bool found = false;
    while ((it != Contacts.end()) && (found == false))
    {
        if (*it == p)
        {
            found = true;
            it = Contacts.erase(it);
        }
        else
            ++it;
    }
    return *this;
}

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher la liste de contacts.
 * @param os Flux de sortie.
 * @param gestioncontact Objet GestionContact à afficher.
 * @return Une référence vers le flux de sortie.
 */
std::ostream& operator<<(std::ostream &os, const GestionContact &gestioncontact)
{
    int j = 0;
    for (const Contact &contact : gestioncontact.getListe())
    {
        j++;
        os << "contact " << j << " : \n";
        os << contact << "\n\n";
    }
    return os;
}

/**
 * @brief Affiche la liste de contacts sous forme d'une chaîne de caractères.
 * @return Chaîne de caractères représentant la liste de contacts.
 */
std::string GestionContact::afficheListe()
{
    std::stringstream ss;
    int j = 0;
    for (const Contact &contact : getListe())
    {
        j++;
        ss << "contact " << j << " : \n";
        ss << contact << "\n\n";
    }
    std::string s = ss.str();
    return s;
}

/**
 * @brief Affiche l'historique des changements de gestionContact.
 * @return Chaîne de caractères représentant l'historique des changements.
 */
std::string GestionContact::afficheHisto()
{
    std::string s;
    s = "Historique des changements de gestionContact : \n\n";
    auto it = Histo.begin();
    while (it != Histo.end())
    {
        s+= it->Affichage();
        it++;
    }
    return s;
}

/**
 * @brief Trie la liste de contacts par ordre alphabétique croissant (A-Z) basé sur le nom.
 */
void GestionContact::trierParNomAZ()
{
    Contacts.sort([](const Contact& a, const Contact& b) {
        return a.getNom() < b.getNom();
    });

    // Mise à jour de l'historique si nécessaire
    ajouteHisto("Tri de la liste de contacts par nom A-Z");
}

/**
 * @brief Trie la liste de contacts par ordre alphabétique décroissant (Z-A) basé sur le nom.
 */
void GestionContact::trierParNomZA()
{
    Contacts.sort([](const Contact& a, const Contact& b) {
        return a.getNom() > b.getNom();
    });

    // Mise à jour de l'historique si nécessaire
    ajouteHisto("Tri de la liste de contacts par nom Z-A");
}

/**
 * @brief Trie la liste de contacts par date de création, du plus récent au plus ancien.
 */
void GestionContact::trierParDateRecent()
{
    Contacts.sort([](const Contact& a, const Contact& b) {
        // Compare les dates du plus récent au plus ancien
        return a.date.annee > b.date.annee ||
               (a.date.annee == b.date.annee && a.date.mois > b.date.mois) ||
               (a.date.annee == b.date.annee && a.date.mois == b.date.mois && a.date.jour > b.date.jour) ||
               (a.date.annee == b.date.annee && a.date.mois == b.date.mois && a.date.jour == b.date.jour &&
                a.date.heure > b.date.heure) ||
               (a.date.annee == b.date.annee && a.date.mois == b.date.mois && a.date.jour == b.date.jour &&
                a.date.heure == b.date.heure && a.date.min > b.date.min);
    });

    // Mise à jour de l'historique si nécessaire
    ajouteHisto("Tri de la liste de contacts par date (du plus récent au plus ancien)");
}

/**
 * @brief Trie la liste de contacts par date de création, du plus ancien au plus récent.
 */
void GestionContact::trierParDateAncien()
{
    Contacts.sort([](const Contact& a, const Contact& b) {
        // Compare les dates du plus ancien au plus récent
        return a.date.annee < b.date.annee ||
               (a.date.annee == b.date.annee && a.date.mois < b.date.mois) ||
               (a.date.annee == b.date.annee && a.date.mois == b.date.mois && a.date.jour < b.date.jour) ||
               (a.date.annee == b.date.annee && a.date.mois == b.date.mois && a.date.jour == b.date.jour &&
                a.date.heure < b.date.heure) ||
               (a.date.annee == b.date.annee && a.date.mois == b.date.mois && a.date.jour == b.date.jour &&
                a.date.heure == b.date.heure && a.date.min < b.date.min);
    });

    // Mise à jour de l'historique si nécessaire
    ajouteHisto("Tri de la liste de contacts par date (du plus ancien au plus récent)");
}

/**
 * @brief Ajoute un élément d'historique à la base de données SQLite.
 * @param h Historique à ajouter.
 */
void GestionContact::ajoutHistoSQL(Historique h)
{

    QString modif = QString::fromStdString(h.getModif());
    QString annee = QString::number(h.getDate().annee);
    QString mois = QString::number(h.getDate().mois);
    QString jour = QString::number(h.getDate().jour);
    QSqlQuery query;
    QString insertContactSQL = "INSERT INTO histo (modif, date_jour, date_mois, date_annee)"
                               "VALUES (:modif, :jour, :mois, :annee);";
    query.prepare(insertContactSQL);

    // Bind les valeurs à la requête
    query.bindValue(":modif", modif);
    query.bindValue(":jour", jour);
    query.bindValue(":mois", mois);
    query.bindValue(":annee", annee);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'historique :" << query.lastError().text();
    } else {
        qDebug() << "Historique ajouté avec succès.";
    }
}
