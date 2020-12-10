TEMPLATE = app
QT += widgets

SOURCES += src/tools.cpp \
           src/number.cpp \
           src/convert_fast.cpp \
           src/convert_substitution.cpp \
           src/convert_successive_division.cpp \
           src/convert.cpp \
           src/program.cpp \
           src/ui/main_window.cpp \
           src/ui/add_dialog.cpp \
           src/ui/subtract_dialog.cpp \
           src/ui/multiply_dialog.cpp \
           src/ui/divide_dialog.cpp

HEADERS += src/tools.hpp \
           src/number.hpp \
           src/convert.hpp \
           src/ui/main_window.hpp \
           src/ui/add_dialog.hpp \
           src/ui/subtract_dialog.hpp \
           src/ui/multiply_dialog.hpp \
           src/ui/divide_dialog.hpp
