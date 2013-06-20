#ifndef CUSTOMWEBVIEW_H
#define CUSTOMWEBVIEW_H

#include <QWebView>

class QNetworkAccessManager;


class CustomWebView : public QWebView
{
    Q_OBJECT

public:
    CustomWebView();

private slots:
    void updateWindowTitle(const QUrl &url);
};

#endif // CUSTOMWEBVIEW_H
