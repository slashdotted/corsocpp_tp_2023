#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui{new Ui::MainWindow}
{
    ui->setupUi(this);

    m_cells[0][0] = ui->cell00;
    m_cells[0][1] = ui->cell01;
    m_cells[0][2] = ui->cell02;
    m_cells[1][0] = ui->cell10;
    m_cells[1][1] = ui->cell11;
    m_cells[1][2] = ui->cell12;
    m_cells[2][0] = ui->cell20;
    m_cells[2][1] = ui->cell21;
    m_cells[2][2] = ui->cell22;

    for(auto row{0}; row<3; ++row) {
        for(auto col{0}; col<3; ++col) {
            connect(m_cells[row][col], SIGNAL(clicked(bool)), this, SLOT(onCellClicked()));
        }
    }

    connect(ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(onExitClicked()));
    connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(onAboutClicked()));
    connect(ui->actionNew_game,SIGNAL(triggered(bool)),this,SLOT(onNewGameClicked()));
    connect(this,SIGNAL(invalidMove(QString)),ui->statusbar,SLOT(showMessage(QString)));
    connect(this,SIGNAL(endOfTurn(QString)),ui->statusbar,SLOT(showMessage(QString)));
    connect(this,SIGNAL(playerWon(QString)),ui->statusbar,SLOT(showMessage(QString)));
    connect(this,SIGNAL(playerWon(QString)),this,SLOT(onEndGame(QString)));

    //ui->statusbar->showMessage("Player " + m_player + " starts!");
    emit endOfTurn("Player " + m_player + " starts!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onExitClicked()
{
    qDebug() << "Exit clicked";
    close();
}

void MainWindow::onAboutClicked()
{
    qDebug() << "About clicked";
    QMessageBox::information(this,"About TicTacToe","Proudly provided by SUPSI",QMessageBox::Ok);
}

void MainWindow::onNewGameClicked()
{
    for(auto row{0}; row<3; ++row) {
        for(auto col{0}; col<3; ++col) {
            m_cells[row][col]->setEnabled(true);
            m_cells[row][col]->setText("");
        }
    }
    emit endOfTurn("Player " + m_player + " starts!");
}

void MainWindow::onCellClicked()
{
    QPushButton* source{dynamic_cast<QPushButton*>(sender())};
    if (source) {
         auto column = getCol(source);
         auto row = getRow(source);
         auto state = getState(row, column);
         if (!state) {
            source->setText(m_player);
            if (checkIfPlayerWon()) {
                emit playerWon("Player " + m_player + " has won");
            } else {
                m_player = m_player == "O" ? "X" : "O";
                emit endOfTurn("It's player " + m_player + " turn");
            }
         } else {
            emit invalidMove("Cell is not empty!");
         }
    }

}

void MainWindow::onEndGame(const QString &message)
{
    for(auto row{0}; row<3; ++row) {
        for(auto col{0}; col<3; ++col) {
            m_cells[row][col]->setEnabled(false);
        }
    }
    qDebug() << message;
}

// Returns 0 if the cell is empty, 1 if it contains X, -1 otherwise
int MainWindow::getState(unsigned int row, unsigned int col) const
{
    auto label{m_cells[row][col]->text()};
    if (label == "O") {
        return -1;
    } else if (label == "X") {
        return 1;
    } else {
        return 0;
    }
}

// Returns the row [0-2] of the cell represented by QPushButton b
int MainWindow::getRow(QPushButton *b) const
{
    for(auto row{0}; row<3; ++row) {
        for(auto col{0}; col<3; ++col) {
            if (m_cells[row][col] == b) {
                return row;
            }
        }
    }
    return -1;
}

// Returns the column [0-2] of the cell represented by QPushButton b
int MainWindow::getCol(QPushButton *b) const
{
    for(auto row{0}; row<3; ++row) {
        for(auto col{0}; col<3; ++col) {
            if (m_cells[row][col] == b) {
                return col;
            }
        }
    }
    return -1;
}

// https://pastebin.com/VJAbqf4e
bool MainWindow::checkIfPlayerWon() const
{
    return (getState(0,0)==getState(0,1)&&getState(0,1)==getState(0,2)&&getState(0,2)!=0
    ||getState(1,0)==getState(1,1)&&getState(1,1)==getState(1,2)&&getState(1,2)!=0
    ||getState(2,0)==getState(2,1)&&getState(2,1)==getState(2,2)&&getState(2,2)!=0
    ||getState(0,0)==getState(1,0)&&getState(1,0)==getState(2,0)&&getState(2,0)!=0
    ||getState(0,1)==getState(1,1)&&getState(1,1)==getState(2,1)&&getState(2,1)!=0
    ||getState(0,2)==getState(1,2)&&getState(1,2)==getState(2,2)&&getState(2,2)!=0
    ||getState(0,0)==getState(1,1)&&getState(1,1)==getState(2,2)&&getState(2,2)!=0
    ||getState(2,0)==getState(1,1)&&getState(1,1)==getState(0,2)&&getState(0,2)!=0);
}

