#include "workwithpixmap.h"
#include <QPainter>

WorkWithPixmap::WorkWithPixmap() {}

QPixmap WorkWithPixmap::TranslationInPixmap(QGraphicsScene *scene)
{
    QPixmap pixmap(scene->sceneRect().size().toSize());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    scene->render(&painter);

    return pixmap;
}
