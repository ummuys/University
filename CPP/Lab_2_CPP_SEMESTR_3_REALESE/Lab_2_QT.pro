QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    u_deque/u_deque.cpp \
    u_list/u_list.cpp \
    u_queue/u_queue.cpp \
    u_queue/u_queue_info.cpp \
    u_stack/u_stack.cpp \
    u_stack/u_stack_info.cpp \

HEADERS += \
    mainwindow.h \
    u_BST.h \
    u_conteiner.h \
    u_deque/u_deque.h \
    u_deque_conteiner.h \
    u_list/u_list.h \
    u_list_conteiner.h \
    u_queue.h \
    u_queue/u_queue.h \
    u_queue/u_queue_info.h \
    u_stack.h \
    u_queue_conteiner.h \
    u_stack/u_stack.h \
    u_stack/u_stack_info.h \
    u_stack_conteiner.h \
    u_stack_info.h

FORMS += \
    mainwindow.ui \
    u_deque/u_deque.ui \
    u_list/u_list.ui \
    u_queue/u_queue.ui \
    u_queue/u_queue_info.ui \
    u_stack/u_stack.ui \
    u_stack/u_stack_info.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
