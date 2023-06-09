#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onExitClicked();
    void onAboutClicked();
    void onNewGameClicked();
    void onCellClicked();
    void onEndGame(const QString& message);

signals:
    void endOfTurn(const QString& message);
    void invalidMove(const QString& message);
    void playerWon(const QString& message);

private:
    // Returns 0 if the cell is empty, 1 if it contains X, -1 otherwise
    int getState(unsigned int row, unsigned int col) const;
    // Returns the row [0-2] of the cell represented by QPushButton b
    int getRow(QPushButton* b) const;
    // Returns the column [0-2] of the cell represented by QPushButton b
    int getCol(QPushButton* b) const;
    // Check winning conditions
    bool checkIfPlayerWon() const;

    QString m_player{"O"};
    QPushButton *m_cells[3][3];
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
