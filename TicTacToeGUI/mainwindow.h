#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_button00_clicked();
    void on_button01_clicked();
    void on_button02_clicked();
    void on_button10_clicked();
    void on_button11_clicked();
    void on_button12_clicked();
    void on_button20_clicked();
    void on_button21_clicked();
    void on_button22_clicked();
    void on_buttonRetry_clicked();


    void playGame(int buttonX, int buttonY);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
