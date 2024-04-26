#include "contact.h"


/**
 * @brief Constructeur par défaut de la classe Contact.
 *
 * Ce constructeur crée un objet Contact en utilisant des valeurs par défaut pour ses propriétés.
 * Ces valeurs par défaut sont spécifiées dans le corps du constructeur.
 */
Contact::Contact()
{
    nom = "Dupond Moretti";
    prenom = "Eric";
    entreprise = "Garde des sceaux";
    mail = "DupondMoretti@gmail.com";
    telephone = "0665673075";
    urlphoto = "EricDupondMoretti";
    date.getCourante();
    linteractions = std::list<Interaction>();
}



/**
 * @brief Constructeur de la classe Contact avec paramètres.
 *
 * Ce constructeur crée un objet Contact en initialisant ses propriétés
 * avec les valeurs spécifiées.
 *
 * @param n Le nom du contact.
 * @param p Le prénom du contact.
 * @param e Le nom de l'entreprise du contact.
 * @param m L'adresse e-mail du contact.
 * @param t Le numéro de téléphone du contact.
 * @param ph L'URL de la photo du contact.
 */
Contact::Contact(const std::string& n, const std::string& p, const std::string& e, const std::string& m, const std::string& t, const std::string& ph)
{
    this->setNom(n);
    this->setPrenom(p);
    this->setEntreprise(e);
    this->setMail(m);
    this->setTelephone(t);
    this->setPhoto(ph);
    date.getCourante();
}



/**
 * @brief Destructeur de la classe Contact.
 *
 * Ce destructeur est appelé lorsqu'un objet Contact est détruit et effectue
 * des opérations de nettoyage, telles que la libération de la mémoire des propriétés.
 */
Contact::~Contact()
{
    telephone.clear();
    linteractions.clear();
}


// Accesseurs

/**
 * @brief Obtient le nom du contact.
 * @return Le nom du contact.
 */
std::string Contact::getNom() const { return nom; }

/**
 * @brief Obtient le prénom du contact.
 * @return Le prénom du contact.
 */
std::string Contact::getPrenom() const { return prenom; }

/**
 * @brief Obtient le nom de l'entreprise du contact.
 * @return Le nom de l'entreprise du contact.
 */
std::string Contact::getEntreprise() const { return entreprise; }

/**
 * @brief Obtient l'adresse e-mail du contact.
 * @return L'adresse e-mail du contact.
 */
std::string Contact::getMail() const { return mail; }

/**
 * @brief Obtient le numéro de téléphone du contact.
 * @return Le numéro de téléphone du contact.
 */
std::string Contact::getTelephone() const { return telephone; }

/**
 * @brief Obtient l'URL de la photo du contact.
 * @return L'URL de la photo du contact.
 */
std::string Contact::getPhoto() const { return urlphoto; }

// Modificateurs

/**
 * @brief Modifie le nom du contact.
 * @param n Le nouveau nom du contact.
 */
void Contact::setNom(const std::string& n) { nom = n; }

/**
 * @brief Modifie le prénom du contact.
 * @param p Le nouveau prénom du contact.
 */
void Contact::setPrenom(const std::string& p) { prenom = p; }

/**
 * @brief Modifie le nom de l'entreprise du contact.
 * @param e Le nouveau nom de l'entreprise du contact.
 */
void Contact::setEntreprise(const std::string& e) { entreprise = e; }

/**
 * @brief Modifie l'adresse e-mail du contact.
 * @param m La nouvelle adresse e-mail du contact.
 */
void Contact::setMail(const std::string& m) { mail = m; }

/**
 * @brief Modifie le numéro de téléphone du contact.
 * @param t Le nouveau numéro de téléphone du contact.
 */
void Contact::setTelephone(const std::string& t) { telephone = t; }

/**
 * @brief Modifie l'URL de la photo du contact.
 * @param photo La nouvelle URL de la photo du contact.
 */
void Contact::setPhoto(const std::string& photo) { urlphoto = photo; }

/**
 * @brief Ajoute une interaction à la liste d'interactions du contact.
 * @param interaction L'interaction à ajouter.
 */
void Contact::ajoutInteraction(const Interaction& interaction)
{
    linteractions.push_back(interaction);
}


/**
 * @brief Surcharge de l'opérateur de sortie pour l'affichage d'un objet Contact.
 *
 * Cette surcharge permet d'afficher les détails d'un objet Contact dans un flux de sortie.
 * Elle affiche le nom, le prénom, l'entreprise, l'adresse e-mail, le numéro de téléphone,
 * l'URL de la photo, la date de création et les interactions associées au contact.
 *
 * @param os Le flux de sortie dans lequel afficher le contact.
 * @param contact L'objet Contact à afficher.
 * @return Le flux de sortie mis à jour.
 */
std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
    os << "Nom: " << contact.getNom() << "\n";
    os << "Prenom: " << contact.getPrenom() << "\n";
    os << "Entreprise: " << contact.getEntreprise() << "\n";
    os << "Mail: " << contact.getMail() << "\n";
    os << "Téléphone: " << contact.getTelephone();
    os << "\n";
    os << "URL Photo: " << contact.getPhoto() << "\n";
    os << "Date de création: " << contact.date.jour << "/" << contact.date.mois << "/" << contact.date.annee << "  " << contact.date.heure << ":" << contact.date.min << "\n";
    os << "Interactions de " << contact.getNom() << " " << contact.getPrenom() << ": " << std::endl << "{" << std::endl;
    for (const Interaction& interaction : contact.linteractions)
    {
        os << interaction << "\n";
    }
    os << "}" << std::endl;
    return os;
}


/**
 * @brief Surcharge de l'opérateur d'égalité pour comparer deux contacts.
 * @param p Le contact à comparer.
 * @return True si les contacts sont égaux, false sinon.
 */
bool Contact::operator==(const Contact& p) const
{
    if (getNom() == p.getNom())
        if (getPrenom() == p.getPrenom())
            if (getEntreprise() == p.getEntreprise())
                if (getMail() == p.getMail())
                    return true;
    return false;
}
