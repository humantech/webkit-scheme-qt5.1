#include <QNetworkAccessManager>
#include <QBuffer>
#include <QTimer>
#include <QNetworkRequest>

#include "qcustomnetworkreply.h"

struct QCustomNetworkReplyPrivate
{
    QByteArray data;
    int offset;
};

QCustomNetworkReply::QCustomNetworkReply(const QUrl &url)
    : QNetworkReply()
{
    setFinished(true);
    open(ReadOnly | Unbuffered);

    reply = new QCustomNetworkReplyPrivate;
    reply->offset = 0;

    setUrl(url);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // tudo aqui mesmo? para testes ...

    setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/html; charset=UTF-8"));
    setHeader(QNetworkRequest::ContentLengthHeader, QVariant(reply->data.size()));

    QTimer::singleShot(0, this, SIGNAL(metaDataChanged()));

    setAttribute(QNetworkRequest::HttpStatusCodeAttribute, 200);
    setAttribute(QNetworkRequest::HttpReasonPhraseAttribute, "OK");
    QString hasQuery = url.hasQuery() ? QString("yes") : QString("no");
    reply->data = QString("<html><body>"
                      "<h1>This is not the coolest title</h1>"
                      "<p>You shall not pass!</p>"
                      "<ul>"
                      "<li>Has query? " + hasQuery + "</li>"
                      "<li>Host: " + url.host() + "</li>"
                      "<li>Path: " + url.path() + "</li>"
                      "<li>Url: " + url.url() + "</li>"
                      "<li>Top level domain: " + url.topLevelDomain() + "</li>"
                      "<li>Scheme: " + url.scheme() + "</li>"
                      "</ul>"
                      "<img src=\"http://ih1.redbubble.net/image.11911585.8363/sticker,375x360.u1.png\" />"
                      "</body></html>").toUtf8();

    QTimer::singleShot(0, this, SIGNAL(readyRead()));
    QTimer::singleShot(0, this, SIGNAL(finished()));

}

QCustomNetworkReply::~QCustomNetworkReply()
{
    delete reply;
}

qint64 QCustomNetworkReply::size() const
{
    return reply->data.size();
}

void QCustomNetworkReply::abort()
{
    // !!! no need to implement code here, but must be declared !!!
}

qint64 QCustomNetworkReply::bytesAvailable() const
{
    return size();
}

bool QCustomNetworkReply::isSequential() const
{
    return true;
}

qint64 QCustomNetworkReply::read(char *data, qint64 maxSize)
{
    return readData(data, maxSize);
}

qint64 QCustomNetworkReply::readData(char *data, qint64 maxSize)
{
    if (reply->offset >= reply->data.size())
    {
        return -1;
    }

    qint64 number = qMin(maxSize, (qint64) reply->data.size() - reply->offset);
    memcpy(data, reply->data.constData() + reply->offset, number);
    reply->offset += number;
    return number;
}
