#ifndef QCUSTOMNETWORKACCESSMANAGER_H
#define QCUSTOMNETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>

class QCustomNetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    explicit QCustomNetworkAccessManager(QNetworkAccessManager *oldManager, QObject *parent = 0);

public slots:
    void customReplyFinished();

protected:
    QNetworkReply *createRequest( Operation operation,
                                  const QNetworkRequest &request,
                                  QIODevice *device );
};

#endif // QCUSTOMNETWORKACCESSMANAGER_H
