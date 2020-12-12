/********************************************************************************
** Form generated from reading UI file 'usernamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERNAMEWINDOW_H
#define UI_USERNAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_UsernameWindow
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QLabel *usernameLabel;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *okButton;
    QPushButton *skipButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *UsernameWindow)
    {
        if (UsernameWindow->objectName().isEmpty())
            UsernameWindow->setObjectName(QString::fromUtf8("UsernameWindow"));
        UsernameWindow->resize(650, 450);
        UsernameWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(UsernameWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(UsernameWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(" border-style: outset;\n"
" border-width: 2px;\n"
" border-radius: 50px;\n"
" border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/backgrounds/usernameWindow.png);\n"
"background: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 1, 1, 1);

        usernameLabel = new QLabel(frame);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:images/backgrounds/usernameText.png);\n"
"background: none;\n"
"border-width: 2px;\n"
"border-radius: 50px;\n"
"border-color: purple;"));
        usernameLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(usernameLabel, 2, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 4, 1, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-image: none;\n"
"background: none;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: purple;"));
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(134, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 7, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 4, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 9, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        okButton = new QPushButton(frame);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);
        okButton->setStyleSheet(QString::fromUtf8(" border-style: outset;\n"
" border-width: 2px;\n"
" border-radius: 50px;\n"
" border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/ok_button.png);\n"
"background: none;"));

        horizontalLayout_2->addWidget(okButton);

        skipButton = new QPushButton(frame);
        skipButton->setObjectName(QString::fromUtf8("skipButton"));
        sizePolicy1.setHeightForWidth(skipButton->sizePolicy().hasHeightForWidth());
        skipButton->setSizePolicy(sizePolicy1);
        skipButton->setStyleSheet(QString::fromUtf8(" border-style: outset;\n"
" border-width: 2px;\n"
" border-radius: 50px;\n"
" border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/skip_button.png);\n"
"background: none;"));

        horizontalLayout_2->addWidget(skipButton);

        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        cancelButton->setStyleSheet(QString::fromUtf8(" border-style: outset;\n"
" border-width: 2px;\n"
" border-radius: 50px;\n"
" border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/cancel_button.png);\n"
""));

        horizontalLayout_2->addWidget(cancelButton);


        gridLayout_2->addLayout(horizontalLayout_2, 8, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 3);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 3);
        gridLayout_2->setRowStretch(3, 2);
        gridLayout_2->setRowStretch(4, 1);
        gridLayout_2->setRowStretch(5, 1);
        gridLayout_2->setRowStretch(6, 1);
        gridLayout_2->setRowStretch(7, 1);
        gridLayout_2->setRowStretch(8, 2);
        gridLayout_2->setRowStretch(9, 3);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 3);

        retranslateUi(UsernameWindow);

        QMetaObject::connectSlotsByName(UsernameWindow);
    } // setupUi

    void retranslateUi(QDialog *UsernameWindow)
    {
        UsernameWindow->setWindowTitle(QString());
        usernameLabel->setText(QString());
        lineEdit->setText(QString());
        okButton->setText(QString());
        skipButton->setText(QString());
        cancelButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UsernameWindow: public Ui_UsernameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERNAMEWINDOW_H
