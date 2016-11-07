/********************************************************************************
** Form generated from reading UI file 'configurationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONDIALOG_H
#define UI_CONFIGURATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *player1Name;
    QLabel *label_2;
    QLineEdit *player2Name;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigurationDialog)
    {
        if (ConfigurationDialog->objectName().isEmpty())
            ConfigurationDialog->setObjectName(QStringLiteral("ConfigurationDialog"));
        ConfigurationDialog->resize(232, 116);
        gridLayout = new QGridLayout(ConfigurationDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ConfigurationDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        player1Name = new QLineEdit(ConfigurationDialog);
        player1Name->setObjectName(QStringLiteral("player1Name"));

        gridLayout->addWidget(player1Name, 0, 1, 1, 1);

        label_2 = new QLabel(ConfigurationDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        player2Name = new QLineEdit(ConfigurationDialog);
        player2Name->setObjectName(QStringLiteral("player2Name"));

        gridLayout->addWidget(player2Name, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigurationDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(player1Name);
        label_2->setBuddy(player2Name);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(player1Name, player2Name);

        retranslateUi(ConfigurationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigurationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigurationDialog, SLOT(reject()));
        QObject::connect(player1Name, SIGNAL(textChanged(QString)), ConfigurationDialog, SLOT(updateOKButtonState()));
        QObject::connect(player2Name, SIGNAL(textChanged(QString)), ConfigurationDialog, SLOT(updateOKButtonState()));

        QMetaObject::connectSlotsByName(ConfigurationDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigurationDialog)
    {
        ConfigurationDialog->setWindowTitle(QApplication::translate("ConfigurationDialog", "Dialog", 0));
        label->setText(QApplication::translate("ConfigurationDialog", "Player &1 Name:", 0));
        label_2->setText(QApplication::translate("ConfigurationDialog", "Player &2 Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationDialog: public Ui_ConfigurationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONDIALOG_H
