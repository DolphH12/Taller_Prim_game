#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cuerpo.h"
#include "enemy.h"
#include "pared.h"
#include "moneda.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<moneda *> monedas;

public slots:
    void moveEnemy();

private:
    Ui::MainWindow *ui;
    cuerpo *personaje;
    enemy *enemigo;
    pared *muro1;
    pared *muro2;
    QGraphicsScene *scene;
    void keyPressEvent(QKeyEvent * evento);
    QTimer *timer;
    QList<moneda *> eliminarMonedas(QList<moneda *> monedas,int pos);

};
#endif // MAINWINDOW_H
