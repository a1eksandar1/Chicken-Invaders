/********************************************************************************
** Form generated from reading UI file 'hofwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOFWINDOW_H
#define UI_HOFWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_HofWindow
{
public:
    QGridLayout *gridLayout_2;
    QListView *listView;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *HofWindow)
    {
        if (HofWindow->objectName().isEmpty())
            HofWindow->setObjectName(QString::fromUtf8("HofWindow"));
        HofWindow->resize(795, 565);
        HofWindow->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(HofWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listView = new QListView(HofWindow);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backgrounds/gameBackground.png);\n"
"border-radius: 20px;"));
        listView->setItemAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(listView, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(HofWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("height:  30px;\n"
"background-image: url(:/images/backgrounds/usernameWindow.png);\n"
" background-repeat: no-repeat;\n"
"  background-attachment: fixed;\n"
"  background-position: center; \n"
"border-image: url(:/images/backgrounds/usernameWindow.png);"));
        pushButton->setFlat(false);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 6);
        horizontalLayout_2->setStretch(2, 5);

        gridLayout_2->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        gridLayout_2->setRowStretch(1, 8);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setColumnStretch(1, 6);

        retranslateUi(HofWindow);

        QMetaObject::connectSlotsByName(HofWindow);
    } // setupUi

    void retranslateUi(QDialog *HofWindow)
    {
        HofWindow->setWindowTitle(QCoreApplication::translate("HofWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("HofWindow", "Close Hall of Fame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HofWindow: public Ui_HofWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOFWINDOW_H
