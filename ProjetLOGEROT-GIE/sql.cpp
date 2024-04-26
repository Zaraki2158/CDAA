#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "gestioncontact.h"


/**
 * @brief Ajoute un contact à la base de données.
 * @param c Le contact à ajouter.
 */

void ajoutContactSQL(const Contact& c)
{
    // Convertir les propriétés du contact en QString
    QString nom = QString::fromStdString(c.getNom());
    QString prenom = QString::fromStdString(c.getPrenom());
    QString entreprise = QString::fromStdString(c.getEntreprise());
    QString telephone = QString::fromStdString(c.getTelephone());
    QString mail = QString::fromStdString(c.getMail());
    QString urlPhoto = QString::fromStdString(c.getPhoto());
    QString annee = QString::number(c.date.annee);
    QString mois = QString::number(c.date.mois);
    QString jour = QString::number(c.date.jour);
    QString heure = QString::number(c.date.heure);
    QString min = QString::number(c.date.min);

    // Préparer la requête SQL pour l'ajout du contact
    QSqlQuery query;
    QString insertContactSQL = "INSERT INTO contact (nom, prenom, entreprise, mail, telephone, urlphoto, date_jour, date_mois, date_annee, date_heure, date_min)"
                               "VALUES (:nom, :prenom, :entreprise, :mail, :telephone, :urlPhoto, :jour, :mois, :annee, :heure, :min);";
    query.prepare(insertContactSQL);

    // Binder les valeurs à la requête
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":entreprise", entreprise);
    query.bindValue(":mail", mail);
    query.bindValue(":telephone", telephone);
    query.bindValue(":urlPhoto", urlPhoto);
    query.bindValue(":jour", jour);
    query.bindValue(":mois", mois);
    query.bindValue(":annee", annee);
    query.bindValue(":heure", heure);
    query.bindValue(":min", min);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du contact :" << query.lastError().text();
    } else {
        qDebug() << "Contact ajouté avec succès.";
    }

    // Fermer la base de données
}


/**
 * @brief Supprime un contact de la base de données.
 * @param c Le contact à supprimer.
 */

void SuprContactSQL(Contact c)
{
    QString nom = QString::fromStdString(c.getNom());
    QString prenom = QString::fromStdString(c.getPrenom());

    // Récupérer l'ID du contact supprimé
    QString selectContactIDSQL = "SELECT id FROM contact WHERE nom = :nom AND prenom = :prenom";
    QSqlQuery selectIDQuery;
    selectIDQuery.prepare(selectContactIDSQL);
    selectIDQuery.bindValue(":nom", nom);
    selectIDQuery.bindValue(":prenom", prenom);

    if (!selectIDQuery.exec()) {
        qDebug() << "Erreur lors de la récupération de l'ID du contact :" << selectIDQuery.lastError().text();
        return;
    }

    int contactID = -1;
    if (selectIDQuery.next()) {
        contactID = selectIDQuery.value("id").toInt();
    }

    QSqlQuery query;
    QString deleteContactSQL = "DELETE FROM contact WHERE nom = :nom AND prenom = :prenom";
    query.prepare(deleteContactSQL);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du contact :" << query.lastError().text();
        return;
    } else {
        qDebug() << "Contact supprimé avec succès.";
    }

    // Supprimer les todos associés à ces interactions
    QString deleteTodosSQL = "DELETE FROM todo WHERE interaction_id IN (SELECT id FROM interaction WHERE contact_id = :contactID)";
    QSqlQuery deleteTodosQuery;
    deleteTodosQuery.prepare(deleteTodosSQL);
    deleteTodosQuery.bindValue(":contactID", contactID);

    if (!deleteTodosQuery.exec())
    {
        qDebug() << "Erreur lors de la suppression des todos :" << deleteTodosQuery.lastError().text();
        return;
    }
    else
    {
        qDebug() << "Todo supprimés avec succès.";
    }

    // Supprimer les interactions associées à ce contact
    QString deleteInteractionsSQL = "DELETE FROM interaction WHERE contact_id = :contactID";
    QSqlQuery deleteInteractionsQuery;
    deleteInteractionsQuery.prepare(deleteInteractionsSQL);
    deleteInteractionsQuery.bindValue(":contactID", contactID);

    if (!deleteInteractionsQuery.exec()) {
        qDebug() << "Erreur lors de la suppression des interactions :" << deleteInteractionsQuery.lastError().text();
        return;
    }
    else
    {
        qDebug() << "Interactions supprimées avec succès.";
    }



}


