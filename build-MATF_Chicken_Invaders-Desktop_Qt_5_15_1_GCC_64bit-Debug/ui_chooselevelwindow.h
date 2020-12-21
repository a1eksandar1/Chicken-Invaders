/********************************************************************************
** Form generated from reading UI file 'chooselevelwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELWINDOW_H
#define UI_CHOOSELEVELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelWindow
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *ChooseLevelWindow)
    {
        if (ChooseLevelWindow->objectName().isEmpty())
            ChooseLevelWindow->setObjectName(QString::fromUtf8("ChooseLevelWindow"));
        ChooseLevelWindow->resize(698, 462);
        gridLayout = new QGridLayout(ChooseLevelWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(ChooseLevelWindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setAutoFillBackground(false);
        graphicsView->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(ChooseLevelWindow);

        QMetaObject::connectSlotsByName(ChooseLevelWindow);
    } // setupUi

    void retranslateUi(QWidget *ChooseLevelWindow)
    {
        ChooseLevelWindow->setWindowTitle(QCoreApplication::translate("ChooseLevelWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelWindow: public Ui_ChooseLevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELWINDOW_H
