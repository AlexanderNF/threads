#include "threadpool.h"
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	ThreadPool threads;
	threads.start(100);

	app.exec();

	return 0;
}
