#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QColor>
#include <QTimer>
#include <QMouseEvent>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int count;

    QPushButton *start;
    QPushButton *exit;

    QLabel *label;
    QString *textlevel;

    QLabel *textlose;
    QLabel *textwin;

    QPixmap *level;

   QTimer timer1;
   QTimer timer2;
   QTimer timer3;

  //QMouseEvent ev;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void StartGame();
    void StartLevel();
    void GameOver();
protected:
   void mousePressEvent(QMouseEvent *ev);
};
#endif // MAINWINDOW_H
