#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"
#include "para.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString reference= ui->lineEdit_reference->text();
  Medicament m(id,nom,reference);
  bool test=m.ajouter();
  if(test)
{ui->tabmedicament->setModel(tmpmedicament.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un medicament"),
                  QObject::tr("Medicament ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un medicament"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    Medicament m;
    if(m.rech(ui->lineEdit->text().toInt())){
        bool test=tmpmedicament.supprimer(ui->lineEdit->text().toInt());
        if(test){
            ui->tabmedicament->setModel(tmpmedicament.afficher());
            QMessageBox::critical(nullptr,QObject::tr("Medicament supprimé"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
        QString reference = ui->lineEdit_reference_2->text();
        QString nom = ui->lineEdit_nom_2->text();
        Medicament m;
        if(m.rech(id)){
            bool test = m.modifier(id,nom,reference);
            if(test){
                ui->tabmedicament->setModel(tmpmedicament.afficher());
                QMessageBox::information(nullptr,QObject::tr("Medicament modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            }
        }
}

void MainWindow::on_Ajout_clicked()
{
    int Serial = ui->lineEdit_Serial->text().toInt();
    QString Ref= ui->lineEdit_Ref->text();
    QString Type= ui->lineEdit_Type->text();
  Para p(Serial,Ref,Type);
  bool test=p.ajouter_para();
  if(test)
{ui->tabpara->setModel(tmppara.afficher_para());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un para"),
                  QObject::tr("Para ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un para"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Modif_para_clicked()
{
    int Serial = ui->lineEdit_Serial_2->text().toInt();
        QString Ref = ui->lineEdit_Ref_2->text();
        QString Type = ui->lineEdit_Name_2->text();
        Para p;
        if(p.rech_para(Serial)){
            bool test = p.modifier_para(Serial,Ref,Type);
            if(test){
                ui->tabpara->setModel(tmppara.afficher_para());
                QMessageBox::information(nullptr,QObject::tr("Para modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            }
        }

}

void MainWindow::on_Supp_para_clicked()
{

    Para p;
    if(p.rech_para(ui->lineEdit_Ser->text().toInt())){
        bool test=tmppara.supprimer_para(ui->lineEdit_Ser->text().toInt());
        if(test){
            ui->tabpara->setModel(tmppara.afficher_para());
            QMessageBox::critical(nullptr,QObject::tr("Para supprimé"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{

    Medicament m;
    ui->tabmedicament->setModel(tmpmedicament.trier());
}

void MainWindow::on_pushButton_4_clicked()
{
    Para p;
    ui->tabpara->setModel(tmppara.trier());
}

void MainWindow::on_pushButton_7_clicked()
{
    Medicament m;
    int id=ui->lineEdit_3->text().toInt();
    ui->tabmedicament->setModel(m.rechercher(id));
}

void MainWindow::on_pushButton_6_clicked()
{
    Para p;
    int Serial=ui->lineEdit_2->text().toInt();
    ui->tabpara->setModel(p.rechercher(Serial));
}


