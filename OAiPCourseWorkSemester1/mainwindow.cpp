#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylayout.h"
#include "mainplayer.h"
#include "clientplayer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createLobbyButton = new QPushButton(this);
    createLobbyButton->move(350, 300);
    createLobbyButton->setText("Создать лобби");
    connect(createLobbyButton, &QPushButton::clicked, this, &MainWindow::SlotClickedButtonCreateLobby);

    connectLobbyButton = new QPushButton(this);
    connectLobbyButton->move(350, 350);
    connectLobbyButton->setText("Подключится");
    connect(connectLobbyButton, &QPushButton::clicked, this, &MainWindow::SlotClickedButtonConnectLobby);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    MyLayout::Layout_45_110(createLobbyButton,  event->size(), QPointF(350, 300));
    MyLayout::Layout_45_110(connectLobbyButton, event->size(), QPointF(350, 350));
}

void MainWindow::SlotClickedButtonCreateLobby() {
    this->hide();
    MainPlayer *player = new MainPlayer(this);
    player->show();
    connect(player, &MainPlayer::rejected, this, &MainWindow::showMainWindow);
}

void MainWindow::SlotClickedButtonConnectLobby() {
    this->hide();
    ClientPlayer *player = new ClientPlayer(this);
    connect(player, &MainPlayer::rejected, this, &MainWindow::showMainWindow);
    player->show();
}

void MainWindow::showMainWindow() {
    this->show();
}
