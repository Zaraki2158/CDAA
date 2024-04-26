#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sql.cpp"
#include <fstream>

/*!
 * \class MainWindow
 * \brief Classe principale représentant la fenêtre principale de l'application.
 *
 * Cette classe gère les interactions et les opérations sur les contacts et les interactions.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gs = recupererContactsDepuisSQL();
    for (const auto& item : gs.getListe())
    {
        QString s = QString::fromStdString(item.getNom()+" "+item.getPrenom());
        ui->ListeContact->addItem(s);
    }
}


/*!
 * \brief Destructeur de la classe MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief Méthode pour recevoir un nouveau contact et l'ajouter à la liste.
 * \param c Le contact à ajouter.
 */
void MainWindow::RecuContact(Contact c)
{
    gs.addContact(c, true);
    QString s = QString::fromStdString(c.getNom()+" "+c.getPrenom());
    ui->ListeContact->addItem(s);
    ajoutContactSQL(c);
}

/**
 * @brief Supprime un contact de la liste et de la base de données.
 *
 * @param c Contact à supprimer.
 */
void MainWindow::RecuSupr(Contact c)
{
    gs.removeBy_N_And_P(c.getNom(),c.getPrenom());
    QString s = QString::fromStdString(c.getNom()+" "+c.getPrenom());
    for (int i = 0; i < ui->ListeContact->count(); ++i) {
        // Vérifier si le texte de l'élément correspond
        if (ui->ListeContact->itemText(i) == s) {
            // Supprimer l'élément correspondant
            ui->ListeContact->removeItem(i);
            break;  // Sortir de la boucle après la suppression
        }
    }
    SuprContactSQL(c);
}

/**
 * @brief Ajoute une interaction avec un contact dans la liste et la base de données.
 *
 * @param c Contact associé à l'interaction.
 * @param i Interaction à ajouter.
 */
void MainWindow::RecuInteract(Contact c, Interaction i)
{
    gs.addInteraction(c,i);
    ajouterInteractionSQL(i,c);
    for (const auto& item : i.getListe())
    {
        // Ajouter chaque todo dans la base de données
        ajouterTodoSQL(item, c);
    }
}

/**
 * @brief Modifie un contact dans la liste et la base de données.
 *
 * @param c     Contact à modifier.
 * @param modif Nouvelles informations pour le contact.
 */
void MainWindow::RecuModif(Contact c, Contact modif)
{
    gs.modifContact(c.getNom(),modif);
    QString s1 = QString::fromStdString(c.getNom()+" "+c.getPrenom());
    QString s2 = QString::fromStdString(modif.getNom()+" "+modif.getPrenom());
    for (int i = 0; i < ui->ListeContact->count(); ++i) {
        // Vérifier si le texte de l'élément correspond à l'ancien nom
        if (ui->ListeContact->itemText(i) == s1) {
            // Mettre à jour le texte de l'élément avec le nouveau nom
            ui->ListeContact->setItemText(i, s2);
            break;  // Sortir de la boucle après la mise à jour
        }
    }
    ModifContactSQL(c, modif);
}

/**
 * @brief Ferme l'application.
 */
void MainWindow::on_actionQuitter_triggered()
{
    close();
}

/**
 * @brief Ouvre une fenêtre pour ajouter un nouveau contact.
 */
void MainWindow::on_actionAjouter_triggered()
{
    AjouterContact *ajoute = new AjouterContact();
    ajoute->show();
    connect(ajoute, &AjouterContact::EnvoieContact, this, &MainWindow::RecuContact);
}

/**
 * @brief Ouvre une fenêtre pour supprimer un contact.
 */
void MainWindow::on_actionSupprimer_triggered()
{
    Supprimer *Supr = new Supprimer(nullptr,gs);
    connect(Supr, &Supprimer::envoiSupr, this, &MainWindow::RecuSupr);
    Supr->show();
}


/**
 * @brief Ouvre une fenêtre pour modifier un contact.
 */
void MainWindow::on_actionModifier_triggered()
{
    ModifierContact *Modif = new ModifierContact(nullptr,gs);
    connect(Modif, &ModifierContact::envoiModif, this, &MainWindow::RecuModif);
    Modif->show();
}

/**
 * @brief Affiche l'historique des interactions.
 */
void MainWindow::on_actionHistorique_triggered()
{
    QString s = QString::fromStdString(gs.afficheHisto());
    ui->textBrowser->setText(s);
}

/**
 * @brief Affiche la liste des contacts.
 */
void MainWindow::on_actionAfficheContact_triggered()
{
    QString s = QString::fromStdString(gs.afficheListe());
    ui->textBrowser->setText(s);
}

/**
 * @brief Ouvre une fenêtre pour gérer les interactions avec les contacts.
 */
void MainWindow::on_actionInteractions_triggered()
{
    InteractionsTodo *Interact = new InteractionsTodo(nullptr,gs);
    connect(Interact, &InteractionsTodo::EnvoiInteract, this, &MainWindow::RecuInteract);
    Interact->show();
}

/**
 * @brief Met à jour l'affichage lorsqu'un contact est sélectionné dans la liste déroulante.
 *
 * @param arg1 Texte sélectionné dans la liste déroulante.
 */
void MainWindow::on_ListeContact_currentIndexChanged(const QString &arg1)
{
    GestionContact g;
    std::string s = arg1.toStdString();
    size_t pos = s.find(' ');
    std::string Nom = s.substr(0, pos);
    std::string Prenom = s.substr(pos +1);
    std::string img;
    for (const auto& item : gs.getListe())
    {
        if(item.getNom() == Nom &&  item.getPrenom()==Prenom)
        {

            g.addContact(item);
            img = item.getPhoto();
        }
    }
    ui->textBrowser->setText(QString::fromStdString(g.afficheListe()));
    QPixmap imgb(QCoreApplication::applicationDirPath() + "/../ProjetLOGEROT-GIE/img/" +QString::fromStdString(img));
    QPixmap Resizedimgb = imgb.scaledToWidth(250,Qt::SmoothTransformation);
    ui->img->setPixmap(Resizedimgb);
}




/**
 * @brief Trie la liste des contacts par ordre alphabétique croissant.
 */
void MainWindow::on_actionCroissant_triggered()
{
    gs.trierParNomAZ();
}

/**
 * @brief Trie la liste des contacts par ordre alphabétique décroissant.
 */
void MainWindow::on_actionZ_A_triggered()
{
    gs.trierParNomZA();
}

/**
 * @brief Trie la liste des contacts par date la plus récente.
 */
void MainWindow::on_actionR_cent_triggered()
{
    gs.trierParDateRecent();
}

/**
 * @brief Trie la liste des contacts par date la plus ancienne.
 */
void MainWindow::on_actionAncien_triggered()
{
    gs.trierParDateAncien();
}


