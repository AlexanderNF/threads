TEMPLATE = app

CONFIG -= debug release
CONFIG += qt debug console

SOURCES = main.cpp \
          thread.cpp \
          threadpool.cpp

HEADERS = thread.h \
          threadpool.h
