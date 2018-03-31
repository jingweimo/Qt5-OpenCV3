#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QResizeEvent>
#include <QGraphicsScene>
#include <QMimeData>
#include <QFileInfo>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>

#include "qcustomgraphicseffect.h"
#include "qenhancedgraphicsview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene scene;


protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
