#ifndef THREADS_THREADPOOL_H
#define THREADS_THREADPOOL_H

#include "thread.h"
#include <QtCore/QObject>
#include <QtCore/QVector>

class ThreadPool : public QObject
{
	Q_OBJECT
public:
	void start(int threadNumber);

private slots:
	void threadStarted();
	void threadFinished();

private:
	QVector<Thread *> m_threads;
};

#endif // THREADS_THREADPOOL_H
