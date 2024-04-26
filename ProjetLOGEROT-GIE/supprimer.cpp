#include "supprimer.h"
#include "ui_supprimer.h"

/**
 * @brief Constructeur de la classe Supprimer.
 *
 * @param parent Pointeur vers le widget parent.
 * @param g Objet de type GestionContact.
 */
Supprimer::Supprimer(QWidget *parent, GestionContact g) :
    QWidget(parent),
    gs(g),
    ui(new Ui::Supprimer)

{
    ui->setupUi(this);
}


/**
 * @brief Destructeur de la classe Supprimer.
 */
Supprimer::~Supprimer()
{
    delete ui;
}


/**
 * @brief Méthode déclenchée lors de la modification du champ du nom.
 *
 * @param arg1 Nouvelle valeur du champ de texte.
 */
void Supprimer::on_NomE_textChanged(const QString &arg1)
{
    GestionContact t;
    if(ui->PrenomE->text().isEmpty())
    {
        std::string s =ui->NomE->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getNom()==s)
            {

                t.addContact(item);
            }
        }
        tempgs = t;
    }


    else
    {
        std::string s =ui->NomE->text().toStdString();
        std::string s2 =ui->PrenomE->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getNom()==s and item.getPrenom()==s2)
            {
                t.addContact(item);
            }
        }
        tempgs = t;
    }


    if(tempgs.getSize()!=0)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage->setText(s);
    }
    else
    {
        ui->Affichage->setText("il n'y a aucune corespondance");
    }
}



/**
 * @brief Méthode déclenchée lors de la modification du champ du prénom.
 *
 * @param arg1 Nouvelle valeur du champ de texte.
 */
void Supprimer::on_PrenomE_textChanged(const QString &arg1)
{
    GestionContact t;
    if(ui->NomE->text().isEmpty())
    {
        std::string s =ui->PrenomE->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getPrenom()==s)
            {
                t.addContact(item);
            }
        }
        tempgs = t;
    }


    else
    {
        std::string s =ui->NomE->text().toStdString();
        std::string s2 =ui->PrenomE->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getNom()==s and item.getPrenom()==s2)
            {
                t.addContact(item);
            }
        }
        tempgs = t;
    }


    if(tempgs.getSize()!=0)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage->setText(s);
    }
    else
    {
        ui->Affichage->setText("il n'y a aucune corespondance");
    }
}


/**
 * @brief Méthode déclenchée lors du clic sur le bouton "Supprimer".
 *
 * Si un seul contact est sélectionné, l'événement envoie ce contact et ferme la fenêtre.
 * Sinon, un message est affiché demandant de choisir un seul contact.
 */
void Supprimer::on_Supprimer_2_clicked()
{
    if(tempgs.getSize()==1)
    {
        Contact c = tempgs.getListe().front();
        emit(envoiSupr(c));
        close();
    }
    else
    {
        ui->Affichage->setText("Choisissez un seul contact");
    }
}


/**
 * @brief Méthode déclenchée lors du clic sur le bouton "Annuler".
 *
 * Ferme la fenêtre actuelle.
 */
void Supprimer::on_Annuler_clicked()
{
    close();
}
