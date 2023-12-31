#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtWidgets>
#include <QtQuickWidgets>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>

QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
QList<QAction*> actionSystemLocation;
QSerialPort serialPort;
QString messageStatusBar("Select Serial Port...");
QString defaultLabel("Choose Menu Option");
QString portName;
int i = 0;
int sysLocAct_number = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/map.qml")));
    // ui->quickWidget->show();
    QWidget *widget = new QWidget;

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(defaultLabel);
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

//    QQuickWidget *qQuickWidgetMap = new QQuickWidget;
//    qQuickWidgetMap->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/map.qml")));
//    qQuickWidgetMap->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(50, 50, 50, 50);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);

    //layout->addWidget(qQuickWidgetMap);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();
//    connect(descriptionAct, &QAction::triggered, this, &MainWindow::setPortName);
//    connect(descriptionAct, &QAction::triggered, this, &MainWindow::setStatusBar);
}
#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.addSeparator();
    menu.addAction(newFileAct);
    menu.addAction(openFileAct);
    menu.addAction(saveFileAct);
    menu.addAction(printFileAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

    //SLOTS
//menu
//serialPorts
void MainWindow::selectPort(){
    if (infoLabel->text() == systemLocationAct->statusTip()) {
        infoLabel->setText(defaultLabel);
    } else {
        infoLabel->setText(systemLocationAct->statusTip());
    }
};

//file
void MainWindow::newFile()
{
    if (infoLabel->text() == newFileAct->statusTip()) {
        infoLabel->setText(defaultLabel);
    } else {
        infoLabel->setText(newFileAct->statusTip());
    }
}

void MainWindow::openFile()
{
    if (infoLabel->text() == openFileAct->statusTip()) {
        infoLabel->setText(defaultLabel);
    } else {
    infoLabel->setText(openFileAct->statusTip());
    }
}

void MainWindow::saveFile()
{
    if (infoLabel->text() == saveFileAct->statusTip()) {
    infoLabel->setText(defaultLabel);
    } else {
    infoLabel->setText(saveFileAct->statusTip());
    }
}

void MainWindow::print()
{
    if (infoLabel->text() == printFileAct->statusTip()) {
    infoLabel->setText(defaultLabel);
    } else {
    infoLabel->setText(printFileAct->statusTip());
    }
}

//Edit
void MainWindow::cut()
{
    if (infoLabel->text() == cutAct->statusTip()) {
    infoLabel->setText(defaultLabel);
    } else {
    infoLabel->setText(cutAct->statusTip());
    }
}

void MainWindow::copy()
{
    if (infoLabel->text() == copyAct->statusTip()) {
    infoLabel->setText(defaultLabel);
    } else { infoLabel->setText(copyAct->statusTip());
    }
}

void MainWindow::paste()
{
    if  (infoLabel->text() == pasteAct->statusTip()) {
    infoLabel->setText(defaultLabel);
    } else { infoLabel->setText(pasteAct->statusTip());
    }
}

//help
void MainWindow::help()
{
    if  (infoLabel->text() == helpAct->statusTip()) {
    infoLabel->setText(defaultLabel);
    } else { infoLabel->setText(helpAct->statusTip());
    }
}

//  FUNCTION
void MainWindow::createActions(){
    //portMenu
    portNameAct;
    descriptionAct;
    manufacturerAct;
    serialNumberAct;
    systemLocationAct;
    vendorIdAct;
    productIdAct;

    //fileMenu
    newFileAct = new QAction(tr("File &New"), this);
    newFileAct->setShortcut(QKeySequence::New);
    newFileAct->setShortcutVisibleInContextMenu(true);
    newFileAct->setStatusTip("Create a new file");
    connect(newFileAct, &QAction::triggered, this, &MainWindow::newFile);

    openFileAct = new QAction(tr("File &Open"), this);
    openFileAct->setShortcut(QKeySequence::Open);
    openFileAct->setShortcutVisibleInContextMenu(true);
    openFileAct->setStatusTip("Open File");
    connect(openFileAct, &QAction::triggered, this, &MainWindow::openFile);

    saveFileAct = new QAction(tr("File &Save"), this);
    saveFileAct->setShortcut(QKeySequence::Save);
    saveFileAct->setShortcutVisibleInContextMenu(true);
    saveFileAct->setStatusTip("Save File");
    connect(saveFileAct, &QAction::triggered, this, &MainWindow::saveFile);

    printFileAct = new QAction(tr("&Print"), this);
    printFileAct->setShortcut(QKeySequence::Print);
    printFileAct->setShortcutVisibleInContextMenu(true);
    printFileAct->setStatusTip("Print...");
    connect(printFileAct, &QAction::triggered, this, &MainWindow::print);

    //editMenu
    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcut(QKeySequence::Cut);
    cutAct->setShortcutVisibleInContextMenu(true);
    cutAct->setStatusTip("Cut the current selection");
    connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setShortcutVisibleInContextMenu(true);
    copyAct->setStatusTip("Copy the current selection");
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcut(QKeySequence::Paste);
    pasteAct->setShortcutVisibleInContextMenu(true);
    pasteAct->setStatusTip("Paste the clipboard's contents into the current selection");
    connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);

    //helpMenu
    helpAct = new QAction(tr("Help"), this);
    helpAct->setShortcut(QKeySequence::HelpContents);
    helpAct->setShortcutVisibleInContextMenu(true);
    helpAct->setStatusTip("Help information");
    connect(helpAct, &QAction::triggered, this, &MainWindow::help);
}

