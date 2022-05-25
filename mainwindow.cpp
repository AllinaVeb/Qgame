#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainx = 500;
    mainy = 500;
    resize(mainx, mainy);
    int w = 140;
    int h = 100;
    int butx = (mainx - w) / 2;
    int starty = (mainy - 2 * h - 100) / 2;
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

    connect(start, SIGNAL(clicked()), start, SLOT(hide()));
    connect(start, SIGNAL(clicked()), exit, SLOT(hide()));
    connect(start, SIGNAL(clicked()), this, SLOT(StartLevel()));
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(&timer1, SIGNAL(timeout()), this, SLOT(GameOver()));

    StartGame();
}

void MainWindow::StartGame(){
    timer1.stop();
    start->show();
    exit->show();

    count = 1;
}

void MainWindow::StartLevel(){
    a = 100 / count;   // 100 50 25 12 6
 //   labelx = 100 + 20 * count;
    labelx = rand() % (mainx - a);
    labely = rand() % (mainy - a);
    label->setGeometry(labelx, labely, a, a);
    level->fill(QColor(100, 240, 240));
    label->setPixmap(*level);
    label->show();
    int time1 = 3000 - 500 * count; // 2500 2000 1500 1000 500
    timer1.start(time1);
}

void MainWindow::GameOver(){
    label->hide();
    textlose->show();
    timer.singleShot(700, textlose, SLOT(hide()));
    timer.singleShot(700, this, SLOT(StartGame()));
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
        if(ev->button() == Qt::LeftButton){
            label->hide();
            timer1.stop();
            x = ev->x();
            y = ev->y();
            if(x >= labelx  && x <= labelx + a && y >= labely && y <= labely + a){
                if(count++ < 5){
                    StartLevel();
                }else{
                    count = 1;
                    textwin->show();
                    timer.singleShot(700,textwin, SLOT(hide()));
                    timer.singleShot(700,this, SLOT(StartGame()));
                }
            }else{
                GameOver();
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
