/********************************************************************************
** Form generated from reading UI file 'optionswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWINDOW_H
#define UI_OPTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionsWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *difficulty_label;
    QRadioButton *easyButton;
    QRadioButton *hardButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSlider *volumeSlider;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *backButton;

    void setupUi(QDialog *OptionsWindow)
    {
        if (OptionsWindow->objectName().isEmpty())
            OptionsWindow->setObjectName(QString::fromUtf8("OptionsWindow"));
        OptionsWindow->resize(795, 565);
        OptionsWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(OptionsWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        difficulty_label = new QLabel(OptionsWindow);
        difficulty_label->setObjectName(QString::fromUtf8("difficulty_label"));
        difficulty_label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:images/backgrounds/difficulty_label.png);\n"
"background: none;"));

        verticalLayout->addWidget(difficulty_label);

        easyButton = new QRadioButton(OptionsWindow);
        easyButton->setObjectName(QString::fromUtf8("easyButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(easyButton->sizePolicy().hasHeightForWidth());
        easyButton->setSizePolicy(sizePolicy);
        easyButton->setStyleSheet(QString::fromUtf8("#easyButton {\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/easyButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#easyButton:pressed {\n"
"border-image: url(:images/buttons/easyButton_pressed.png);\n"
"}"));

        verticalLayout->addWidget(easyButton);

        hardButton = new QRadioButton(OptionsWindow);
        hardButton->setObjectName(QString::fromUtf8("hardButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hardButton->sizePolicy().hasHeightForWidth());
        hardButton->setSizePolicy(sizePolicy1);
        hardButton->setStyleSheet(QString::fromUtf8("#hardButton {\n"
"background-color: transparent;\n"
"border-image: url(:images/buttons/hardButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#hardButton:pressed {\n"
"border-image: url(:images/buttons/hardButton_pressed.png);\n"
"}"));
        hardButton->setChecked(false);

        verticalLayout->addWidget(hardButton);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        volumeSlider = new QSlider(OptionsWindow);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy2);
        volumeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeSlider, 4, 3, 1, 1);

        label = new QLabel(OptionsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:images/backgrounds/difficulty_label.png);\n"
"background: none;"));

        gridLayout->addWidget(label, 3, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        backButton = new QPushButton(OptionsWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        sizePolicy1.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy1);
        backButton->setMaximumSize(QSize(200, 65));
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

        gridLayout->addWidget(backButton, 7, 1, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(1, 3);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 3);
        gridLayout->setRowStretch(6, 3);
        gridLayout->setRowStretch(7, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(3, 2);
        gridLayout->setColumnStretch(4, 3);

        retranslateUi(OptionsWindow);

        QMetaObject::connectSlotsByName(OptionsWindow);
    } // setupUi

    void retranslateUi(QDialog *OptionsWindow)
    {
        OptionsWindow->setWindowTitle(QCoreApplication::translate("OptionsWindow", "Dialog", nullptr));
        difficulty_label->setText(QString());
        easyButton->setText(QString());
        hardButton->setText(QString());
        label->setText(QString());
        backButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OptionsWindow: public Ui_OptionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWINDOW_H
