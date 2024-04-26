#include "modifiercontact.h"
#include "ui_modifiercontact.h"


/**
 * @brief Constructeur de la classe ModifierContact.
 *
 * @param parent Widget parent.
 * @param g Objet de type GestionContact.
 */
ModifierContact::ModifierContact(QWidget *parent, GestionContact g) :
    QWidget(parent),
    gs(g),
    ui(new Ui::ModifierContact)
{
    ui->setupUi(this);
    QRegExp regexN("[A-Z][a-z]*");
    QRegExpValidator *validatorN = new QRegExpValidator(regexN, ui->ENom);
    ui->ENom->setValidator(validatorN);
    QRegExp regexP("[A-Z][a-z]*");
    QRegExpValidator *validatorP = new QRegExpValidator(regexP, ui->EPrenom);
    ui->EPrenom->setValidator(validatorP);
    QRegExp regexNum("[0-9]\\d{10}$");
    QRegExpValidator * validatorNum = new QRegExpValidator(regexNum, ui->ETelephone);
    ui->ETelephone->setValidator(validatorNum);
    QRegExp regexM(".*@.*\.fr");
    QRegExpValidator *validatorM = new QRegExpValidator(regexM, ui->EMail);
    ui->EMail->setValidator(validatorM);
}

/**
 * @brief Destructeur de la classe ModifierContact.
 */
ModifierContact::~ModifierContact()
{
    delete ui;
}


/**
 * @brief Méthode appelée lors de la modification du champ de nom.
 *
 * Elle recherche les correspondances dans la liste de contacts en fonction du nom et du prénom (s'il est renseigné).
 * Affiche les correspondances trouvées et pré-remplit les champs si une seule correspondance est trouvée.
 * Efface les champs si aucune ou plus d'une correspondance n'est trouvée.
 *
 * @param arg1 Nouvelle valeur du champ de texte du nom.
 */
void ModifierContact::on_NomE_textChanged(const QString &arg1)
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
        Contact c = tempgs.getListe().front();
        ui->ENom->setText(QString::fromStdString(c.getNom()));
        ui->EPrenom->setText(QString::fromStdString(c.getPrenom()));
        ui->EEntreprise->setText(QString::fromStdString(c.getEntreprise()));
        ui->EMail->setText(QString::fromStdString(c.getMail()));
        ui->ETelephone->setText(QString::fromStdString(c.getTelephone()));
        ui->EPhoto->setText(QString::fromStdString(c.getPhoto()));
    }
    else if(tempgs.getSize()>1)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage->setText(s);
        ui->ENom->clear();
        ui->EPrenom->clear();
        ui->EEntreprise->clear();
        ui->EMail->clear();
        ui->ETelephone->clear();
        ui->EPhoto->clear();
    }
    else
    {
        ui->Affichage->setText("il n'y a aucune corespondance");
        ui->ENom->clear();
        ui->EPrenom->clear();
        ui->EEntreprise->clear();
        ui->EMail->clear();
        ui->ETelephone->clear();
        ui->EPhoto->clear();
    }
}


/**
 * @brief Méthode appelée lors de la modification du champ de prénom.
 *
 * Recherche les correspondances dans la liste de contacts en fonction du prénom et du nom (s'il est renseigné).
 * Affiche les correspondances trouvées et pré-remplit les champs si une seule correspondance est trouvée.
 * Efface les champs si aucune ou plus d'une correspondance n'est trouvée.
 *
 * @param arg1 Nouvelle valeur du champ de texte du prénom.
 */
