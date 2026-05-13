#include "LoginWindow.h"
#include "MainWindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QString>

LoginWindow::LoginWindow(QWidget *parent)
        : QWidget(parent)
{
        setWindowTitle("Scavenger Hunt - Login");
        setFixedSize(500, 520);

        setStyleSheet(
        "QWidget {"
        "   background-color: #0B1220;"
        "   color: white;"
        "}"
        );

        QVBoxLayout *rootLayout = new QVBoxLayout(this);
        rootLayout->setAlignment(Qt::AlignCenter);
        rootLayout->setContentsMargins(40, 40, 40, 40);

        QFrame *card = new QFrame();
        card->setFixedWidth(380);

        card->setStyleSheet(
        "QFrame {"
        "   background-color: #111827;"
        "   border-radius: 24px;"
        "   border: 1px solid #1F2937;"
        "}"
        );

        QVBoxLayout *layout = new QVBoxLayout(card);
        layout->setContentsMargins(36, 40, 36, 40);
        layout->setSpacing(18);

        QLabel *iconLabel = new QLabel("🌊");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setStyleSheet(
        "font-size: 54px;"
        "border: none;"
        );

        titleLabel = new QLabel("Scavenger Hunt");
        titleLabel->setAlignment(Qt::AlignCenter);

        titleLabel->setStyleSheet(
        "font-size: 28px;"
        "font-weight: 700;"
        "color: white;"
        "border: none;"
        );

        QLabel *subtitle = new QLabel(
                "Dive and uncover lost treasures."
        );

        subtitle->setAlignment(Qt::AlignCenter);

        subtitle->setStyleSheet(
        "font-size: 14px;"
        "color: #9CA3AF;"
        "border: none;"
        );

        usernameInput = new QLineEdit();
        usernameInput->setPlaceholderText("Enter your username");

        usernameInput->setFixedHeight(50);

        usernameInput->setStyleSheet(
        "QLineEdit {"
        "   background-color: #1F2937;"
        "   border: 2px solid transparent;"
        "   border-radius: 14px;"
        "   padding: 0 16px;"
        "   font-size: 15px;"
        "   color: white;"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #2563EB;"
        "   background-color: #111827;"
        "}"
        );

        loginButton = new QPushButton("▶ Start Adventure");

        loginButton->setCursor(Qt::PointingHandCursor);
        loginButton->setFixedHeight(50);

        loginButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #2563EB;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 14px;"
        "   font-size: 15px;"
        "   font-weight: 600;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3B82F6;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1D4ED8;"
        "}"
        );

        errorLabel = new QLabel("");
        errorLabel->setAlignment(Qt::AlignCenter);

        errorLabel->setStyleSheet(
        "color: #EF4444;"
        "font-size: 13px;"
        "border: none;"
        );

        layout->addWidget(iconLabel);
        layout->addWidget(titleLabel);
        layout->addWidget(subtitle);
        layout->addSpacing(10);
        layout->addWidget(usernameInput);
        layout->addWidget(loginButton);
        layout->addWidget(errorLabel);

        rootLayout->addWidget(card);

        connect(usernameInput, &QLineEdit::returnPressed,
                this, &LoginWindow::onLoginClicked);

        connect(loginButton, &QPushButton::clicked,
                this, &LoginWindow::onLoginClicked);
}

void LoginWindow::onLoginClicked() {
        QString user = usernameInput->text().trimmed();

        if(user.isEmpty()) {
                errorLabel->setText("Please enter your username.");
                return;
        }

        MainWindow *main = new MainWindow(user);
        main->show();

        close();
}
