#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ajoutercontact.h"
#include <QMainWindow>
#include <QDebug>
#include "gestioncontact.h"
#include <iostream>
#include "supprimer.h"
#include "modifiercontact.h"
#include "interactionstodo.h"
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>

namespace Ui {
class MainWindow;
}

/**
 * @brief La classe MainWindow représente la fenêtre principale de l'application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe MainWindow.
     * @param parent Pointeur vers le widget parent.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe MainWindow.
     */
    ~MainWindow();

    /**
     * @brief gs est un objet de type GestionContact utilisé pour gérer les contacts.
     */
    GestionContact gs;

    /**
     * @brief comparaisonNom est une méthode statique permettant de comparer deux contacts par leur nom.
     * @param contact1 Premier contact à comparer.
     * @param contact2 Deuxième contact à comparer.
     * @return true si le nom du contact1 est inférieur au nom du contact2, sinon false.
     */
    static bool comparaisonNom(const Contact& contact1, const Contact& contact2);

private slots:
    // Méthodes liées aux actions déclenchées par l'interface utilisateur

    void RecuContact(Contact c);
    void RecuSupr(Contact c);
    void RecuModif(Contact c, Contact modif);
    void RecuInteract(Contact c, Interaction i);
    void on_actionQuitter_triggered();
    void on_actionAjouter_triggered();
    void on_actionSupprimer_triggered();
    void on_actionModifier_triggered();
    void on_actionHistorique_triggered();
    void on_ListeContact_currentIndexChanged(const QString &arg1);
    void on_actionAfficheContact_triggered();
    void on_actionInteractions_triggered();
    void on_actionCroissant_triggered();
    void on_actionZ_A_triggered();
    void on_actionR_cent_triggered();
    void on_actionAncien_triggered();

private:
    Ui::MainWindow *ui; // Interface utilisateur associée à la MainWindow
};

#endif // MAINWINDOW_H
