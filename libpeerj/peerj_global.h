#ifndef PEERJ_GLOBAL_H
#define PEERJ_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PEERJ_LIBRARY)
#  define PEERJSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PEERJSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PEERJ_GLOBAL_H
