#ifndef MENU_H
#define MENU_H


class Menu
{
public:
	Menu();
	virtual ~Menu();
	int MainSelect();//���˵�ѡ��
	void MainPrint();//�˵���ӡ
	int SaveSelect();//���Ȳ˵�ѡ��
	void SavePrint();//���Ȳ˵���ӡ
protected:
private:
	int selectNum;
};

#endif // MENU_H
