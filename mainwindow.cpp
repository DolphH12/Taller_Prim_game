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
    muro1 = new pared(20,200,0,20);
    muro2 = new pared(200,20,-100,-350);

    //muro_1.push_back(new pared(w,h,x,y));

    scene->addItem(personaje);
    scene->addItem(muro1);
    scene->addItem(muro2);
}



void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_A){
        personaje->left();
        if(personaje->collidesWithItem(muro1)){
            personaje->right();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->right();
        }
    }
    else if(evento->key() == Qt::Key_D){
        personaje->right();
        if(personaje->collidesWithItem(muro1)){
            personaje->left();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->left();
        }
    }
    else if(evento->key() == Qt::Key_W){
        personaje->up();
        if(personaje->collidesWithItem(muro1)){
            personaje->down();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->down();
        }
    }
    else if(evento->key() == Qt::Key_S){
        personaje->down();
        if(personaje->collidesWithItem(muro1)){
            personaje->up();
        }
        if(personaje->collidesWithItem(muro2)){
            personaje->up();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
