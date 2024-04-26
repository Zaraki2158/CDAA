/********************************************************************************
** Form generated from reading UI file 'interactionstodo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIONSTODO_H
#define UI_INTERACTIONSTODO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InteractionsTodo
{
public:
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *Nom_3;
    QLineEdit *NomE_3;
    QLabel *Prenom_3;
    QLineEdit *PrenomE_3;
    QTextBrowser *Affichage_3;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QLabel *Interactions;
    QLineEdit *InteractionsE;
    QVBoxLayout *verticalLayout_11;
    QLabel *Todo;
    QLabel *Valide;
    QLineEdit *TodoE;
    QDateTimeEdit *DateTodo;
    QPushButton *AjoutTodo;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Interact;
    QPushButton *Annuler_3;

    void setupUi(QWidget *InteractionsTodo)
    {
        if (InteractionsTodo->objectName().isEmpty())
            InteractionsTodo->setObjectName(QString::fromUtf8("InteractionsTodo"));
        InteractionsTodo->resize(724, 602);
        verticalLayout_10 = new QVBoxLayout(InteractionsTodo);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        Nom_3 = new QLabel(InteractionsTodo);
        Nom_3->setObjectName(QString::fromUtf8("Nom_3"));

        verticalLayout_7->addWidget(Nom_3);

        NomE_3 = new QLineEdit(InteractionsTodo);
        NomE_3->setObjectName(QString::fromUtf8("NomE_3"));

        verticalLayout_7->addWidget(NomE_3);

        Prenom_3 = new QLabel(InteractionsTodo);
        Prenom_3->setObjectName(QString::fromUtf8("Prenom_3"));

        verticalLayout_7->addWidget(Prenom_3);

        PrenomE_3 = new QLineEdit(InteractionsTodo);
        PrenomE_3->setObjectName(QString::fromUtf8("PrenomE_3"));

        verticalLayout_7->addWidget(PrenomE_3);


        horizontalLayout_5->addLayout(verticalLayout_7);

        Affichage_3 = new QTextBrowser(InteractionsTodo);
        Affichage_3->setObjectName(QString::fromUtf8("Affichage_3"));

        horizontalLayout_5->addWidget(Affichage_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        Interactions = new QLabel(InteractionsTodo);
        Interactions->setObjectName(QString::fromUtf8("Interactions"));

        verticalLayout_9->addWidget(Interactions);

        InteractionsE = new QLineEdit(InteractionsTodo);
        InteractionsE->setObjectName(QString::fromUtf8("InteractionsE"));

        verticalLayout_9->addWidget(InteractionsE);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        Todo = new QLabel(InteractionsTodo);
        Todo->setObjectName(QString::fromUtf8("Todo"));

        verticalLayout_11->addWidget(Todo);

        Valide = new QLabel(InteractionsTodo);
        Valide->setObjectName(QString::fromUtf8("Valide"));
        Valide->setMinimumSize(QSize(206, 0));
        Valide->setMaximumSize(QSize(100, 20));

        verticalLayout_11->addWidget(Valide);


        verticalLayout_9->addLayout(verticalLayout_11);

        TodoE = new QLineEdit(InteractionsTodo);
        TodoE->setObjectName(QString::fromUtf8("TodoE"));

        verticalLayout_9->addWidget(TodoE);

        DateTodo = new QDateTimeEdit(InteractionsTodo);
        DateTodo->setObjectName(QString::fromUtf8("DateTodo"));

        verticalLayout_9->addWidget(DateTodo);

        AjoutTodo = new QPushButton(InteractionsTodo);
        AjoutTodo->setObjectName(QString::fromUtf8("AjoutTodo"));

        verticalLayout_9->addWidget(AjoutTodo);


        horizontalLayout_5->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Interact = new QPushButton(InteractionsTodo);
        Interact->setObjectName(QString::fromUtf8("Interact"));

        horizontalLayout_6->addWidget(Interact);

        Annuler_3 = new QPushButton(InteractionsTodo);
        Annuler_3->setObjectName(QString::fromUtf8("Annuler_3"));

        horizontalLayout_6->addWidget(Annuler_3);


        verticalLayout_10->addLayout(horizontalLayout_6);


        retranslateUi(InteractionsTodo);

        QMetaObject::connectSlotsByName(InteractionsTodo);
    } // setupUi

    void retranslateUi(QWidget *InteractionsTodo)
    {
        InteractionsTodo->setWindowTitle(QCoreApplication::translate("InteractionsTodo", "Ajout_Interaction_Todo", nullptr));
        Nom_3->setText(QCoreApplication::translate("InteractionsTodo", "Nom", nullptr));
        Prenom_3->setText(QCoreApplication::translate("InteractionsTodo", "Pr\303\251nom", nullptr));
        Interactions->setText(QCoreApplication::translate("InteractionsTodo", "Interactions", nullptr));
        Todo->setText(QCoreApplication::translate("InteractionsTodo", "Todo", nullptr));
        Valide->setText(QString());
        AjoutTodo->setText(QCoreApplication::translate("InteractionsTodo", "AjoutTodo", nullptr));
        Interact->setText(QCoreApplication::translate("InteractionsTodo", "Ajout Interactions", nullptr));
        Annuler_3->setText(QCoreApplication::translate("InteractionsTodo", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InteractionsTodo: public Ui_InteractionsTodo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIONSTODO_H
