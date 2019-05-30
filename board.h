#ifndef BOARD_H
#define BOARD_H
#include <QFrame>
#include <QPointer>
#include <QBasicTimer>
#include "block.h"
#include <QLabel>

class Board : public QFrame
{
private:
    Q_OBJECT
public:
    Board(QWidget* parent = nullptr);

    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void start();
    void pause();

signals:
    void lineRemovedChange(int numerOfLines);
    void scoreChange(int score);
    void speedChange(int speed);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    enum {BoardWidth = 10, BoardHeight = 22};


};

#endif // BOARD_H
