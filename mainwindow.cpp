#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int mainx = 500;
    int mainy = 500;
    resize(mainx, mainy);
    int w = 140;
    int h = 100;
    int butx = (mainx - w) / 2;
    int starty = 100;
    int exity = starty + h + 100;
    start = new QPushButton("Start", this);
    start->setGeometry(butx, starty , w, h);
    start->hide();
    exit = new QPushButton("Exit", this);
    exit->setGeometry(butx, exity, w, h);
    exit->hide();

    textwin = new QLabel("you win", this);
    textwin->setGeometry(100, 100, 100, 100);
    textwin->hide();

    textlose = new QLabel("you lose", this);
    textlose->setGeometry(100, 100, 100, 100);
    textlose->hide();

    label = new QLabel(this);
    level = new QPixmap(100, 100);

    StartGame();
}

void MainWindow::StartGame(){
    timer1.stop();
    timer2.stop();
    timer3.stop();
    start->show();
    exit->show();

    count = 1;
    connect(start, SIGNAL(clicked()), start, SLOT(hide()));
    connect(start, SIGNAL(clicked()), exit, SLOT(hide()));
    connect(start, SIGNAL(clicked()), this, SLOT(StartLevel()));
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::StartLevel(){
    int x = 100 + 20 * count;
    int y = 100 + 20 * count;
    int a = 100 / count;   // 100 50 25 12 6
    label->setGeometry(x, y, a, a);
    level->fill(QColor(110, 240, 240));
    label->setPixmap(*level);
    label->show();
    int time1 = 3000 - 500 * count; // 2500 2000 1500 1000 500
    timer1.start(time1);
    connect(&timer1, SIGNAL(timeout()), this, SLOT(GameOver()));
}

void MainWindow::GameOver(){
    label->hide();
    textlose->show();
    timer2.start(700);
    connect(&timer2, SIGNAL(timeout()), textlose, SLOT(hide()));
    connect(&timer2, SIGNAL(timeout()), this, SLOT(StartGame()));
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
        if(ev->button() == Qt::LeftButton){
            timer1.stop();
            label->hide();
            if(count++ < 5){
                StartLevel();
            }else{
                count = 1;
                textwin->show();
                timer3.start(700);
                connect(&timer3, SIGNAL(timeout()), textwin, SLOT(hide()));
                connect(&timer3, SIGNAL(timeout()), this, SLOT(StartGame()));
            }
        }
}

MainWindow::~MainWindow()
{
    delete level;
    delete label;
    delete textwin;
    delete textlose;
    delete exit;
    delete start;
}
