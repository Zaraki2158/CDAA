/********************************************************************************
** Form generated from reading UI file 'supprimer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMER_H
#define UI_SUPPRIMER_H

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

class Ui_Supprimer
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Nom;
    QLineEdit *NomE;
    QLabel *Prenom;
    QLineEdit *PrenomE;
    QPushButton *Supprimer_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *Affichage;
    QPushButton *Annuler;

    void setupUi(QWidget *Supprimer)
    {
        if (Supprimer->objectName().isEmpty())
            Supprimer->setObjectName(QString::fromUtf8("Supprimer"));
        Supprimer->resize(543, 485);
        horizontalLayout = new QHBoxLayout(Supprimer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Nom = new QLabel(Supprimer);
        Nom->setObjectName(QString::fromUtf8("Nom"));

        verticalLayout->addWidget(Nom);

        NomE = new QLineEdit(Supprimer);
        NomE->setObjectName(QString::fromUtf8("NomE"));

        verticalLayout->addWidget(NomE);

        Prenom = new QLabel(Supprimer);
        Prenom->setObjectName(QString::fromUtf8("Prenom"));

        verticalLayout->addWidget(Prenom);

        PrenomE = new QLineEdit(Supprimer);
        PrenomE->setObjectName(QString::fromUtf8("PrenomE"));

        verticalLayout->addWidget(PrenomE);

        Supprimer_2 = new QPushButton(Supprimer);
        Supprimer_2->setObjectName(QString::fromUtf8("Supprimer_2"));

        verticalLayout->addWidget(Supprimer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Affichage = new QTextBrowser(Supprimer);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));

        verticalLayout_2->addWidget(Affichage);

        Annuler = new QPushButton(Supprimer);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));

        verticalLayout_2->addWidget(Annuler);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Supprimer);

        QMetaObject::connectSlotsByName(Supprimer);
    } // setupUi

    void retranslateUi(QWidget *Supprimer)
    {
        Supprimer->setWindowTitle(QCoreApplication::translate("Supprimer", "Supprimer_Contact", nullptr));
        Nom->setText(QCoreApplication::translate("Supprimer", "Nom", nullptr));
        Prenom->setText(QCoreApplication::translate("Supprimer", "Pr\303\251nom", nullptr));
        Supprimer_2->setText(QCoreApplication::translate("Supprimer", "Supprimer", nullptr));
        Annuler->setText(QCoreApplication::translate("Supprimer", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Supprimer: public Ui_Supprimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMER_H
