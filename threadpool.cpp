#include "threadpool.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QTextStream>

/*------- ThreadPool ------------------------------------*/
void ThreadPool::start(int threadNumber)
{
	m_threads.resize(threadNumber);

	for (int i = 0; i < threadNumber; i++) {
		m_threads[i] = new Thread(i, this);
		m_threads[i]->start();

		connect(m_threads[i], SIGNAL(started()),
				SLOT(threadStarted()));
		connect(m_threads[i], SIGNAL(finished()),
				SLOT(threadFinished()));
	}
}

void ThreadPool::threadStarted()
{
	Thread *thread = static_cast<Thread *>(sender());

	QTextStream out(stdout);
	out << "Thread No." << thread->id() << " is started." << endl;
}

void ThreadPool::threadFinished()
{
	Thread *thread = static_cast<Thread *>(sender());
	const int threadId = thread->id();

	QTextStream out(stdout);
	out << "Thread No." << threadId << " is finished." << endl;

	if (m_threads[threadId]->isFinished()) {
		m_threads[threadId]->start();
	}
}
