#ifndef L1V2CL_MAINWINDOW_H
#define L1V2CL_MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include "UI.h"
#include "textControl.h"

class MainWindow : public QMainWindow {
public:
    Ui_MainWindow _ui{};
    explicit MainWindow(QWidget * parent = nullptr, Qt::WindowFlags flags = nullptr);

private:
    TextControl textControl;

    void btnApply();

    void updateData();

    void btnUndo();

    void btnRedo();

    void btnSave();

    void btnLoad();
};


#endif //L1V2CL_MAINWINDOW_H
