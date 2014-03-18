#ifndef MIDICONTROLLER_H
#define MIDICONTROLLER_H

#include <QQuickPaintedItem>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsTextItem>

#include "gui/MidiMappingGui.h"

class MidiController : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(QString schemeFile READ schemeFile() WRITE setSchemeFile(QString) NOTIFY schemeFileChanged())
public:
	explicit MidiController(QQuickItem *parent = 0);
	virtual ~MidiController();

	virtual void paint(QPainter *painter);

	// property accessors
	QString schemeFile() const;
	void setSchemeFile(QString schemeFile);

signals:
	void schemeFileChanged();

public slots:

protected:
	virtual void mousePressEvent(QMouseEvent *event);

private:
	QGraphicsScene* m_scene;
	QString m_schemeFile;
	QRectF m_sceneRect;
	MidiMappingGui m_guiMapping;
};


inline QString MidiController::schemeFile() const
{
	return m_schemeFile;
}

#endif // MIDICONTROLLER_H
