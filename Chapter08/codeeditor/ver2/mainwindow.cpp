#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->hide();
    connect(ui->actionNewDocument, SIGNAL(triggered()), this, SLOT(newDocument()));
    connect(ui->actionOpenDocument, SIGNAL(triggered()), this, SLOT(openDocument()));
    connect(ui->actionSaveDocument, SIGNAL(triggered()), this, SLOT(saveDocument()));
    connect(ui->actionSaveDocumentAs, SIGNAL(triggered()), this, SLOT(saveDocumentAs()));
    connect(ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionExecuteScript, SIGNAL(triggered()), this, SLOT(run()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDocument()
{
    setWindowFilePath(QString());
    ui->codeEditor->clear();
    ui->logWindow->clear();
}

void MainWindow::openDocument()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Document", QDir::homePath(), "JavaScript Documents (*.js)");
    if(filePath.isEmpty()) return;
    open(filePath);
}

void MainWindow::saveDocument()
{
    if(windowFilePath().isEmpty()) {
        saveDocumentAs();
        return;
    }
    save(windowFilePath());
}

void MainWindow::saveDocumentAs()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Document", QDir::homePath(), "JavaScript Documents (*.js)");
    if(filePath.isEmpty()) return;
    setWindowFilePath(filePath);
    saveDocument();
}

void MainWindow::open(const QString &filePath)
{
    QFile file(filePath);
    if(!file.open(QFile::ReadOnly|QFile::Text)) {
        QMessageBox::critical(this, "Error", "Can't open file.");
        return;
    }
    setWindowFilePath(filePath);
    ui->codeEditor->setPlainText(QTextStream(&file).readAll());
    ui->logWindow->clear();
}

void MainWindow::save(const QString &filePath)
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly|QFile::Truncate|QFile::Text)) {
        return;
    }
    QTextStream stream(&file);
    stream << ui->codeEditor->toPlainText();
    ui->codeEditor->document()->setModified(false);
}

void MainWindow::run()
{
    ui->logWindow->clear();
    QString scriptSourceCode = ui->codeEditor->toPlainText();
    m_engine.pushContext();
    QScriptValue result = m_engine.evaluate(scriptSourceCode, windowFilePath());
    if(m_engine.hasUncaughtException()) {
        QScriptValue exception = m_engine.uncaughtException();
        QTextCursor cursor = ui->logWindow->textCursor();
        QTextCharFormat errFormat;
        errFormat.setForeground(Qt::red);
        cursor.insertText(QString("Exception at line %1:").arg(m_engine.uncaughtExceptionLineNumber()), errFormat);
        cursor.insertText(exception.toString(), errFormat);
        QStringList trace = m_engine.uncaughtExceptionBacktrace();
        errFormat.setForeground(Qt::darkRed);
        for(int i = 0; i < trace.size(); ++i) {
            const QString & traceFrame = trace.at(i);
            cursor.insertBlock();
            cursor.insertText(QString("#%1: %2").arg(i).arg(traceFrame), errFormat);
        }
    } else {
        QTextCursor cursor = ui->logWindow->textCursor();
        QTextCharFormat resultFormat;
        resultFormat.setForeground(Qt::blue);
        cursor.insertText(result.toString(), resultFormat);
    }
    m_engine.popContext();
}
