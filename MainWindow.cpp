#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>

MainWindow::MainWindow(const QString &username, QWidget *parent)
        : QMainWindow(parent), playerName(username)
{
        setWindowTitle("Scavenger Hunt");
        setFixedSize(800, 600);

        QWidget *central = new QWidget(this);
        setCentralWidget(central);

        central->setStyleSheet(
        "QWidget {"
        "   background-color: #0B1220;"
        "   color: white;"
        "}"
        );

        QVBoxLayout *mainLayout = new QVBoxLayout(central);
        mainLayout->setContentsMargins(60, 40, 60, 40);
        mainLayout->setSpacing(20);
        mainLayout->setAlignment(Qt::AlignCenter);

        QFrame *card = new QFrame();
        card->setFixedWidth(500);

        card->setStyleSheet(
        "QFrame {"
        "   background-color: #111827;"
        "   border-radius: 24px;"
        "   border: 1px solid #1F2937;"
        "}"
        );

        QVBoxLayout *cardLayout = new QVBoxLayout(card);
        cardLayout->setContentsMargins(40, 40, 40, 40);
        cardLayout->setSpacing(24);

        QLabel *titleLabel = new QLabel("🌊 Scavenger Hunt");
        titleLabel->setAlignment(Qt::AlignCenter);

        titleLabel->setStyleSheet(
        "font-size: 32px;"
        "font-weight: 700;"
        "color: white;"
        );

        welcomeLabel = new QLabel(
                "Welcome back, <b>" + playerName + "</b><br>"
                "<span style='color:#9CA3AF;'>Ready to explore the depths?</span>"
        );

        welcomeLabel->setAlignment(Qt::AlignCenter);

        welcomeLabel->setStyleSheet(
        "font-size: 18px;"
        "line-height: 1.6;"
        "color: #E5E7EB;"
        );

	easyButton   = new QPushButton("🟢 Easy");
	mediumButton = new QPushButton("🟡 Medium");
	hardButton   = new QPushButton("🔴 Hard");
        exitButton  = new QPushButton("Exit");

        QString levelStyle =
		"QPushButton {"
		"   background-color: #2563EB;"
		"   color: white;"
		"   border: none;"
		"   border-radius: 14px;"
		"   font-size: 15px;"
		"   font-weight: 600;"
		"   padding: 14px;"
		"}"
		"QPushButton:hover {"
		"   background-color: #3B82F6;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #1D4ED8;"
		"}";

	easyButton->setStyleSheet(levelStyle);
	mediumButton->setStyleSheet(levelStyle);
	hardButton->setStyleSheet(levelStyle);

	easyButton->setFixedHeight(50);
	mediumButton->setFixedHeight(50);
	hardButton->setFixedHeight(50);

	easyButton->setCursor(Qt::PointingHandCursor);
	mediumButton->setCursor(Qt::PointingHandCursor);
	hardButton->setCursor(Qt::PointingHandCursor);

        exitButton->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   color: #9CA3AF;"
        "   border: 1px solid #374151;"
        "   border-radius: 14px;"
        "   font-size: 15px;"
        "   padding: 10px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #1F2937;"
        "   color: white;"
        "}"
        );

        cardLayout->addWidget(titleLabel);
        cardLayout->addWidget(welcomeLabel);
        cardLayout->addSpacing(10);
	cardLayout->addWidget(easyButton);
	cardLayout->addWidget(mediumButton);
	cardLayout->addWidget(hardButton);
        cardLayout->addWidget(exitButton);

        mainLayout->addWidget(card);

	connect(easyButton, &QPushButton::clicked,
        	this, &MainWindow::startEasy);

	connect(mediumButton, &QPushButton::clicked,
        	this, &MainWindow::startMedium);

	connect(hardButton, &QPushButton::clicked,
        	this, &MainWindow::startHard);

        connect(exitButton, &QPushButton::clicked,
                this, &MainWindow::onExitGame);
}

void MainWindow::startEasy() {
        gameWidget = new GameWidget(playerName, 2400, 1600, this);
        setCentralWidget(gameWidget);
        gameWidget->setFocus();
}

void MainWindow::startMedium() {
        gameWidget = new GameWidget(playerName, 3200, 2200, this);
        setCentralWidget(gameWidget);
        gameWidget->setFocus();
}

void MainWindow::startHard() {
        gameWidget = new GameWidget(playerName, 4200, 3000, this);
        setCentralWidget(gameWidget);
        gameWidget->setFocus();
}
void MainWindow::onExitGame() {
        close();
}
