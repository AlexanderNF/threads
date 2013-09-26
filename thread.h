#ifndef THREADS_THREAD_H
#define THREADS_THREAD_H

#include <QtCore/QThread>

class Thread : public QThread
{
	Q_OBJECT
public:
	Thread(int id, QObject *parent = 0);

	int id() const;

signals:
	void postInfo(const QString &text);

private:
	int m_id;

	void run();
};


#endif // THREADS_THREAD_H
