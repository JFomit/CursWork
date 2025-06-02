#include "paintscene.h"

PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene(parent)
    ,brush(Qt::red)
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               brush);
    previousPoint = event->scenePos();
    emit ellipsePointSignals();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(brush, 10, Qt::SolidLine, Qt::RoundCap));
    startPoint = previousPoint;
    previousPoint = event->scenePos();
    emit linePointSignal();

}

QPointF PaintScene::getStartPoint() {
    return startPoint;
}

QPointF PaintScene::getEndPoint() {
    return previousPoint;
}

void PaintScene::setBrush(QBrush clientBrush) {
    brush = clientBrush;
}


