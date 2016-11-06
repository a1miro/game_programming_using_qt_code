#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScriptEngine>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void newDocument();
    void openDocument();
    void saveDocument();
    void saveDocumentAs();
    void open(const QString &filePath);
    void save(const QString &filePath);
    void run();
private:
    Ui::MainWindow *ui;
    QScriptEngine m_engine;
};

#endif // MAINWINDOW_H
