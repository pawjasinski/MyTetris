#include "tetrixwindow.h"
#include "ui_tetrixwindow.h"
#include <QtWidgets>
#include "board.h"

TetrixWindow::TetrixWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TetrixWindow)
{
    ui->setupUi(this);
    board = new Board;

    nextBlockLabel = new QLabel;
    nextBlockLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextBlockLabel->setAlignment(Qt::AlignCenter);
}

TetrixWindow::~TetrixWindow()
{
    delete ui;
}
