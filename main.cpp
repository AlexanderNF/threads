#include "thread.h"
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Thread thread(1);
	thread.start();

	app.exec();

	return 0;
}
