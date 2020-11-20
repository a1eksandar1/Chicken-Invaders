/********************************************************************************
** Form generated from reading UI file 'usernamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERNAMEWINDOW_H
#define UI_USERNAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
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
    QHBoxLayout *horizontalLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *skipButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QLabel *usernameLabel;

    void setupUi(QDialog *UsernameWindow)
    {
        if (UsernameWindow->objectName().isEmpty())
            UsernameWindow->setObjectName(QString::fromUtf8("UsernameWindow"));
        UsernameWindow->resize(311, 200);
        gridLayout = new QGridLayout(UsernameWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        okButton = new QPushButton(UsernameWindow);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(UsernameWindow);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        skipButton = new QPushButton(UsernameWindow);
        skipButton->setObjectName(QString::fromUtf8("skipButton"));

        horizontalLayout_2->addWidget(skipButton);


        gridLayout->addLayout(horizontalLayout_2, 8, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 8, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 9, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        lineEdit = new QLineEdit(UsernameWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 4, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 0, 1, 1, 1);

        usernameLabel = new QLabel(UsernameWindow);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(usernameLabel, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setColumnMinimumWidth(0, 20);
        gridLayout->setColumnMinimumWidth(1, 1);
        gridLayout->setColumnMinimumWidth(2, 20);

        retranslateUi(UsernameWindow);

        QMetaObject::connectSlotsByName(UsernameWindow);
    } // setupUi

    void retranslateUi(QDialog *UsernameWindow)
    {
        UsernameWindow->setWindowTitle(QCoreApplication::translate("UsernameWindow", "Dialog", nullptr));
        okButton->setText(QCoreApplication::translate("UsernameWindow", "Ok", nullptr));
        cancelButton->setText(QCoreApplication::translate("UsernameWindow", "Cancel", nullptr));
        skipButton->setText(QCoreApplication::translate("UsernameWindow", "Skip", nullptr));
        lineEdit->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("UsernameWindow", "Enter username:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsernameWindow: public Ui_UsernameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERNAMEWINDOW_H
