#include "LoginWindow.h"
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QString>
LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent){
	setWindowTitle("Scavenger Hunt - Login");
	setFixedSize(420, 360);

	setStyleSheet("QWidget { background-color: #F7F7F8; }");

	titleLabel = new QLabel("🎯 Scavenger Hunt");
	usernameInput = new QLineEdit();

	loginButton = new QPushButton("Start Game");
	errorLabel    = new QLabel("");

	titleLabel->setAlignment(Qt::AlignCenter);
	titleLabel->setStyleSheet("font-size: 20px; font-weight: 600; color: #111111;"
        "border: none; background: transparent;");

	usernameInput->setPlaceholderText("Username");
	usernameInput->setFixedHeight(42);
	usernameInput->setFixedWidth(276);
	usernameInput->setStyleSheet(
        "QLineEdit {"
        "  border: 1px solid #DDDDDD;"
        "  border-radius: 8px;"
        "  padding: 0 12px;"
        "  font-size: 14px;"
        "  color: #111111;"
        "  background-color: #FAFAFA;"
        "}"
        "QLineEdit:focus {"
        "  border: 1px solid #111111;"
        "  background-color: #FFFFFF;"
        "}"
    );

	loginButton->setStyleSheet("padding: 8px; font-size: 14px;");
	loginButton->setCursor(Qt::PointingHandCursor);
	loginButton->setFixedHeight(42);
	loginButton->setFixedWidth(276);
	loginButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #111111;"
        "  color: #FFFFFF;"
        "  border-radius: 8px;"
        "  font-size: 14px;"
        "  font-weight: 500;"
        "}"
        "QPushButton:hover {"
        "  background-color: #333333;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #000000;"
        "}"
    );


	errorLabel->setStyleSheet("color: red;");
	errorLabel->setAlignment(Qt::AlignCenter);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setContentsMargins(40, 30, 40, 30);
	layout->setSpacing(12);
	layout->addWidget(titleLabel);
	layout->addWidget(usernameInput);
	layout->addWidget(loginButton);
	layout->addWidget(errorLabel);

	connect(usernameInput, &QLineEdit::returnPressed,this, &LoginWindow::onLoginClicked);
	connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
}

void LoginWindow::onLoginClicked(){
	QString user = usernameInput->text().trimmed();
	if(user.isEmpty()){
		errorLabel->setText("Please enter your username.");
		return;
	}
	MainWindow *main = new MainWindow(user);
	main->show();
	this->close();


}
