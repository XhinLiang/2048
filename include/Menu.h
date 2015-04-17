#ifndef MENU_H
#define MENU_H


class Menu
{
public:
	Menu();
	virtual ~Menu();
	int MainSelect();//主菜单选择
	void MainPrint();//菜单打印
	int SaveSelect();//进度菜单选择
	void SavePrint();//进度菜单打印
protected:
private:
	int selectNum;
};

#endif // MENU_H
