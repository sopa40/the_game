#ifndef REGISTER_H
#define REGISTER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QQmlApplicationEngine>

#include "game.h"
#include "info.h"
#include "websocket_connection.h"

class Registration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString login READ getLogin WRITE setLogin)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword)
    Q_PROPERTY(QString password_rpt READ getPassword_rpt WRITE setPassword_rpt)
    Q_PROPERTY(QString email READ getEmail WRITE setEmail)

public:
    explicit Registration(QObject *parent = nullptr);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    void setPassword_rpt(const QString &password_rpt);
    void setEmail(const QString &email);
    QString getLogin();
    QString getPassword();
    QString getPassword_rpt();
    QString getEmail();
    int verify();

public slots:
    void registerMe();

private:
    QString login_;
    QString password_;
    QString password_rpt_;
    QString email_;
    QQmlApplicationEngine engine_;
    WebSocketManager socketManager_;
};

#endif // REGISTER_H
