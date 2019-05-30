#ifndef TETRIXWINDOW_H
#define TETRIXWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class TetrixWindow;
}

class Board;

class TetrixWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TetrixWindow(QWidget *parent = nullptr);
    ~TetrixWindow();

private:
    Ui::TetrixWindow *ui;
    QLabel *createLabel(const QString& text);
    Board *board;
    QLabel *nextBlockLabel;
    QLCDNumber *scoreLCD;
    QLCDNumber *levelLCD;
    QLCDNumber *linesLCD;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};

#endif // TETRIXWINDOW_H
