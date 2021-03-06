// =====================================================================================
// 
//       Filename:  ServiceTreeView.cpp
//
//    Description:  服务浏览显示
//
//        Version:  1.0
//        Created:  2013年03月09日 19时12分01秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "ServerTreeView.h"

ServerTreeView::ServerTreeView()
{
	iPosition = 0;

	mainModel = new QStandardItemModel;

	mainModel->setColumnCount(5);
	mainModel->setHeaderData(0, Qt::Horizontal, tr("映像名称"));
	mainModel->setHeaderData(1, Qt::Horizontal, tr("PID"));
	mainModel->setHeaderData(2, Qt::Horizontal, tr("描述"));
	mainModel->setHeaderData(3, Qt::Horizontal, tr("服务状态"));
	mainModel->setHeaderData(4, Qt::Horizontal, tr("工作组"));

	this->setModel(mainModel);
}

ServerTreeView::~ServerTreeView()
{

}

void ServerTreeView::rebuildInfo()
{
	mainModel->clear();
	iPosition = 0;

	mainModel->setColumnCount(5);
	mainModel->setHeaderData(0, Qt::Horizontal, tr("映像名称"));
	mainModel->setHeaderData(1, Qt::Horizontal, tr("PID"));
	mainModel->setHeaderData(2, Qt::Horizontal, tr("描述"));
	mainModel->setHeaderData(3, Qt::Horizontal, tr("服务状态"));
	mainModel->setHeaderData(4, Qt::Horizontal, tr("工作组"));
}

void ServerTreeView::addOneServerItem(QString strServer, QString strPID, QString strDes, 
								QString strState, QString strWorkGroup)
{
	QStandardItem *item;

	item = new QStandardItem(QString(strServer));
	mainModel->setItem(iPosition, 0, item);
	item = new QStandardItem(QString(strPID));
	mainModel->setItem(iPosition, 1, item);
	item = new QStandardItem(QString(strDes));
	mainModel->setItem(iPosition, 2, item);
	item = new QStandardItem(QString(strState));
	mainModel->setItem(iPosition, 3, item);
	item = new QStandardItem(QString(strWorkGroup));
	mainModel->setItem(iPosition, 4, item);

	iPosition++;
}

QString ServerTreeView::getStrNowServer()
{
	return strNowServer;
}

void ServerTreeView::setNowSelectServer(QModelIndex &index)
{
	strNowServer = mainModel->data(index, 0).toString();
}

