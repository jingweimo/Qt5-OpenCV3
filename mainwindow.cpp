#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
    ui->graphicsView->setAcceptDrops(false);
    ui->graphicsView->setScene(&scene);

    ui->graphicsView->setInteractive(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    ui->graphicsView->setRubberBandSelectionMode(Qt::ContainsItemShape);


    setAcceptDrops(true);

//    scene.addEllipse(-100.0,100.0,200.0,100.0,QPen(QBrush(Qt::SolidPattern), 2.0),
//                     QBrush(Qt::Dense2Pattern));
//    scene.addLine(-200.0,200,200,200,QPen(QBrush(Qt::SolidPattern),5.0));
//    scene.addRect(-150,150,300,140);
//    //add polygon
//    QVector<QPoint> points;
//    points.append(QPoint(150,250));
//    points.append(QPoint(250,250));
//    points.append(QPoint(165,280));
//    points.append(QPoint(150,250));
//    scene.addPolygon(QPolygon(points));
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList acceptedFileTypes;
    acceptedFileTypes.append("jpg");
    acceptedFileTypes.append("png");
    acceptedFileTypes.append("bmp");

    if (event->mimeData()->hasUrls() && event->mimeData()->urls().count()==1)
    {
        QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
        if(acceptedFileTypes.contains(file.suffix().toLower()))
        {
            event->acceptProposedAction();
        }
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QPoint viewPos = ui->graphicsView->mapFromParent(event->pos());
    QPointF sceneDropPos = ui->graphicsView->mapToScene(viewPos);

    //ui->graphicsView->resetTransform();
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
    QPixmap pixmap;
    if(pixmap.load(file.absoluteFilePath()))
    {
        //scene.addPixmap(pixmap);
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        item -> setPos(sceneDropPos);
//        scene.clear();

        //make items selectable
        item->setFlag(QGraphicsItem::ItemIsSelectable);
        item->setAcceptedMouseButtons(Qt::LeftButton);

        scene.addItem(item);
//        qDebug()<<"scene.items().count():"<<scene.items().count();
        //delete item;

//        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
//        item->setGraphicsEffect(new QCustomGraphicsEffect(this));

        //item -> setPos(sceneDropPos);
        //scene.clear();
        //scene.addItem(item);
    }
    else
    {
        //display an error message
    }



}

void MainWindow::resizeEvent(QResizeEvent *event)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}
