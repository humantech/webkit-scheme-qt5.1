# A simple webkit content handler for your application

This piece of code was made for Qt 5.1 (as of this day, June 20, 2013, RC1) to provide a custom way of intercept requests from webkit and put whatever you want in the way, without messing up with [QWebView::setHtml](http://qt-project.org/doc/qt-5.0/qtwebkit/qwebview.html#setHtml) or other protocols (schemes).

So, I followed some examples around the internet, but they all failed to be functional under Qt 5.1 (which I'm using to rewrite a software that **needs** to run on Linux, OSX and Windows, 32 **and** 64 bits - as of Qt 5.0, there wasn't any engine that could interpret JavaScript in 64 bit versions of Windows, except for Internet Explorer itself (for god sakes, avoid it at all costs).

Now everything is clear, simple and cross-compatible :)

## Usage

Just compile it using QtCreator and have some fun!

## Thanks to

- The qt-webkit discussion group;
- My patience on reading the Qt 5.1 source code;
- My employers for allowing me to develop this;
- @reyesr for updating me about a bug in the code.

## License

None that I would die for. I just added the beerware license to this repository because you can buy me a beer :)
