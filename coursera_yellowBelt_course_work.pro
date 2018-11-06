TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    condition_parser_test.cpp \
    condition_parser.cpp \
    token.cpp \
    date.cpp \
    node.cpp \
    database.cpp \
    datecomparisonnode.cpp \
    eventcomparisonnode.cpp \
    logicaloperationnode.cpp \
    emptynode.cpp

HEADERS += \
    condition_parser.h \
    token.h \
    date.h \
    node.h \
    database.h \
    test_runner.h \
    comparison.h \
    datecomparisonnode.h \
    eventcomparisonnode.h \
    logicaloperation.h \
    logicaloperationnode.h \
    emptynode.h
