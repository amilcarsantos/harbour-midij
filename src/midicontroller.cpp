#include "midicontroller.h"

#include <QPainter>

MidiController::MidiController(QQuickItem *parent) :
	QQuickPaintedItem(parent),
	m_sceneRect(0,0, 480, 800)
{
	m_scene = new QGraphicsScene();	// TODO criar o meu GraphicsScene...

	m_scene->setSceneRect(m_sceneRect);
	QGraphicsPixmapItem* px = m_scene->addPixmap(QPixmap("/usr/share/themes/jolla-ambient/meegotouch/icons/graphic-os-oem-logo.png"));
	px->setPos(0,0);


/*QGraphicsTextItem* text = m_scene->addText("Ola Mundo");
	text->setPos(100, 100);
	text->setDefaultTextColor(QColor(Qt::black));
*/
	setAcceptedMouseButtons(Qt::LeftButton);
}


MidiController::~MidiController()
{
	delete m_scene;
}
#include "Utils.h"
void MidiController::setSchemeFile(QString schemeFile)
{
	qDebug("scheme file: ");
	qDebug(schemeFile.toLocal8Bit());

    if (m_schemeFile == schemeFile)
        return;

    // update watcher to watch the new directory
/*    if (!m_schemeFile.isEmpty())
        m_watcher->removePath(m_dir);
    if (!schemeFile.isEmpty())
        m_watcher->addPath(dir);
*/
	QList<QGraphicsItem*> guiItems;
	QFileInfo schemeFileInfo(schemeFile);
	DirContext dc(schemeFileInfo);
	if (!m_guiMapping.loadScheme(schemeFileInfo.fileName(), guiItems))
		return;

	m_scene->blockSignals(true);
	m_scene->clear();

	foreach (QGraphicsItem *item, guiItems)
		m_scene->addItem(item);

	m_scene->blockSignals(false);

    m_schemeFile = schemeFile;

    emit schemeFileChanged();
}


void MidiController::paint(QPainter *painter)
{

	m_scene->render(painter, m_sceneRect, m_sceneRect);

}

void MidiController::mousePressEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	qDebug("mouse presss");
	event->accept();
	// TODO bloquear arrasto... permitir apenas no logo!!!
	// + mapear eventos para o scene

}

/*
void QDeclarativeMouseArea::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_D(QDeclarativeMouseArea);
    d->moved = false;
    d->stealMouse = d->preventStealing;
    if (!d->absorb)
        QDeclarativeItem::mousePressEvent(event);
    else {
        d->longPress = false;
        d->saveEvent(event);
        if (d->drag) {
            d->dragX = drag()->axis() & QDeclarativeDrag::XAxis;
            d->dragY = drag()->axis() & QDeclarativeDrag::YAxis;
        }
        if (d->drag)
            d->drag->setActive(false);
        setHovered(true);
        d->startScene = event->scenePos();
        // we should only start timer if pressAndHold is connected to.
        if (d->isPressAndHoldConnected())
            d->pressAndHoldTimer.start(PressAndHoldDelay, this);
        setKeepMouseGrab(d->stealMouse);
        event->setAccepted(setPressed(true));
    }
}




			QGraphicsSceneMouseEvent mouseEvent(QEvent::GraphicsSceneMousePress);
            mouseEvent.setWidget(viewport());
            mouseEvent.setButtonDownScenePos(d->mousePressButton, d->mousePressScenePoint);
            mouseEvent.setButtonDownScreenPos(d->mousePressButton, d->mousePressScreenPoint);
            mouseEvent.setScenePos(d->mousePressScenePoint);
            mouseEvent.setScreenPos(d->mousePressScreenPoint);
            mouseEvent.setLastScenePos(d->lastMouseMoveScenePoint);
            mouseEvent.setLastScreenPos(d->lastMouseMoveScreenPoint);
            mouseEvent.setButtons(event->buttons());
            mouseEvent.setButton(event->button());
            mouseEvent.setModifiers(event->modifiers());
            mouseEvent.setAccepted(false);
            if (event->spontaneous())
                qt_sendSpontaneousEvent(d->scene, &mouseEvent);
            else
                QApplication::sendEvent(d->scene, &mouseEvent);

            // Update the original mouse event accepted state.
            bool isAccepted = mouseEvent.isAccepted();
            event->setAccepted(isAccepted);

            // Update the last mouse event accepted state.
            d->lastMouseEvent.setAccepted(isAccepted);

            if (isAccepted)
                return;
*/