/**
 * @brief Modifie les informations d'un contact dans la base de données.
 * @param c Le contact à modifier.
 * @param nouveauContact Les nouvelles informations du contact.
 */

void ModifContactSQL(Contact c, Contact nouveauContact)
{
        QString nom = QString::fromStdString(c.getNom());
        QString prenom = QString::fromStdString(c.getPrenom());
        QString Nnom = QString::fromStdString(nouveauContact.getNom());
        QString Nprenom = QString::fromStdString(nouveauContact.getPrenom());
        QString Nentreprise = QString::fromStdString(nouveauContact.getEntreprise());
        QString Ntelephone = QString::fromStdString(nouveauContact.getTelephone());
        QString Nmail = QString::fromStdString(nouveauContact.getMail());
        QString NurlPhoto = QString::fromStdString(nouveauContact.getPhoto());
        QString Nannee = QString::number(nouveauContact.date.annee);
        QString Nmois = QString::number(nouveauContact.date.mois);
        QString Njour = QString::number(nouveauContact.date.jour);
        QString Nheure = QString::number(nouveauContact.date.heure);
        QString Nmin = QString::number(nouveauContact.date.min);
        QSqlQuery query;
        QString updateContactSQL = "UPDATE contact SET nom = :nouveauNom, prenom = :nouveauPrenom, entreprise = :nouvelleEntreprise, "
                                   "mail = :nouveauMail, telephone = :nouveauTelephone, urlphoto = :nouvelleUrlPhoto WHERE nom = :ancienNom AND prenom = :ancienPrenom";
        query.prepare(updateContactSQL);
        query.bindValue(":nouveauNom", Nnom);
        query.bindValue(":nouveauPrenom", Nprenom);
        query.bindValue(":nouvelleEntreprise", Nentreprise);
        query.bindValue(":nouveauMail", Nmail);
        query.bindValue(":nouveauTelephone", Ntelephone);
        query.bindValue(":nouvelleUrlPhoto", NurlPhoto);
        query.bindValue(":ancienNom", nom);
        query.bindValue(":ancienPrenom", prenom);

        // Exécuter la requête
        if (!query.exec()) {
            qDebug() << "Erreur lors de la modification du contact :" << query.lastError().text();
        } else {
            qDebug() << "Contact modifié avec succès.";
        }
}


/**
 * @brief Ajoute une interaction à un contact dans la base de données.
 * @param I L'interaction à ajouter.
 * @param c Le contact associé à l'interaction.
 */

void ajouterInteractionSQL(Interaction I,Contact c)
{
    QString contenu = QString::fromStdString(I.getContenu());
    QString annee = QString::number(I.getDate().annee);
    QString mois = QString::number(I.getDate().mois);
    QString jour = QString::number(I.getDate().jour);
    QString nom = QString::fromStdString(c.getNom());
    QString prenom = QString::fromStdString(c.getPrenom());

    // Récupérer l'ID du contact
    QSqlQuery query;
    QString getContactIDSQL = "SELECT id FROM contact WHERE nom = :nom AND prenom = :prenom";
    query.prepare(getContactIDSQL);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération de l'ID du contact :" << query.lastError().text();
        return;
    }

    int contactID = -1;
    if (query.next()) {
        contactID = query.value(0).toInt();
    }

    // Insérer l'interaction dans la table "interaction"
    QString insertInteractionSQL = "INSERT INTO interaction (contenu, date_jour, date_mois, date_annee, contact_id) "
                                   "VALUES (:contenu, :jour, :mois, :annee, :contactID)";
    query.prepare(insertInteractionSQL);
    query.bindValue(":contenu", contenu);
    query.bindValue(":jour", jour);
    query.bindValue(":mois", mois);
    query.bindValue(":annee", annee);
    query.bindValue(":contactID", contactID);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'interaction :" << query.lastError().text();
    } else {
        qDebug() << "Interaction ajoutée avec succès.";
    }
}


/**
 * @brief Ajoute un todo à une interaction associée à un contact dans la base de données.
 * @param T Le todo à ajouter.
 * @param c Le contact associé à l'interaction.
 */

