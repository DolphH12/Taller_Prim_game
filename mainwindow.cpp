#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);
    personaje = new cuerpo(25,220,250);
    enemigo = new enemy(25,100,100);
    muro1 = new pared(20,200,0,20);
    muro2 = new pared(200,20,-100,-350);

    //muro_1.push_back(new pared(w,h,x,y));

    monedas.push_back(new moneda(5,190,150));scene->addItem(monedas.back());
    monedas.push_back(new moneda(5,200,300));scene->addItem(monedas.back());

    scene->addItem(personaje);
    scene->addItem(enemigo);
    scene->addItem(muro1);
    scene->addItem(muro2);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(25);
}



void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_A){
        personaje->left();
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(muro1)){
            personaje->right();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->right();
        }
    }
    else if(evento->key() == Qt::Key_D){
        personaje->right();
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(muro1)){
            personaje->left();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->left();
        }
    }
    else if(evento->key() == Qt::Key_W){
        personaje->up();
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(muro1)){
            personaje->down();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->down();
        }
    }
    else if(evento->key() == Qt::Key_S){
        personaje->down();
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(muro1)){
            personaje->up();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->up();
        }
    }
}

QList<moneda *> MainWindow::eliminarMonedas(QList<moneda *> monedas, int pos)
{
    QList<moneda *> aux;
    for (int i = 0;i < monedas.size() ; i++) {
        if(i != pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
}

void MainWindow::moveEnemy()
{
    if(enemigo->x() < personaje->x()){
        enemigo->right();
        if(enemigo->collidesWithItem(muro1)){
            enemigo->left();
        }
        if(enemigo->collidesWithItem(muro2)){
            enemigo->left();
        }
    }
    else if(enemigo->x() > personaje->x()){
        enemigo->left();
        if(enemigo->collidesWithItem(muro1)){
            enemigo->right();
        }
        if(enemigo->collidesWithItem(muro2)){
            enemigo->right();
        }
    }

    if(enemigo->y() < personaje->y()){
        enemigo->down();
        if(enemigo->collidesWithItem(muro1)){
            enemigo->up();
        }
        if(enemigo->collidesWithItem(muro2)){
            enemigo->up();
        }
    }
    else if(enemigo->y() > personaje->y()){
        enemigo->up();
        if(enemigo->collidesWithItem(muro1)){
            enemigo->down();
        }
        if(enemigo->collidesWithItem(muro2)){
            enemigo->down();
        }
    }
    //enemigo->setPos(enemigo->posx,enemigo->posy);

}


MainWindow::~MainWindow()
{
    delete ui;
}




