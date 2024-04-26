#include "ajoutercontact.h"
#include "ui_ajoutercontact.h"
#include <iostream>
#include <QFile>

/**
 * @brief Constructeur de la classe AjouterContact.
 * @param parent Le widget parent de cette fenêtre.
 */
AjouterContact::AjouterContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterContact)
{
    ui->setupUi(this);
    QRegExp regexN("[A-Z][a-z]*");
    QRegExpValidator *validatorN = new QRegExpValidator(regexN, ui->ENom);
    ui->ENom->setValidator(validatorN);
    QRegExp regexP("[A-Z][a-z]*");
    QRegExpValidator *validatorP = new QRegExpValidator(regexP, ui->EPrenom);
    ui->EPrenom->setValidator(validatorP);
    QRegExp regexNum("[0-9]\\d{9}$");
    QRegExpValidator * validatorNum = new QRegExpValidator(regexNum, ui->ETelephone);
    ui->ETelephone->setValidator(validatorNum);
    QRegExp regexM(".*@.*\.fr");
    QRegExpValidator *validatorM = new QRegExpValidator(regexM, ui->EMail);
    ui->EMail->setValidator(validatorM);
    QPixmap imgb(QCoreApplication::applicationDirPath() + "/../ProjetLOGEROT-GIE/img/baseimg.jpeg");
    if (imgb.isNull()) {
        qDebug("Impossible de charger l'image");
    } else {
        QPixmap Resizedimgb = imgb.scaledToWidth(200,Qt::SmoothTransformation);
        ui->img->setPixmap(Resizedimgb);
    }
}

/**
 * @brief Destructeur de la classe AjouterContact.
 * Libère la mémoire utilisée par l'interface utilisateur.
 */
AjouterContact::~AjouterContact()
{
    delete ui;
}


/**
 * @brief Slot appelé lors du clic sur le bouton "Ajouter".
 * Récupère les données des champs de texte pour créer un nouveau contact.
 */
void AjouterContact::on_Ajouter_clicked()
{
    std::string Nom = ui->ENom->text().toStdString();
    std::string Prenom = ui->EPrenom->text().toStdString();
    std::string Entreprise = ui->EEntreprise->text().toStdString();
    std::string Telephone = ui->ETelephone->text().toStdString();
    std::string Photo;
    if(validImg = true)
            Photo = ui->EPhoto->text().toStdString();
    else
            Photo = "baseimg.jpeg";
    std::string Mail = ui->EMail->text().toStdString();
    Contact C(Nom,Prenom,Entreprise,Mail,Telephone,Photo);
    emit EnvoieContact(C);

    close();
}

/**
 * @brief Slot appelé lors de la modification du champ de texte pour le nom.
 * Met à jour l'affichage des données du contact en temps réel.
 * @param arg1 La nouvelle valeur du champ de texte.
 */
void AjouterContact::on_ENom_textChanged(const QString &arg1)
{

    ui->Affichage->setText("Nom : "+ui->ENom->text());
    ui->Affichage->append("Prénom : "+ui->EPrenom->text());
    ui->Affichage->append("Entreprise : "+ui->EEntreprise->text());
    ui->Affichage->append("Mail : "+ui->EMail->text());
    ui->Affichage->append("Téléphone : "+ui->ETelephone->text());
    ui->Affichage->append("Photo : "+ui->EPhoto->text());
}

/**
 * @brief Met à jour l'affichage lorsque le prénom est modifié.
 * @param arg1 Nouveau texte du prénom.
 */
void AjouterContact::on_EPrenom_textChanged(const QString &arg1)
{
    ui->Affichage->setText("Nom : "+ui->ENom->text());
    ui->Affichage->append("Prénom : "+ui->EPrenom->text());
    ui->Affichage->append("Entreprise : "+ui->EEntreprise->text());
    ui->Affichage->append("Mail : "+ui->EMail->text());
    ui->Affichage->append("Téléphone : "+ui->ETelephone->text());
    ui->Affichage->append("Photo : "+ui->EPhoto->text());
}


/**
 * @brief Met à jour l'affichage lorsque le champ entreprise est modifié.
 * @param arg1 Nouveau texte du champ entreprise.
 */
void AjouterContact::on_EEntreprise_textChanged(const QString &arg1)
{
    ui->Affichage->setText("Nom : "+ui->ENom->text());
    ui->Affichage->append("Prénom : "+ui->EPrenom->text());
    ui->Affichage->append("Entreprise : "+ui->EEntreprise->text());
    ui->Affichage->append("Mail : "+ui->EMail->text());
    ui->Affichage->append("Téléphone : "+ui->ETelephone->text());
    ui->Affichage->append("Photo : "+ui->EPhoto->text());
}

/**
 * @brief Met à jour l'affichage lorsque le numéro de téléphone est modifié.
 * @param arg1 Nouveau texte du numéro de téléphone.
 */
void AjouterContact::on_ETelephone_textChanged(const QString &arg1)
{
    ui->Affichage->setText("Nom : "+ui->ENom->text());
    ui->Affichage->append("Prénom : "+ui->EPrenom->text());
    ui->Affichage->append("Entreprise : "+ui->EEntreprise->text());
    ui->Affichage->append("Mail : "+ui->EMail->text());
    ui->Affichage->append("Téléphone : "+ui->ETelephone->text());
    ui->Affichage->append("Photo : "+ui->EPhoto->text());
}

/**
 * @brief Met à jour l'affichage lorsque le champ de la photo est modifié.
 * @param arg1 Nouveau texte du champ de la photo.
 */
void AjouterContact::on_EPhoto_textChanged(const QString &arg1)
{
    ui->Affichage->setText("Nom : "+ui->ENom->text());
    ui->Affichage->append("Prénom : "+ui->EPrenom->text());
    ui->Affichage->append("Entreprise : "+ui->EEntreprise->text());
    ui->Affichage->append("Mail : "+ui->EMail->text());
    ui->Affichage->append("Téléphone : "+ui->ETelephone->text());
    ui->Affichage->append("Photo : "+ui->EPhoto->text());
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

/**
 * @brief Slot appelé lors de la modification du champ de texte pour l'e-mail.
 * Met à jour l'affichage des données du contact en temps réel.
 * @param arg1 La nouvelle valeur du champ de texte.
 */
void AjouterContact::on_EMail_textChanged(const QString &arg1)
{
    ui->Affichage->setText("Nom : "+ui->ENom->text());
    ui->Affichage->append("Prénom : "+ui->EPrenom->text());
    ui->Affichage->append("Entreprise : "+ui->EEntreprise->text());
    ui->Affichage->append("Mail : "+ui->EMail->text());
    ui->Affichage->append("Téléphone : "+ui->ETelephone->text());
    ui->Affichage->append("Photo : "+ui->EPhoto->text());
}


/**
 * @brief Slot appelé lors du clic sur le bouton "Annuler".
 * Ferme la fenêtre sans ajouter de contact.
 */
void AjouterContact::on_Annuler_clicked()
{
    close();
}
