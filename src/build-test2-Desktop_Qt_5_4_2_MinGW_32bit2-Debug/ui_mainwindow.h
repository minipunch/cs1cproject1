/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMember_File_Import;
    QAction *actionPurchase_File_Import;
    QAction *actionSave_All;
    QAction *actionMember_File_Save;
    QAction *actionPurchase_File_Save;
    QAction *actionPrint_member_list;
    QAction *actionSearch_Member_List;
    QAction *actionAdd_A_Member;
    QAction *actionDelete_a_member;
    QAction *actionRebate;
    QAction *actionExpirations;
    QAction *actionSearch;
    QAction *actionNew;
    QAction *actionDelete;
    QAction *actionSearch_2;
    QWidget *centralWidget;
    QLabel *label;
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImport;
    QMenu *menuSave;
    QMenu *menuMembers;
    QMenu *menuManage_Products;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(915, 636);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionMember_File_Import = new QAction(MainWindow);
        actionMember_File_Import->setObjectName(QStringLiteral("actionMember_File_Import"));
        actionPurchase_File_Import = new QAction(MainWindow);
        actionPurchase_File_Import->setObjectName(QStringLiteral("actionPurchase_File_Import"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QStringLiteral("actionSave_All"));
        actionMember_File_Save = new QAction(MainWindow);
        actionMember_File_Save->setObjectName(QStringLiteral("actionMember_File_Save"));
        actionPurchase_File_Save = new QAction(MainWindow);
        actionPurchase_File_Save->setObjectName(QStringLiteral("actionPurchase_File_Save"));
        actionPrint_member_list = new QAction(MainWindow);
        actionPrint_member_list->setObjectName(QStringLiteral("actionPrint_member_list"));
        actionSearch_Member_List = new QAction(MainWindow);
        actionSearch_Member_List->setObjectName(QStringLiteral("actionSearch_Member_List"));
        actionAdd_A_Member = new QAction(MainWindow);
        actionAdd_A_Member->setObjectName(QStringLiteral("actionAdd_A_Member"));
        actionDelete_a_member = new QAction(MainWindow);
        actionDelete_a_member->setObjectName(QStringLiteral("actionDelete_a_member"));
        actionRebate = new QAction(MainWindow);
        actionRebate->setObjectName(QStringLiteral("actionRebate"));
        actionExpirations = new QAction(MainWindow);
        actionExpirations->setObjectName(QStringLiteral("actionExpirations"));
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QStringLiteral("actionSearch"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionSearch_2 = new QAction(MainWindow);
        actionSearch_2->setObjectName(QStringLiteral("actionSearch_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 0, 311, 71));
        QFont font;
        font.setFamily(QStringLiteral("Tempus Sans ITC"));
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 70, 861, 471));
        listWidget->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 550, 601, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton_9);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        label->raise();
        listWidget->raise();
        pushButton_3->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 915, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuImport = new QMenu(menuFile);
        menuImport->setObjectName(QStringLiteral("menuImport"));
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        menuMembers = new QMenu(menuBar);
        menuMembers->setObjectName(QStringLiteral("menuMembers"));
        menuManage_Products = new QMenu(menuBar);
        menuManage_Products->setObjectName(QStringLiteral("menuManage_Products"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuMembers->menuAction());
        menuBar->addAction(menuManage_Products->menuAction());
        menuFile->addAction(menuImport->menuAction());
        menuFile->addAction(menuSave->menuAction());
        menuFile->addAction(actionSave_All);
        menuImport->addAction(actionMember_File_Import);
        menuImport->addAction(actionPurchase_File_Import);
        menuSave->addAction(actionMember_File_Save);
        menuSave->addAction(actionPurchase_File_Save);
        menuMembers->addAction(actionPrint_member_list);
        menuMembers->addAction(actionSearch_Member_List);
        menuMembers->addAction(actionAdd_A_Member);
        menuMembers->addAction(actionDelete_a_member);
        menuMembers->addAction(actionRebate);
        menuMembers->addAction(actionExpirations);
        menuManage_Products->addAction(actionNew);
        menuManage_Products->addAction(actionDelete);
        menuManage_Products->addAction(actionSearch_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionMember_File_Import->setText(QApplication::translate("MainWindow", "Member File", 0));
        actionPurchase_File_Import->setText(QApplication::translate("MainWindow", "Purchase File", 0));
        actionSave_All->setText(QApplication::translate("MainWindow", "Save All", 0));
        actionMember_File_Save->setText(QApplication::translate("MainWindow", "Member File", 0));
        actionPurchase_File_Save->setText(QApplication::translate("MainWindow", "Purchase File", 0));
        actionPrint_member_list->setText(QApplication::translate("MainWindow", "Show All", 0));
        actionSearch_Member_List->setText(QApplication::translate("MainWindow", "Search", 0));
        actionAdd_A_Member->setText(QApplication::translate("MainWindow", "New", 0));
        actionDelete_a_member->setText(QApplication::translate("MainWindow", "Delete", 0));
        actionRebate->setText(QApplication::translate("MainWindow", "Rebates", 0));
        actionExpirations->setText(QApplication::translate("MainWindow", "Expirations", 0));
        actionSearch->setText(QApplication::translate("MainWindow", "Info", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0));
        actionSearch_2->setText(QApplication::translate("MainWindow", "Search", 0));
        label->setText(QApplication::translate("MainWindow", "Five Gui's Club", 0));
        pushButton->setText(QApplication::translate("MainWindow", "SALES REPORT", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "PURCHASE LIST", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "MEMBER LIST", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "PRODUCT INFO", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuImport->setTitle(QApplication::translate("MainWindow", "Import", 0));
        menuSave->setTitle(QApplication::translate("MainWindow", "Save", 0));
        menuMembers->setTitle(QApplication::translate("MainWindow", "Members", 0));
        menuManage_Products->setTitle(QApplication::translate("MainWindow", "Products", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
