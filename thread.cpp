#include "thread.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDateTime>
#include <QtCore/QTextStream>

/*------- Thread class ----------------------------------*/
Thread::Thread(int id, QObject *parent)
	: QThread(parent)
{
	m_id = id;
}

void Thread::run()
{
	qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
	int pauseDuration = qrand() % 5;

	sleep(pauseDuration);

	QTextStream out(stdout);
	out << "Thread No." << m_id << ". HANDLER is " << currentThreadId();

	QCoreApplication::processEvents();

	// sleep(1000000);
}
