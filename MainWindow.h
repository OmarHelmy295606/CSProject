#pragma once
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QString>

class MainWindow : public QMainWindow{
	Q_OBJECT
public:
	explicit MainWindow(const QString& usernmae, QWidget *parent = nullptr);
private slots:
	void onStartGame();
	void onExitGame();

private:
	QString playerName;
	QLabel *welcomeLabel;
	QPushButton *startButton;
	QPushButton *exitButton;


};
