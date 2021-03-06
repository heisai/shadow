// =====================================================================================
// 
//	   Filename:  CamareDialog.cpp
//
//	Description:  摄像头对话框实现文件
//
//		Version:  1.0
//		Created:  2013年03月07日 20时11分20秒
//	   Revision:  none
//	   Compiler:  cl
//
//		 Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//		Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "CamareDialog.h"
#include "CamareGet.h"

CamareDialog::CamareDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);

	label->setPixmap(QPixmap(":/res/images/camarewait.png"));

	camaraGet = new CamaraGet();

	camaraGet->setLabel(label);

	connect(camareButton, SIGNAL(clicked()), this, SLOT(CamareButton()));

	setWindowIcon(QIcon(":/res/images/camare.png"));
}

CamareDialog::~CamareDialog()
{

}

void CamareDialog::closeEvent(QCloseEvent *event)
{
	camaraGet->closeCamara();
}

void CamareDialog::CamareButton()
{
	static bool isStart = 0;

	if (isStart == 0) {
		camareButton->setText(tr("关闭摄像头"));
		camaraGet->openCamara();
		isStart = 1;
	} else {
		camareButton->setText(tr("启动摄像头"));
		camaraGet->closeCamara();
		isStart = 0;
	}
}
