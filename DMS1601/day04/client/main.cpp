// 主函数
#include <cstring>
#include <QApplication>
#include "logreader.h"
#include "consolesender.h"
#include "socketsender.h"
#include "client.h"
#include "clientdlg.h"
int main (int argc, char* argv[]) {
	if (argc < 2) {
		try {
			LogReader reader ("./wtmpx",
				"./logins.dat");
//			ConsoleSender sender;
			SocketSender sender (
				"./fail.dat", 8888, "172.30.4.130");
			Client client (reader, sender);
			client.dataMine ();
		}
		catch (exception& ex) {
			cout << ex.what () << endl;
			return -1;
		}
	}
	else
	if (! strcmp (argv[1], "-g")) {
		/*
		cout << "图形用户界面尚未实现！"
			<< endl;
		return -1;
		*/
		QApplication app (argc, argv);
		ClientDlg dlg;
		dlg.show ();
		return app.exec ();
	}
	else {
		cout << "用法：" << argv[0]
			<< " [-g]" << endl;
		return -1;
	}
	return 0;
}
