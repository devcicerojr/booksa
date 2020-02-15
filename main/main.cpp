#include <iostream>
#include <qapplication.h>
#include <qmainwindow.h>

using namespace std;

const int DEFAULT_WIDTH = 1080;
const int DEFAULT_HEIGHT = 720;

int main( int argc, char **argv )
{
  (void) argc;
  (void) argv;

  QApplication app( argc, argv );
  QMainWindow window;
  window.setWindowTitle( QString( "BookSA APP" ) );
  window.resize( DEFAULT_WIDTH , DEFAULT_HEIGHT );
  window.show();
  return app.exec();
}
