/********************************************************************************
** Form generated from reading UI file 'ajoutercontact.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERCONTACT_H
#define UI_AJOUTERCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjouterContact
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *LNom;
    QLineEdit *ENom;
    QLabel *LPrenom;
    QLineEdit *EPrenom;
    QLabel *LEntreprise;
    QLineEdit *EEntreprise;
    QLabel *LMail;
    QLineEdit *EMail;
    QLabel *LTelephone;
    QLineEdit *ETelephone;
    QLabel *LPhoto;
    QLineEdit *EPhoto;
    QVBoxLayout *layout_txt;
    QTextBrowser *Affichage;
    QLabel *img;
    QHBoxLayout *horizontalLayout;
    QPushButton *Ajouter;
    QPushButton *Annuler;

    void setupUi(QWidget *AjouterContact)
    {
        if (AjouterContact->objectName().isEmpty())
            AjouterContact->setObjectName(QString::fromUtf8("AjouterContact"));
        AjouterContact->resize(440, 573);
        verticalLayout_8 = new QVBoxLayout(AjouterContact);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LNom = new QLabel(AjouterContact);
        LNom->setObjectName(QString::fromUtf8("LNom"));

        verticalLayout->addWidget(LNom);

        ENom = new QLineEdit(AjouterContact);
        ENom->setObjectName(QString::fromUtf8("ENom"));

        verticalLayout->addWidget(ENom);

        LPrenom = new QLabel(AjouterContact);
        LPrenom->setObjectName(QString::fromUtf8("LPrenom"));

        verticalLayout->addWidget(LPrenom);

        EPrenom = new QLineEdit(AjouterContact);
        EPrenom->setObjectName(QString::fromUtf8("EPrenom"));

        verticalLayout->addWidget(EPrenom);

        LEntreprise = new QLabel(AjouterContact);
        LEntreprise->setObjectName(QString::fromUtf8("LEntreprise"));

        verticalLayout->addWidget(LEntreprise);

        EEntreprise = new QLineEdit(AjouterContact);
        EEntreprise->setObjectName(QString::fromUtf8("EEntreprise"));

        verticalLayout->addWidget(EEntreprise);

        LMail = new QLabel(AjouterContact);
        LMail->setObjectName(QString::fromUtf8("LMail"));

        verticalLayout->addWidget(LMail);

        EMail = new QLineEdit(AjouterContact);
        EMail->setObjectName(QString::fromUtf8("EMail"));

        verticalLayout->addWidget(EMail);

        LTelephone = new QLabel(AjouterContact);
        LTelephone->setObjectName(QString::fromUtf8("LTelephone"));

        verticalLayout->addWidget(LTelephone);

        ETelephone = new QLineEdit(AjouterContact);
        ETelephone->setObjectName(QString::fromUtf8("ETelephone"));

        verticalLayout->addWidget(ETelephone);

        LPhoto = new QLabel(AjouterContact);
        LPhoto->setObjectName(QString::fromUtf8("LPhoto"));

        verticalLayout->addWidget(LPhoto);

        EPhoto = new QLineEdit(AjouterContact);
        EPhoto->setObjectName(QString::fromUtf8("EPhoto"));

        verticalLayout->addWidget(EPhoto);


        horizontalLayout_2->addLayout(verticalLayout);

        layout_txt = new QVBoxLayout();
        layout_txt->setObjectName(QString::fromUtf8("layout_txt"));
        Affichage = new QTextBrowser(AjouterContact);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));

        layout_txt->addWidget(Affichage);

        img = new QLabel(AjouterContact);
        img->setObjectName(QString::fromUtf8("img"));
        img->setMinimumSize(QSize(50, 200));

        layout_txt->addWidget(img);


        horizontalLayout_2->addLayout(layout_txt);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Ajouter = new QPushButton(AjouterContact);
        Ajouter->setObjectName(QString::fromUtf8("Ajouter"));

        horizontalLayout->addWidget(Ajouter);

        Annuler = new QPushButton(AjouterContact);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));

        horizontalLayout->addWidget(Annuler);


        verticalLayout_8->addLayout(horizontalLayout);


        retranslateUi(AjouterContact);

        QMetaObject::connectSlotsByName(AjouterContact);
    } // setupUi

    void retranslateUi(QWidget *AjouterContact)
    {
        AjouterContact->setWindowTitle(QCoreApplication::translate("AjouterContact", "Ajout_Contact", nullptr));
        LNom->setText(QCoreApplication::translate("AjouterContact", "Nom", nullptr));
        LPrenom->setText(QCoreApplication::translate("AjouterContact", "Pr\303\251nom", nullptr));
        LEntreprise->setText(QCoreApplication::translate("AjouterContact", "Entreprise", nullptr));
        LMail->setText(QCoreApplication::translate("AjouterContact", "Mail", nullptr));
        LTelephone->setText(QCoreApplication::translate("AjouterContact", "Telephone", nullptr));
        LPhoto->setText(QCoreApplication::translate("AjouterContact", "Photo", nullptr));
        img->setText(QString());
        Ajouter->setText(QCoreApplication::translate("AjouterContact", "Ajouter", nullptr));
        Annuler->setText(QCoreApplication::translate("AjouterContact", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterContact: public Ui_AjouterContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERCONTACT_H
