

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QTabWidget;
class QQuickWidget;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU


private slots:
    void setPortName();
    void setStatusBar();
    void selectPort();
    void newFile();
    void openFile();
    void saveFile();
    void print();
    void cut();
    void copy();
    void paste();
    void help();
    /*void undo();
    void redo();
    void bold();
    void italic();
    void leftAlign();
    void rightAlign();
    void justify();
    void center();
    void setLineSpacing();
    void setParagraphSpacing();
    void about();
    void aboutQt();*/
private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
private:
    //menuBar
    QMenu *serialMenu;
    QMenu *portMenu;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QActionGroup *alignmentGroup;
    //serialMenu->portMenu
    QAction *portNameAct;
    QAction *descriptionAct;
    QAction *manufacturerAct;
    QAction *serialNumberAct;
    QAction *systemLocationAct;
    QAction *systemLocationAct1;
    QAction *vendorIdAct;
    QAction *productIdAct;
    //fileMenu
    QAction *newFileAct;
    QAction *openFileAct;
    QAction *saveFileAct;
    QAction *printFileAct;
    //editMenu
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    //helpMenu
    QAction *helpAct;
    //

    QStatusBar *statusStBar;
    QString *label;
    QLabel *infoLabel;
    // for create QML Map on window
    QQuickWidget *qQuickWidgetMap;

};

#endif // MAINWINDOW_H
