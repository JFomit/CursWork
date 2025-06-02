#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = 0);

    QPointF getStartPoint();
    QPointF getEndPoint();
    void setBrush(QBrush clientBrush);

private:
    QPointF previousPoint;
    QPointF startPoint;
    QBrush brush;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:
    void linePointSignal();
    void ellipsePointSignals();

};

#endif // PAINTSCENE_H
