/********************************************************************************
** Form generated from reading UI file 'quitgamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUITGAMEWINDOW_H
#define UI_QUITGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_QuitGameWindow
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ok_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancel_button;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *QuitGameWindow)
    {
        if (QuitGameWindow->objectName().isEmpty())
            QuitGameWindow->setObjectName(QString::fromUtf8("QuitGameWindow"));
        QuitGameWindow->resize(500, 400);
        gridLayout = new QGridLayout(QuitGameWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(QuitGameWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(" border-style: outset;\n"
" border-width: 2px;\n"
" border-radius: 50px;\n"
" border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/backgrounds/usernameWindow.png);\n"
"background: none;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ok_button = new QPushButton(frame);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ok_button->sizePolicy().hasHeightForWidth());
        ok_button->setSizePolicy(sizePolicy);
        ok_button->setStyleSheet(QString::fromUtf8("#ok_button{\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 50px;\n"
"border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/ok_button.png);\n"
"background: none;\n"
"}\n"
"#ok_button:pressed {\n"
"border-image: url(:images/buttons/ok_button_pressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(ok_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cancel_button = new QPushButton(frame);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        sizePolicy.setHeightForWidth(cancel_button->sizePolicy().hasHeightForWidth());
        cancel_button->setSizePolicy(sizePolicy);
        cancel_button->setStyleSheet(QString::fromUtf8("#cancel_button{\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 50px;\n"
"border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/cancel_button.png);\n"
"background: none;\n"
"}\n"
"#cancel_button:pressed {\n"
"border-image: url(:images/buttons/cancel_button_pressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(cancel_button);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 3);

        gridLayout_2->addLayout(horizontalLayout_2, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(" border-style: outset;\n"
" border-width: 2px;\n"
" border-radius: 50px;\n"
" border-color: purple;\n"
"background-color: transparent;\n"
"border-image: url(:images/backgrounds/transparent.png);\n"
"background: none;"));

        gridLayout_2->addWidget(label, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 4, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 3);
        gridLayout_2->setRowStretch(1, 3);
        gridLayout_2->setRowStretch(2, 3);
        gridLayout_2->setRowStretch(3, 2);
        gridLayout_2->setRowStretch(4, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 4);
        gridLayout_2->setColumnStretch(3, 1);
        gridLayout_2->setColumnStretch(4, 1);

        gridLayout->addWidget(frame, 2, 2, 1, 1);


        retranslateUi(QuitGameWindow);

        QMetaObject::connectSlotsByName(QuitGameWindow);
    } // setupUi

    void retranslateUi(QDialog *QuitGameWindow)
    {
        QuitGameWindow->setWindowTitle(QCoreApplication::translate("QuitGameWindow", "Dialog", nullptr));
        ok_button->setText(QString());
        cancel_button->setText(QString());
        label->setText(QCoreApplication::translate("QuitGameWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">Do you want to quit game?</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuitGameWindow: public Ui_QuitGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUITGAMEWINDOW_H
