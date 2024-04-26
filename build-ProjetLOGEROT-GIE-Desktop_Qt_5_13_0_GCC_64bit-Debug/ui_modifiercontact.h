/********************************************************************************
** Form generated from reading UI file 'modifiercontact.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERCONTACT_H
#define UI_MODIFIERCONTACT_H

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

class Ui_ModifierContact
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Nom;
    QLineEdit *NomE;
    QLabel *Prenom;
    QLineEdit *PrenomE;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *Affichage;
    QLabel *img;
    QVBoxLayout *verticalLayout_3;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *Modifier;
    QPushButton *Annuler;

    void setupUi(QWidget *ModifierContact)
    {
        if (ModifierContact->objectName().isEmpty())
            ModifierContact->setObjectName(QString::fromUtf8("ModifierContact"));
        ModifierContact->resize(579, 593);
        verticalLayout_4 = new QVBoxLayout(ModifierContact);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Nom = new QLabel(ModifierContact);
        Nom->setObjectName(QString::fromUtf8("Nom"));

        verticalLayout->addWidget(Nom);

        NomE = new QLineEdit(ModifierContact);
        NomE->setObjectName(QString::fromUtf8("NomE"));

        verticalLayout->addWidget(NomE);

        Prenom = new QLabel(ModifierContact);
        Prenom->setObjectName(QString::fromUtf8("Prenom"));

        verticalLayout->addWidget(Prenom);

        PrenomE = new QLineEdit(ModifierContact);
        PrenomE->setObjectName(QString::fromUtf8("PrenomE"));

        verticalLayout->addWidget(PrenomE);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Affichage = new QTextBrowser(ModifierContact);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));

        verticalLayout_2->addWidget(Affichage);

        img = new QLabel(ModifierContact);
        img->setObjectName(QString::fromUtf8("img"));

        verticalLayout_2->addWidget(img);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LNom = new QLabel(ModifierContact);
        LNom->setObjectName(QString::fromUtf8("LNom"));

        verticalLayout_3->addWidget(LNom);

        ENom = new QLineEdit(ModifierContact);
        ENom->setObjectName(QString::fromUtf8("ENom"));

        verticalLayout_3->addWidget(ENom);

        LPrenom = new QLabel(ModifierContact);
        LPrenom->setObjectName(QString::fromUtf8("LPrenom"));

        verticalLayout_3->addWidget(LPrenom);

        EPrenom = new QLineEdit(ModifierContact);
        EPrenom->setObjectName(QString::fromUtf8("EPrenom"));

        verticalLayout_3->addWidget(EPrenom);

        LEntreprise = new QLabel(ModifierContact);
        LEntreprise->setObjectName(QString::fromUtf8("LEntreprise"));

        verticalLayout_3->addWidget(LEntreprise);

        EEntreprise = new QLineEdit(ModifierContact);
        EEntreprise->setObjectName(QString::fromUtf8("EEntreprise"));

        verticalLayout_3->addWidget(EEntreprise);

        LMail = new QLabel(ModifierContact);
        LMail->setObjectName(QString::fromUtf8("LMail"));

        verticalLayout_3->addWidget(LMail);

        EMail = new QLineEdit(ModifierContact);
        EMail->setObjectName(QString::fromUtf8("EMail"));

        verticalLayout_3->addWidget(EMail);

        LTelephone = new QLabel(ModifierContact);
        LTelephone->setObjectName(QString::fromUtf8("LTelephone"));

        verticalLayout_3->addWidget(LTelephone);

        ETelephone = new QLineEdit(ModifierContact);
        ETelephone->setObjectName(QString::fromUtf8("ETelephone"));

        verticalLayout_3->addWidget(ETelephone);

        LPhoto = new QLabel(ModifierContact);
        LPhoto->setObjectName(QString::fromUtf8("LPhoto"));

        verticalLayout_3->addWidget(LPhoto);

        EPhoto = new QLineEdit(ModifierContact);
        EPhoto->setObjectName(QString::fromUtf8("EPhoto"));

        verticalLayout_3->addWidget(EPhoto);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Modifier = new QPushButton(ModifierContact);
        Modifier->setObjectName(QString::fromUtf8("Modifier"));

        horizontalLayout->addWidget(Modifier);

        Annuler = new QPushButton(ModifierContact);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));

        horizontalLayout->addWidget(Annuler);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(ModifierContact);

        QMetaObject::connectSlotsByName(ModifierContact);
    } // setupUi

    void retranslateUi(QWidget *ModifierContact)
    {
        ModifierContact->setWindowTitle(QCoreApplication::translate("ModifierContact", "Modif_Contact", nullptr));
        Nom->setText(QCoreApplication::translate("ModifierContact", "Nom", nullptr));
        Prenom->setText(QCoreApplication::translate("ModifierContact", "Pr\303\251nom", nullptr));
        img->setText(QString());
        LNom->setText(QCoreApplication::translate("ModifierContact", "Nom", nullptr));
        LPrenom->setText(QCoreApplication::translate("ModifierContact", "Pr\303\251nom", nullptr));
        LEntreprise->setText(QCoreApplication::translate("ModifierContact", "Entreprise", nullptr));
        LMail->setText(QCoreApplication::translate("ModifierContact", "Mail", nullptr));
        LTelephone->setText(QCoreApplication::translate("ModifierContact", "Telephone", nullptr));
        LPhoto->setText(QCoreApplication::translate("ModifierContact", "Photo", nullptr));
        Modifier->setText(QCoreApplication::translate("ModifierContact", "Modifier", nullptr));
        Annuler->setText(QCoreApplication::translate("ModifierContact", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifierContact: public Ui_ModifierContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERCONTACT_H
