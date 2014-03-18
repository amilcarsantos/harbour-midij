# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = harbour-midij

CONFIG += sailfishapp

QT += widgets \
	xml

HEADERS += src/Utils.h \
	src/gui/GuiUtils.h \
	src/gui/MidiMappingGui.h \
    src/gui/GraphicsMidiControlItem.h \
	src/gui/GraphicsMidiInputItem.h \
    src/gui/GraphicsMidiOutputItem.h \
    src/gui/GraphicsMidiMultiItem.h \
    src/gui/MidiSysexAction.h \
    src/gui/MidiSysexProperties.h \
	src/mixxx/MidiMessage.h

SOURCES += src/harbour-midij.cpp \
    src/midicontroller.cpp \
	src/gui/MidiMappingGui.cpp \
    src/gui/GraphicsMidiControlItem.cpp \
    src/gui/GraphicsMidiInputItem.cpp \
    src/gui/GraphicsMidiOutputItem.cpp \
    src/gui/GraphicsMidiMultiItem.cpp \
    src/gui/MidiSysexAction.cpp \
    src/gui/MidiSysexProperties.cpp \
	src/mixxx/MidiMessage.cpp


OTHER_FILES += qml/harbour-midij.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/harbour-midij.spec \
    rpm/harbour-midij.yaml \
    harbour-midij.desktop

HEADERS += \
    src/midicontroller.h

