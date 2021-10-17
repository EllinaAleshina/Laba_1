#include "MainWindow.h"
MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags) : QMainWindow(parent, flags) {
    _ui.setupUi(this);
    textControl = TextControl();
    QObject::connect(_ui.undoBtn, &QPushButton::clicked, this, &MainWindow::btnUndo);
    QObject::connect(_ui.redoBtn, &QPushButton::clicked, this, &MainWindow::btnRedo);
    QObject::connect(_ui.saveBtn, &QPushButton::clicked, this, &MainWindow::btnSave);
    QObject::connect(_ui.loadBtn, &QPushButton::clicked, this, &MainWindow::btnLoad);
    QObject::connect(_ui.applyBtn, &QPushButton::clicked, this, &MainWindow::btnApply);
    updateData();
}

void MainWindow::btnApply() {
    string data = _ui.strEdit->text().toStdString();
    unsigned int pos = _ui.posEdit->text().toUInt();
    unsigned int len = _ui.lenEdit->text().toUInt();
    if (textControl.replace(data, pos, len))
        _ui.errorLabel->setText("Error");
    updateData();
}

void MainWindow::btnUndo() {
    textControl.undo();
    updateData();
}

void MainWindow::btnRedo() {
    textControl.redo();
    updateData();
}

void MainWindow::btnSave() {
    if (textControl.save(_ui.lineEdit->text().toStdString()))
        _ui.errorLabel->setText("Error while saving");
    else
        _ui.errorLabel->setText("Saved successfully");
}

void MainWindow::btnLoad() {
    if (textControl.load(_ui.lineEdit->text().toStdString()))
        _ui.errorLabel->setText("Error while loading");
    else
        _ui.errorLabel->setText("Saved successfully");
    updateData();
}

void MainWindow::updateData() {
    _ui.textEdit->setText(QString::fromStdString(textControl.getText()));
    _ui.textEdit_2->setText(QString::fromStdString(textControl.getUndoStack()));
    _ui.textEdit_3->setText(QString::fromStdString(textControl.getRedoStack()));
    _ui.undoBtn->setEnabled(textControl.canUndo());
    _ui.redoBtn->setEnabled(textControl.canRedo());
}
