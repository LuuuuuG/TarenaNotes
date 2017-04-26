// 声明客户机对话框类
#ifndef _CLIENTDLG_H
#define _CLIENTDLG_H
#include <QDialog>
#include "workthread.h"
class QTextBrowser;
class ClientDlg : public QDialog {
	Q_OBJECT
public:
	// 构造器
	ClientDlg (void);
private slots:
	// 开始按钮点击槽
	void onStart (void);
	// 更新文本浏览槽
	void onUpdate (QString const& text);
private:
	QTextBrowser* m_browser; // 文本浏览器
	WorkThread m_work; // 工作线程
};
#endif // _CLIENTDLG_H
