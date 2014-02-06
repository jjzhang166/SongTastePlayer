#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QMediaPlayer>
#include "stpage.h"
#include <QTime>
#include <QGraphicsScene>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTableWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void contextMenuEvent(QContextMenuEvent *);
    
private:
    Ui::Widget *ui;
    QList<STModel> musicLists;
    int musicListSize;
    int musicOrder;
    STPage *songteste;

    void loadListView();

    QMediaPlayer player;

    void updateTime(qint64 currentTimeNumber);
    QTime qint64ToTime(qint64 time);

    int palyNumber;
    bool buttonModel;
    QPixmap pixmap;
    QGraphicsScene *scene;

    QPoint dragPosition;
    QMap<int,QString> downloadList;
    QString downloadDir;

    QMenu *trayMenu;

    Http *http;

    QSystemTrayIcon* trayIcon;

    int downloadingRow;
    void contentMenu();
    void tableContentMenu(const QPoint &pos);
    void showTrayIcon();

    void titleShow();
    void titleHide();

    void downloadMusic(int i);
    void downloadProgress(qint64 recieved, qint64 total);
    void downloadManager();
    void slotOpenDir();
    void slotSetDir();
    void getConfig();

    void slotMusiclist();
    void slotDownload();
private slots:
    void slotPlayMusic(int id);

    void getTableItem(int row,int column);

    void setPosition(int position);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void playerStateChanged(QMediaPlayer::State state);

    void slotPlayButton();
    void slotPreButton();
    void slotNextButton();

    void updateVolume(int volume);
    void setRowColor(QTableWidget *table,int row, QColor textcolor, QColor backcolor);

    void slotLoadList(int type);
    void slotRefreshList();

    void slotChangelog();
    void slotHomepage();
    void slotQuit();
    void slotMenuWindowsMinimized();
    void slotTrayClicked(QSystemTrayIcon::ActivationReason reason);

    void playerMediaStatus(QMediaPlayer::MediaStatus stats);

    void slotHideList();
    void slotMusicOrder(int i);



signals:
    void signalPlayerMusic(int);
    void signalLoadList(int);
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // WIDGET_H
