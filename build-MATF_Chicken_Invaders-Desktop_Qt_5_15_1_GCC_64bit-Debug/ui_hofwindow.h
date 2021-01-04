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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_HofWindow
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_2;
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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tableView = new QTableView(HofWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(500, 0));
        tableView->setMaximumSize(QSize(550, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backgrounds/gameBackground.png);\n"
"border-radius: 20px;\n"
"font-size: 20px;\n"
"color:  white;\n"
"text-align: center;\n"
"background:transparent;\n"
"font-weight: bold;"));
        tableView->setAutoScroll(false);
        tableView->setProperty("showDropIndicator", QVariant(false));
        tableView->setDragEnabled(false);
        tableView->setAlternatingRowColors(false);
        tableView->setShowGrid(false);
        tableView->setGridStyle(Qt::NoPen);
        tableView->setWordWrap(false);
        tableView->setCornerButtonEnabled(false);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setMinimumSectionSize(230);
        tableView->horizontalHeader()->setDefaultSectionSize(230);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setMinimumSectionSize(40);
        tableView->verticalHeader()->setDefaultSectionSize(40);
        tableView->verticalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(tableView, 0, Qt::AlignHCenter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(HofWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(200, 50));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton {\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/backButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#pushButton:pressed {\n"
"border-image: url(:images/buttons/backButton_pressed.png);\n"
"}"));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(false);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 6);

        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 8);
        gridLayout_2->setRowStretch(2, 1);

        retranslateUi(HofWindow);

        QMetaObject::connectSlotsByName(HofWindow);
    } // setupUi

    void retranslateUi(QDialog *HofWindow)
    {
        HofWindow->setWindowTitle(QCoreApplication::translate("HofWindow", "Dialog", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HofWindow: public Ui_HofWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOFWINDOW_H
