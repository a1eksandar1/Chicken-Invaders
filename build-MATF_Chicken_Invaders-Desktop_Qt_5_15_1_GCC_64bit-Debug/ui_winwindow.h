/********************************************************************************
** Form generated from reading UI file 'winwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINWINDOW_H
#define UI_WINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_winWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *quitButton;
    QPushButton *backButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *winWindow)
    {
        if (winWindow->objectName().isEmpty())
            winWindow->setObjectName(QString::fromUtf8("winWindow"));
        winWindow->resize(400, 300);
        gridLayout = new QGridLayout(winWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        quitButton = new QPushButton(winWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);
        quitButton->setStyleSheet(QString::fromUtf8("#quitButton {\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/quit_button.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#quitButton:pressed {\n"
"border-image: url(:images/buttons/quit_button_pressed.png);\n"
"}"));

        horizontalLayout->addWidget(quitButton);

        backButton = new QPushButton(winWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        backButton->setStyleSheet(QString::fromUtf8("#backButton {\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/backButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#backButton:pressed {\n"
"border-image: url(:images/buttons/backButton_pressed.png);\n"
"}"));

        horizontalLayout->addWidget(backButton);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        gridLayout->setRowStretch(0, 12);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 5);

        retranslateUi(winWindow);

        QMetaObject::connectSlotsByName(winWindow);
    } // setupUi

    void retranslateUi(QDialog *winWindow)
    {
        winWindow->setWindowTitle(QCoreApplication::translate("winWindow", "Dialog", nullptr));
        quitButton->setText(QString());
        backButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class winWindow: public Ui_winWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINWINDOW_H
