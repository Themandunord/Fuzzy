TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    core/nullexpressionexception.cpp \
    main2.cpp

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
    fuzzy/andmin.h \
    fuzzy/thenmult.h \
    fuzzy/thenmin.h \
    fuzzy/then.h \
    fuzzy/orplus.h \
    fuzzy/andmult.h \
    fuzzy/aggplus.h \
    fuzzy/aggmax.h \
    fuzzy/agg.h \
    core/nullexpressionexception.h \
    fuzzy/isgaussian.h \
    fuzzy/istrapeze.h \
    fuzzy/istrapezeleft.h \
    fuzzy/istrapezeright.h \
    core/shapeview.h \
    fuzzy/isbell.h \
    core/expressionfactory.h \
    fuzzy/fuzzyfactory.h \
    core/unaryshadowexpression.h \
    core/binaryshadowexpression.h \
    fuzzy/mamdanidefuzz.h \
    fuzzy/cogdefuzz.h \
    core/shapebuilder.h \
    core/naryexpression.h \
    fuzzy/sugenodefuzz.h \
    fuzzy/sugenothen.h \
    core/naryshadowexpression.h \
    core/naryexpressionmodel.h \
    fuzzy/sugenoconclusion.h