void ajouterTodoSQL(Todo T,Contact c)
{
    QString contenu = QString::fromStdString(T.getContenu());
    QString annee = QString::number(T.getDate().annee);
    QString mois = QString::number(T.getDate().mois);
    QString jour = QString::number(T.getDate().jour);
    QString nom = QString::fromStdString(c.getNom());
    QString prenom = QString::fromStdString(c.getPrenom());

    // Récupérer l'ID de l'interaction associée au contact
    QSqlQuery query;
    QString getInteractionIDSQL = "SELECT interaction.id FROM interaction, contact "
                                  "WHERE interaction.contact_id = contact.id AND contact.nom = :nom AND contact.prenom = :prenom";
    query.prepare(getInteractionIDSQL);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération de l'ID de l'interaction :" << query.lastError().text();
        return;
    }

    int interactionID = -1;
    if (query.next()) {
        interactionID = query.value(0).toInt();
    }

    // Insérer le todo dans la table "todo"
    QString insertTodoSQL = "INSERT INTO todo (contenu, date_jour, date_mois, date_annee, interaction_id) "
                            "VALUES (:contenu, :jour, :mois, :annee, :interactionID)";
    query.prepare(insertTodoSQL);
    query.bindValue(":contenu", contenu);
    query.bindValue(":jour", jour);
    query.bindValue(":mois", mois);
    query.bindValue(":annee", annee);
    query.bindValue(":interactionID", interactionID);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du todo :" << query.lastError().text();
    } else {
        qDebug() << "Todo ajouté avec succès.";
    }

}


/**
 * @brief Récupère les contacts et leurs informations depuis la base de données.
 * @return Un objet GestionContact contenant les contacts récupérés.
 */

GestionContact recupererContactsDepuisSQL()
{
    GestionContact gestionContact;

    QSqlQuery queryHisto;
    QString selectHistoSQL = "SELECT * FROM histo";
    if (!queryHisto.exec(selectHistoSQL)) {
        qDebug() << "Erreur lors de la récupération de l'historique:" << queryHisto.lastError().text();
        return gestionContact;
    }

    while (queryHisto.next())
    {
        Date d;
        d.jour = queryHisto.value("date_jour").toInt();
        d.mois = queryHisto.value("date_mois").toInt();
        d.annee = queryHisto.value("date_annee").toInt();
        Historique h(queryHisto.value("modif").toString().toStdString(),d);
        gestionContact.ajouteHisto(h);
    }

    QSqlQuery query;
    QString selectContactsSQL = "SELECT * FROM contact";
    if (!query.exec(selectContactsSQL)) {
        qDebug() << "Erreur lors de la récupération des contacts :" << query.lastError().text();
        return gestionContact;
    }

    while (query.next()) {
        Contact c;
        c.setNom(query.value("nom").toString().toStdString());
        c.setPrenom(query.value("prenom").toString().toStdString());
        c.setEntreprise(query.value("entreprise").toString().toStdString());
        c.setMail(query.value("mail").toString().toStdString());
        c.setTelephone(query.value("telephone").toString().toStdString());
        c.setPhoto(query.value("urlphoto").toString().toStdString());

        // Récupérer les interactions associées à ce contact
        int contactID = query.value("id").toInt();
        QString selectInteractionsSQL = "SELECT * FROM interaction WHERE contact_id = :contactID";
        QSqlQuery interactionQuery;
        interactionQuery.prepare(selectInteractionsSQL);
        interactionQuery.bindValue(":contactID", contactID);

        if (!interactionQuery.exec()) {
            qDebug() << "Erreur lors de la récupération des interactions :" << interactionQuery.lastError().text();
            return gestionContact;
        }

        while (interactionQuery.next()) {
            Interaction interaction;
            interaction.setContenu(interactionQuery.value("contenu").toString().toStdString());
            Date d;
            d.jour = interactionQuery.value("date_jour").toInt();
            d.mois = interactionQuery.value("date_mois").toInt();
            d.annee = interactionQuery.value("date_annee").toInt();
            interaction.setDate(d);

            // Récupérer les todos associés à cette interaction
            int interactionID = interactionQuery.value("id").toInt();
            QString selectTodosSQL = "SELECT * FROM todo WHERE interaction_id = :interactionID";
            QSqlQuery todoQuery;
            todoQuery.prepare(selectTodosSQL);
            todoQuery.bindValue(":interactionID", interactionID);

            if (!todoQuery.exec()) {
                qDebug() << "Erreur lors de la récupération des todos :" << todoQuery.lastError().text();
                return gestionContact;
            }

            while (todoQuery.next()) {
                Todo todo;
                todo.setContenu(todoQuery.value("contenu").toString().toStdString());
                Date d;
                d.jour = todoQuery.value("date_jour").toInt();
                d.mois = todoQuery.value("date_mois").toInt();
                d.annee = todoQuery.value("date_annee").toInt();
                interaction.setDate(d);
                interaction.ajouteTodo(todo);
            }

            c.ajoutInteraction(interaction);
        }

        gestionContact.addContact(c,false);
    }

    return gestionContact;
}

