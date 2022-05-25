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
    int labelx, labely, a, x, y;
    int mainx, mainy;

    QPushButton *start;
    QPushButton *exit;

    QLabel *label;
    QString *textlevel;

    QLabel *textlose;
    QLabel *textwin;

    QPixmap *level;

   QTimer timer;
   QTimer timer1;

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
