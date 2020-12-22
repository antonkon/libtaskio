#ifndef LIBTASKIO_GLOBAL_H
#define LIBTASKIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBTASKIO_LIBRARY)
#  define LIBTASKIO_EXPORT Q_DECL_EXPORT
#else
#  define LIBTASKIO_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBTASKIO_GLOBAL_H
