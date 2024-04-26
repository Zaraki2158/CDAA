#include "gestioncontact.h"
#include "todo.h"
#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QSqlError>


int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("BDD.sqlite");

        // Vérifier si le fichier de base de données existe
        if (!QFile::exists("BDD.sqlite")) {
            // S'il n'existe pas, créer le fichier
            QFile::copy(":/emptydb", "BDD.sqlite");
        }

        if (!db.open()) {
            qDebug() << "Erreur lors de l'ouverture de la base de données :" << db.lastError().text();
            return 1;
        }

        QSqlQuery query;
        // Requête SQL pour créer la table "contact" si elle n'existe pas déjà
        QString createTableSQL = "CREATE TABLE IF NOT EXISTS contact ("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                 "nom TEXT NOT NULL,"
                                 "prenom TEXT NOT NULL,"
                                 "entreprise TEXT,"
                                 "mail TEXT,"
                                 "telephone TEXT,"
                                 "urlphoto TEXT,"
                                 "date_jour INTEGER,"
                                 "date_mois INTEGER,"
                                 "date_annee INTEGER,"
                                 "date_heure INTEGER,"
                                 "date_min INTEGER"
                                 ");";

        if (!query.exec(createTableSQL)) {
            qDebug() << "Erreur lors de la création de la table :" << query.lastError().text();
        } else {
            qDebug() << "Table 'contact' créée avec succès.";
        }


        // Requête SQL pour créer la table "interaction" si elle n'existe pas déjà
        QString createInteractionTableSQL = "CREATE TABLE IF NOT EXISTS interaction ("
                                             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                             "contenu TEXT NOT NULL,"
                                             "date_jour INTEGER,"
                                             "date_mois INTEGER,"
                                             "date_annee INTEGER,"
                                             "contact_id INTEGER,"
                                             "FOREIGN KEY(contact_id) REFERENCES contact(id)"
                                             ");";

            if (!query.exec(createInteractionTableSQL)) {
                qDebug() << "Erreur lors de la création de la table interaction :" << query.lastError().text();
                return 1;
            } else {
                qDebug() << "Table 'interaction' créée avec succès.";
            }


            // Requête SQL pour créer la table "todo" si elle n'existe pas déjà
            QString createTodoTableSQL = "CREATE TABLE IF NOT EXISTS todo ("
                                         "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                         "contenu TEXT NOT NULL,"
                                         "date_jour INTEGER,"
                                         "date_mois INTEGER,"
                                         "date_annee INTEGER,"
                                         "interaction_id INTEGER,"
                                         "FOREIGN KEY(interaction_id) REFERENCES interaction(id)"
                                         ");";



            if (!query.exec(createTodoTableSQL)) {
                qDebug() << "Erreur lors de la création de la table todo:" << query.lastError().text();
                return 1;
            } else {
                qDebug() << "Table 'todo' créée avec succès.";
            }


            QString TableHistorique = "CREATE TABLE IF NOT EXISTS histo("
                                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                      "modif TEXT NOT NULL,"
                                      "date_jour INTEGER,"
                                      "date_mois INTEGER,"
                                      "date_annee INTEGER"
                                      ");";

            if (!query.exec(TableHistorique)) {
                qDebug() << "Erreur lors de la création de la table histo:" << query.lastError().text();
                return 1;
            } else {
                qDebug() << "Table 'histo' créée avec succès.";
            }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();

}
