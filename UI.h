
#ifndef UNTITLEDSDZBBN_H
#define UNTITLEDSDZBBN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadBtn;
    QLineEdit *lineEdit;
    QLabel *fnLabel;
    QPushButton *saveBtn;
    QTextEdit *textEdit;
    QPushButton *undoBtn;
    QPushButton *redoBtn;
    QLineEdit *strEdit;
    QLabel *strLabel;
    QLabel *posLabel;
    QLabel *lenLabel;
    QLineEdit *posEdit;
    QLineEdit *lenEdit;
    QPushButton *applyBtn;
    QLabel *errorLabel;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(405, 693);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loadBtn = new QPushButton(centralwidget);
        loadBtn->setObjectName(QString::fromUtf8("loadBtn"));
        loadBtn->setGeometry(QRect(10, 50, 89, 25));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 20, 361, 25));
        fnLabel = new QLabel(centralwidget);
        fnLabel->setObjectName(QString::fromUtf8("fnLabel"));
        fnLabel->setGeometry(QRect(10, 20, 31, 17));
        saveBtn = new QPushButton(centralwidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(110, 50, 89, 25));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 80, 391, 141));
        textEdit->setReadOnly(true);
        undoBtn = new QPushButton(centralwidget);
        undoBtn->setObjectName(QString::fromUtf8("undoBtn"));
        undoBtn->setGeometry(QRect(210, 50, 89, 25));
        redoBtn = new QPushButton(centralwidget);
        redoBtn->setObjectName(QString::fromUtf8("redoBtn"));
        redoBtn->setGeometry(QRect(310, 50, 89, 25));
        strEdit = new QLineEdit(centralwidget);
        strEdit->setObjectName(QString::fromUtf8("strEdit"));
        strEdit->setGeometry(QRect(10, 250, 121, 25));
        strLabel = new QLabel(centralwidget);
        strLabel->setObjectName(QString::fromUtf8("strLabel"));
        strLabel->setGeometry(QRect(10, 230, 41, 17));
        posLabel = new QLabel(centralwidget);
        posLabel->setObjectName(QString::fromUtf8("posLabel"));
        posLabel->setGeometry(QRect(150, 230, 71, 17));
        lenLabel = new QLabel(centralwidget);
        lenLabel->setObjectName(QString::fromUtf8("lenLabel"));
        lenLabel->setGeometry(QRect(280, 230, 71, 17));
        posEdit = new QLineEdit(centralwidget);
        posEdit->setObjectName(QString::fromUtf8("posEdit"));
        posEdit->setGeometry(QRect(150, 250, 91, 25));
        lenEdit = new QLineEdit(centralwidget);
        lenEdit->setObjectName(QString::fromUtf8("lenEdit"));
        lenEdit->setGeometry(QRect(270, 250, 91, 25));
        applyBtn = new QPushButton(centralwidget);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
        applyBtn->setGeometry(QRect(10, 280, 89, 25));
        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(150, 290, 191, 17));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 330, 181, 351));
        textEdit_2->setReadOnly(true);
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(200, 330, 191, 351));
        textEdit_3->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 310, 81, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 310, 81, 17));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        loadBtn->setText(QApplication::translate("MainWindow", "Load", nullptr));
        fnLabel->setText(QApplication::translate("MainWindow", "File:", nullptr));
        saveBtn->setText(QApplication::translate("MainWindow", "Save", nullptr));
        undoBtn->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        redoBtn->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        strLabel->setText(QApplication::translate("MainWindow", "Data:", nullptr));
        posLabel->setText(QApplication::translate("MainWindow", "Position:", nullptr));
        lenLabel->setText(QApplication::translate("MainWindow", "Length:", nullptr));
        applyBtn->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        errorLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "undoStack:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "redoStack:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UNTITLEDSDZBBN_H
