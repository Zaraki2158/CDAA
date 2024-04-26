#include "interactionstodo.h"
#include "ui_interactionstodo.h"

/**
 * @brief Constructeur de la classe InteractionsTodo.
 * @param parent Le widget parent.
 * @param g Objet de type GestionContact utilisé pour initialiser l'objet InteractionsTodo.
 */
InteractionsTodo::InteractionsTodo(QWidget *parent, GestionContact g) :
    QWidget(parent),
    gs(g),
    ui(new Ui::InteractionsTodo)
{
    ui->setupUi(this);
}

/**
 * @brief Destructeur de la classe InteractionsTodo.
 */
InteractionsTodo::~InteractionsTodo()
{
    delete ui;
}

/**
 * @brief Méthode appelée lors du changement de texte dans le champ NomE_3.
 * @param arg1 Le texte modifié.
 */
void InteractionsTodo::on_NomE_3_textChanged(const QString &arg1)
{
    GestionContact t;
    if(ui->PrenomE_3->text().isEmpty())
    {
        std::string s =ui->NomE_3->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getNom()==s)
            {

                t.addContact(item, true);
            }
        }
        tempgs = t;
    }


    else
    {
        std::string s =ui->NomE_3->text().toStdString();
        std::string s2 =ui->PrenomE_3->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getNom()==s and item.getPrenom()==s2)
            {
                t.addContact(item, true);
            }
        }
        tempgs = t;
    }


    if(tempgs.getSize()!=0)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage_3->setText(s);
    }
    else
    {
        ui->Affichage_3->setText("il n'y a aucune corespondance");
    }
}

/**
 * @brief Méthode appelée lors du changement de texte dans le champ PrenomE_3.
 * @param arg1 Le texte modifié.
 */
void InteractionsTodo::on_PrenomE_3_textChanged(const QString &arg1)
{
    GestionContact t;
    if(ui->NomE_3->text().isEmpty())
    {
        std::string s =ui->PrenomE_3->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getPrenom()==s)
            {
                t.addContact(item, true);
            }
        }
        tempgs = t;
    }


    else
    {
        std::string s =ui->NomE_3->text().toStdString();
        std::string s2 =ui->PrenomE_3->text().toStdString();
        for (const auto& item : gs.getListe())
        {
            if(item.getNom()==s and item.getPrenom()==s2)
            {
                t.addContact(item, true);
            }
        }
        tempgs = t;
    }


    if(tempgs.getSize()!=0)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage_3->setText(s);
    }
    else
    {
        ui->Affichage_3->setText("il n'y a aucune corespondance");
    }
}

/**
 * @brief Méthode appelée lors du clic sur le bouton AjoutTodo.
 * Ajoute un élément Todo à une liste.
 */
void InteractionsTodo::on_AjoutTodo_clicked()
{
    nbTodo++;
    std::string s = "Todo "+std::to_string(nbTodo)+" Ajouté";
                                                       ui->Valide->setText(QString::fromStdString(s));
    int annee = ui->DateTodo->date().year();
    int mois = ui->DateTodo->date().month();
    int jour = ui->DateTodo->date().day();
    int heure = ui->DateTodo->time().hour();
    int min = ui->DateTodo->time().minute();
    Date d;
    d.annee = annee;
    d.mois = mois;
    d.jour = jour;
    d.heure = heure;
    d.min = min;
    Todo t;
    t.setDate(d);
    t.setContenu(ui->TodoE->text().toStdString());
    lstTodo.push_back(t);
    ui->TodoE->clear();
}

/**
 * @brief Méthode appelée lors du clic sur le bouton Interact.
 * Émet un signal si un seul contact est sélectionné et qu'un texte est présent dans InteractionsE.
 * Sinon, affiche un message d'erreur.
 */
void InteractionsTodo::on_Interact_clicked()
{
    if(tempgs.getSize()==1 and not ui->InteractionsE->text().isEmpty())
    {
        Contact c = tempgs.getListe().front();
        Date d;
        d.getCourante();
        Interaction i(ui->InteractionsE->text().toStdString(), d);
        for (const auto& item : lstTodo)
        {
            i.ajouteTodo(item);
        }
        emit(EnvoiInteract(c, i));
        close();
    }
    else
    {
        ui->Affichage_3->setText("Choisissez un seul contact");
    }

}
