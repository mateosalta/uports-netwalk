QT += qml quick

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

#C++ source files
SOURCES +=  cpp/main.cpp\
    cpp/logic.cpp \
    cpp/cell.cpp

#C++ header files
HEADERS  +=  cpp/logic.h \
    cpp/cell.h

#Path to the libraries...
INCLUDEPATH +=  $$PWD\
                $$PWD/../../../../usr/lib
DEPENDPATH += $$PWD/../../../../usr/lib

#Path to "other files" in this case the QML-Files
OTHER_FILES += \
    qml/*.qml\
    qml/imgs/*\
    qml/components/* \
    qml/components/DropdownMenu.qml \
    qml/components/PinchAndFlick.qml \
    qml/components/GameCell.qml