void ModifierContact::on_PrenomE_textChanged(const QString &arg1)
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

    if(tempgs.getSize()==1)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage->setText(s);
        Contact c = tempgs.getListe().front();
        ui->ENom->setText(QString::fromStdString(c.getNom()));
        ui->EPrenom->setText(QString::fromStdString(c.getPrenom()));
        ui->EEntreprise->setText(QString::fromStdString(c.getEntreprise()));
        ui->EMail->setText(QString::fromStdString(c.getMail()));
        ui->ETelephone->setText(QString::fromStdString(c.getTelephone()));
        ui->EPhoto->setText(QString::fromStdString(c.getPhoto()));
    }
    else if(tempgs.getSize()>1)
    {
        QString s = QString::fromStdString(tempgs.afficheListe());
        ui->Affichage->setText(s);
        ui->ENom->clear();
        ui->EPrenom->clear();
        ui->EEntreprise->clear();
        ui->EMail->clear();
        ui->ETelephone->clear();
        ui->EPhoto->clear();
    }
    else
    {
        ui->Affichage->setText("il n'y a aucune corespondance");
        ui->ENom->clear();
        ui->EPrenom->clear();
        ui->EEntreprise->clear();
        ui->EMail->clear();
        ui->ETelephone->clear();
        ui->EPhoto->clear();
        ui->img->clear();
    }
}


/**
 * @brief Méthode appelée lors du clic sur le bouton "Annuler".
 *
 * Ferme la fenêtre actuelle.
 */
void ModifierContact::on_Annuler_clicked()
{
    close();
}


/**
 * @brief Méthode appelée lors du clic sur le bouton "Modifier".
 *
 * Récupère les informations des champs de texte pour créer un nouvel objet Contact.
 * Si une seule correspondance est sélectionnée, émet un signal pour modifier le contact et ferme la fenêtre.
 * Sinon, affiche un message demandant de sélectionner un seul contact.
 */
void ModifierContact::on_Modifier_clicked()
{
    std::string Nom = ui->ENom->text().toStdString();
    std::string Prenom = ui->EPrenom->text().toStdString();
    std::string Entreprise = ui->EEntreprise->text().toStdString();
    std::string Mail = ui->EMail->text().toStdString();
    std::string Telephone = ui->ETelephone->text().toStdString();
    std::string Photo = ui->EPhoto->text().toStdString();
    Contact modif(Nom,Prenom,Entreprise,Mail,Telephone,Photo);
    if(tempgs.getSize()==1)
    {
        Contact c = tempgs.getListe().front();
        emit(envoiModif(c, modif));
        close();
    }
    else
    {
        ui->Affichage->setText("Choisissez un seul contact");
    }
}


/**
 * @brief Méthode appelée lors de la modification du champ de texte de la photo.
 *
 * Vérifie si l'image existe et l'affiche dans un label.
 * Si l'image n'existe pas ou n'est pas valide, affiche une image par défaut.
 *
 * @param arg1 Nouveau texte du champ de texte de la photo.
 */
void ModifierContact::on_EPhoto_textChanged(const QString &arg1)
{
    QString nimg = ui->EPhoto->text();
    QString imagePath = QCoreApplication::applicationDirPath() + "/../ProjetLOGEROT-GIE/img/" + nimg;
    QFile file(imagePath);
    if (!file.exists())
    {
        QPixmap imgb(QCoreApplication::applicationDirPath() + "/../ProjetLOGEROT-GIE/img/baseimg.jpeg");
        QPixmap Resizedimgb = imgb.scaledToWidth(200,Qt::SmoothTransformation);
        ui->img->setPixmap(Resizedimgb);
        validImg = false;
    }
    else
    {
        QPixmap pixmap(imagePath);
        if (pixmap.isNull())
        {
            QPixmap imgb(QCoreApplication::applicationDirPath() + "/../ProjetLOGEROT-GIE/img/baseimg.jpeg");
            QPixmap Resizedimgb = imgb.scaledToWidth(200,Qt::SmoothTransformation);
            ui->img->setPixmap(Resizedimgb);
            validImg = false;
        }
        else
        {
            QPixmap Resizedpixmap = pixmap.scaledToWidth(200,Qt::SmoothTransformation);
            ui->img->setPixmap(Resizedpixmap);
            validImg = true;
        }
    }
}
