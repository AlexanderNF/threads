#include "thread.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDateTime>
#include <QtCore/QTextStream>

/*------- Thread ----------------------------------------*/
Thread::Thread(int id, QObject *parent)
	: QThread(parent)
{
	m_id = id;
}

void Thread::run()
{
	qsrand(QDateTime::currentMSecsSinceEpoch() / 1000 + m_id);
	int pauseDuration = qrand() % 100;

	sleep(pauseDuration);
}

int Thread::id() const
{
	return m_id;
}
