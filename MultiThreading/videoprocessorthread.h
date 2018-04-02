#ifndef VIDEOPROCESSORTHREAD_H
#define VIDEOPROCESSORTHREAD_H

#include <QObject>
#include <QThread>
#include <QPixmap>

#include "opencv2/opencv.hpp"

class VideoProcessorThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoProcessorThread(QObject *parent = 0);

private:
    void run() override;


signals:
    void inDisplay(QPixmap pixmap);
    void outDisplay(QPixmap pixmap);

public slots:
};

#endif // VIDEOPROCESSORTHREAD_H
