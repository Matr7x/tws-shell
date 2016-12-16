#ifndef LITE_LOG_PRINTER_H_
#define LITE_LOG_PRINTER_H_

#include <pthread.h>
#include <cstdio>
#include <cstring>

#define LOG_DEBUG(_fmt_, args...) \
    { fprintf(stdout, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#define LOG_INFO(_fmt_, args...) \
    { fprintf(stdout, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#define LOG_NOTICE(_fmt_, args...) \
    { fprintf(stdout, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#define LOG_WARN(_fmt_, args...) \
    { fprintf(stdout, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#define LOG_ERROR(_fmt_, args...) \
    { fprintf(stderr, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#define LOG_CRIT(_fmt_, args...) \
    { fprintf(stderr, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#define LOG_FATAL(_fmt_, args...) \
    { fprintf(stderr, " [%s:%s:%d][%lu] \n" _fmt_, __FILE__, __FUNCTION__, __LINE__, (unsigned long)pthread_self(), ##args); }

#endif//LITE_LOG_PRINTER_H_
