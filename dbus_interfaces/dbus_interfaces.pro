TOP_DIR = ..

include($$TOP_DIR/config.pri)

TEMPLATE = lib
CONFIG += plugin
TARGET = dummy

msvc{
    QMAKE_LFLAGS += /NOENTRY #msvc defaults to main entry, but this lib doesn't have one
}

OTHER_FILES += \
    minputmethodcontext1interface.xml \
    minputmethodserver1interface.xml
