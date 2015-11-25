include(../config.pri)

TOP_DIR = ..

VERSION = $$MALIIT_ABI_VERSION
TEMPLATE = lib
msvc | mingw {
    TARGET = ../$$TOP_DIR/lib/maliit-weston-protocols # is one level deeper because of debug/release folder
} else {
    TARGET = $$TOP_DIR/lib/maliit-weston-protocols
}

CONFIG += staticlib

wayland {
    load(wayland-scanner)

    # to force generation of headers.
    SOURCES = dummy.cpp

    WAYLANDCLIENTSOURCES += \
        $$IN_PWD/input-method.xml \
        $$IN_PWD/text.xml
    CONFIG += link_pkgconfig
    PKGCONFIG += wayland-client
}

OTHER_FILES += \
    libmaliit-weston-protocols.pri \
    input-method.xml \
    text.xml
