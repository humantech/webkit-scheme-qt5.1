#include "customwebview.h"
#include "qcustomnetworkaccessmanager.h"

CustomWebView::CustomWebView()
{
    QNetworkAccessManager *oldManager = page()->networkAccessManager();
    QCustomNetworkAccessManager *newManager = new QCustomNetworkAccessManager(oldManager, this);

    settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    page()->setNetworkAccessManager(newManager);
    page()->setForwardUnsupportedContent(true);

    connect(this, SIGNAL(urlChanged(const QUrl &)),
            this, SLOT(updateWindowTitle(const QUrl &)));
}

void CustomWebView::updateWindowTitle(const QUrl &url)
{
    setWindowTitle(tr("You're accessing - %1").arg(url.toString()));
}
