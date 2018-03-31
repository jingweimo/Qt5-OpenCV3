#ifndef QENHANCEDGRAPHICSVIEW_H
#define QENHANCEDGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QtMath>
#include <QMouseEvent>
#include <QMenu>
#include <QGraphicsEffect>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include "qcustomgraphicseffect.h"

#include <QDebug>

class QEnhancedGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QEnhancedGraphicsView(QWidget *parent = 0);

signals:

public slots:

protected:
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QPointF sceneMousePos;

private slots:
    void clearAll(bool);
    void clearSelected(bool);
    void noEffect(bool);
    void blurEffect(bool);
//    void dropShadowEffect(bool);
    void colorizeEffect(bool);
    void customEffect(bool);
};

#endif // QENHANCEDGRAPHICSVIEW_H
