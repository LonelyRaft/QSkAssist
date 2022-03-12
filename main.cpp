
#include <qapplication.h>
#include "mainview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SkMainWindow main;
    main.show();
    return app.exec();
}


