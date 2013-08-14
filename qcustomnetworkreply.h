#ifndef QCUSTOMNETWORKREPLY_H
#define QCUSTOMNETWORKREPLY_H

#include <QNetworkReply>

class QCustomNetworkReply : public QNetworkReply
{
    Q_OBJECT

public:

    QCustomNetworkReply(const QUrl &url);
    ~QCustomNetworkReply();

    void abort();
    qint64 bytesAvailable() const;
    bool isSequential() const;
    qint64 size() const;

protected:
    qint64 read(char *data, qint64 maxSize);
    qint64 readData(char *data, qint64 maxSize);

private:
    struct QCustomNetworkReplyPrivate *reply;
};

#endif // QCUSTOMNETWORKREPLY_H
