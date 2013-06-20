#include <QtWidgets/QApplication>
#include <QWebView>

#include "customwebview.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    CustomWebView view;
    view.setUrl(QUrl("foo://bar.com/hello?world"));
    view.show();

    return app.exec();
}

