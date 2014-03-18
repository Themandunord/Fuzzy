TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    core/expression.h \
    core/valuemodel.h \
    core/unaryexpression.h \
    core/unaryexpressionmodel.h \
    core/binaryexpression.h \
    core/binaryexpressionmodel.h \
    fuzzy/not.h \
    fuzzy/notminus1.h \
    fuzzy/is.h \
    fuzzy/istriangle.h \
    fuzzy/or.h \
    fuzzy/ormax.h \
    fuzzy/and.h \
    fuzzy/andmin.h

