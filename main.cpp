#include "saudio.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon("mstarticons/download.jpg"));

    SAudio w;

    w.show();

    return a.exec();
}
