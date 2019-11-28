#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
int main(int argc, char *argv[])
{  QApplication a(argc, argv);
  MainWindow w;
  Connexion c;
 try {
      c.ConnectConnexion();
      w.show();}
  catch(QString s){
      qDebug()<<s;
  }

    return a.exec();}
