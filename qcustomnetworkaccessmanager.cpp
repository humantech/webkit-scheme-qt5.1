#include <QNetworkRequest>
#include <QDebug>

#include "qcustomnetworkreply.h"
#include "qcustomnetworkaccessmanager.h"

QCustomNetworkAccessManager::QCustomNetworkAccessManager(QNetworkAccessManager *manager, QObject *parent)
    : QNetworkAccessManager( parent )
{
    setCache(manager->cache());
    setCookieJar(manager->cookieJar());
    setProxyFactory(manager->proxyFactory());
}

QNetworkReply *QCustomNetworkAccessManager::createRequest( Operation operation,
                                                             const QNetworkRequest &request,
                                                             QIODevice *device )
{
    if (request.url().scheme() != "foo")
    {
        return QNetworkAccessManager::createRequest( operation, request, device );
    }

    QCustomNetworkReply *reply =  new QCustomNetworkReply(request.url());
    connect(reply, SIGNAL(finished()), this, SLOT(customReplyFinished()));
    return reply;
}

void QCustomNetworkAccessManager::customReplyFinished()
{
    QCustomNetworkReply *reply = qobject_cast<QCustomNetworkReply *>(sender());
    if (reply) {
        emit finished(reply);
    }
}
