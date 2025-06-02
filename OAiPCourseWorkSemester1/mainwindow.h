#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *createLobbyButton;
    QPushButton *connectLobbyButton;

    void resizeEvent(QResizeEvent *event) override;

private slots:
    void SlotClickedButtonCreateLobby();
    void SlotClickedButtonConnectLobby();
    void showMainWindow();
};
#endif // MAINWINDOW_H