void MainWindow::createMenus()
{
    alignmentGroup = new QActionGroup(this);
    setWindowTitle(tr("NMEA Data Reader"));
    setMinimumSize(640, 480);
    resize(480, 320);
    serialMenu = menuBar()->addMenu(tr("&Serial Ports"));
    foreach (const QSerialPortInfo &port, availablePorts)
    {
        portMenu = serialMenu->addMenu(port.portName());
        descriptionAct = portMenu->addAction("Description: " + port.description());
        manufacturerAct = portMenu->addAction("Manufacturer: " + port.manufacturer());
        serialNumberAct = portMenu->addAction("Serial number: " + port.serialNumber());
        if(port.systemLocation() != "/dev/cu.BLTH" &&
            port.systemLocation() != "/dev/tty.BLTH" &&
            port.systemLocation() != "/dev/cu.URT2" &&
            port.systemLocation() != "/dev/tty.URT2" &&
            port.systemLocation() != "/dev/cu.URT1" &&
            port.systemLocation() != "/dev/tty.URT1")
        {

            QString label = "ActionLabel" + QString::number(sysLocAct_number);
            systemLocationAct1 = new QAction(label, this);
            systemLocationAct1 = portMenu->addAction("System location: " + port.systemLocation());
            systemLocationAct1->setStatusTip("System location: " + port.systemLocation());
            systemLocationAct1->setObjectName(port.portName());
            if(port.hasVendorIdentifier()){
                alignmentGroup->addAction(systemLocationAct1);
                systemLocationAct1->setCheckable(true);
                connect(systemLocationAct1, &QAction::toggled, this, &MainWindow::setPortName);
                if ( i == 0)
                {
                systemLocationAct1->setChecked(true);
                i++;
                }
            }
            sysLocAct_number ++;
        }
        if(port.hasVendorIdentifier())
        { vendorIdAct = portMenu->addAction("Vendor ID: " + QString::number(port.vendorIdentifier()));}
        if(port.hasProductIdentifier())
        { productIdAct = portMenu->addAction("Product ID: " + QString::number(port.productIdentifier())); }
    }
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newFileAct);
    fileMenu->addAction(openFileAct);
    fileMenu->addAction(saveFileAct);
    fileMenu->addAction(printFileAct);
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAct);
    statusBar()->showMessage(messageStatusBar);
}

void MainWindow::setPortName()
{   qDebug() << systemLocationAct1->statusTip();
    if(serialPort.isOpen()){
        qDebug() << "serial is open...";
        serialPort.close();
        qDebug() << "serial closed...";
    } else
        serialPort.setPortName(systemLocationAct1->objectName());
            serialPort.setBaudRate(QSerialPort::Baud4800, QSerialPort::AllDirections);
            serialPort.setDataBits(QSerialPort::Data8);
            serialPort.setParity(QSerialPort::NoParity);
            serialPort.setStopBits(QSerialPort::OneStop);
            serialPort.setFlowControl(QSerialPort::NoFlowControl);
            if (serialPort.open(QIODevice::ReadWrite)) {
                qDebug() << serialPort.portName() << "Has been open!\n";
                if (serialPort.waitForReadyRead(3000)) {
                    QByteArray dataReceived = serialPort.readAll();
                    int i = 1;
                    while(serialPort.waitForReadyRead(3000)) {
                        qDebug() << i << ":" << dataReceived;
                        i++; }
                } else {qDebug() << "waitForReadyRead ERROR:";
                    serialPort.close(); }
            } else
            qDebug() << "portName ERROR: ";
            serialPort.close();
}

void MainWindow::setStatusBar()
{
    statusBar()->clearMessage();
    messageStatusBar = ("Data from: ");
    statusBar()->showMessage(messageStatusBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}
