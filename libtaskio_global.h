#ifndef TASKIO_GLOBAL_H
#define TASKIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBTASKIO_LIBRARY)
#  define TASKIO_EXPORT Q_DECL_EXPORT
#else
#  define TASKIO_EXPORT Q_DECL_IMPORT
#endif

#endif // TASKIO_GLOBAL_H
