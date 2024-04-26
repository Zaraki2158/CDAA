/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionAjouter;
    QAction *actionSupprimer;
    QAction *actionModifier;
    QAction *actionAfficheContact;
    QAction *actionHistorique;
    QAction *actionInteractions;
    QAction *actionCroissant;
    QAction *actionZ_A;
    QAction *actionR_cent;
    QAction *actionAncien;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *ListeContact;
    QLabel *img;
    QTextBrowser *textBrowser;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuContact;
    QMenu *menuAffichage;
    QMenu *menuTri_Alphabetique;
    QMenu *menuTri_par_Date;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAjouter = new QAction(MainWindow);
        actionAjouter->setObjectName(QString::fromUtf8("actionAjouter"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionModifier = new QAction(MainWindow);
        actionModifier->setObjectName(QString::fromUtf8("actionModifier"));
        actionAfficheContact = new QAction(MainWindow);
        actionAfficheContact->setObjectName(QString::fromUtf8("actionAfficheContact"));
        actionHistorique = new QAction(MainWindow);
        actionHistorique->setObjectName(QString::fromUtf8("actionHistorique"));
        actionInteractions = new QAction(MainWindow);
        actionInteractions->setObjectName(QString::fromUtf8("actionInteractions"));
        actionCroissant = new QAction(MainWindow);
        actionCroissant->setObjectName(QString::fromUtf8("actionCroissant"));
        actionZ_A = new QAction(MainWindow);
        actionZ_A->setObjectName(QString::fromUtf8("actionZ_A"));
        actionR_cent = new QAction(MainWindow);
        actionR_cent->setObjectName(QString::fromUtf8("actionR_cent"));
        actionAncien = new QAction(MainWindow);
        actionAncien->setObjectName(QString::fromUtf8("actionAncien"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ListeContact = new QComboBox(centralwidget);
        ListeContact->setObjectName(QString::fromUtf8("ListeContact"));
        ListeContact->setMinimumSize(QSize(250, 0));

        verticalLayout->addWidget(ListeContact);

        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));

        verticalLayout->addWidget(img);


        horizontalLayout_2->addLayout(verticalLayout);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);


        verticalLayout_2->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuContact = new QMenu(menubar);
        menuContact->setObjectName(QString::fromUtf8("menuContact"));
        menuAffichage = new QMenu(menubar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuTri_Alphabetique = new QMenu(menuAffichage);
        menuTri_Alphabetique->setObjectName(QString::fromUtf8("menuTri_Alphabetique"));
        menuTri_par_Date = new QMenu(menuAffichage);
        menuTri_par_Date->setObjectName(QString::fromUtf8("menuTri_par_Date"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuContact->menuAction());
        menubar->addAction(menuAffichage->menuAction());
        menuMenu->addAction(actionQuitter);
        menuContact->addAction(actionAjouter);
        menuContact->addAction(actionSupprimer);
        menuContact->addAction(actionModifier);
        menuContact->addAction(actionInteractions);
        menuAffichage->addAction(actionAfficheContact);
        menuAffichage->addAction(actionHistorique);
        menuAffichage->addSeparator();
        menuAffichage->addAction(menuTri_Alphabetique->menuAction());
        menuAffichage->addAction(menuTri_par_Date->menuAction());
        menuTri_Alphabetique->addAction(actionCroissant);
        menuTri_Alphabetique->addAction(actionZ_A);
        menuTri_par_Date->addAction(actionR_cent);
        menuTri_par_Date->addAction(actionAncien);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Fen\303\252tre Principale", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        actionSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        actionModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        actionAfficheContact->setText(QCoreApplication::translate("MainWindow", "AfficheContact", nullptr));
        actionHistorique->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        actionInteractions->setText(QCoreApplication::translate("MainWindow", "Interactions", nullptr));
        actionCroissant->setText(QCoreApplication::translate("MainWindow", "A-Z", nullptr));
        actionZ_A->setText(QCoreApplication::translate("MainWindow", "Z-A", nullptr));
        actionR_cent->setText(QCoreApplication::translate("MainWindow", "R\303\251cent", nullptr));
        actionAncien->setText(QCoreApplication::translate("MainWindow", "Ancien", nullptr));
        img->setText(QString());
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuContact->setTitle(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        menuAffichage->setTitle(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        menuTri_Alphabetique->setTitle(QCoreApplication::translate("MainWindow", "Tri Alphabetique", nullptr));
        menuTri_par_Date->setTitle(QCoreApplication::translate("MainWindow", "Tri par Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
