// =====================================================================================
// 
//       Filename:  LinkListWidget.cpp
//
//    Description:  自动上线主机显示
//
//        Version:  1.0
//        Created:  2013年03月06日 11时08分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "LinkListWidget.h"

LinkListWidget::LinkListWidget()
{
	QListWidgetItem *elem;

	elem = new QListWidgetItem(QIcon(":/res/images/connected.png"), "127.0.0.1 —— 本地机器", this);
}

LinkListWidget::~LinkListWidget()
{

}
