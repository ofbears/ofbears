#include<iostream>
#include<string>
using namespace std;
#define Max 1000  //最大联系人数1000
extern int select = 0;//创建用户选择的变量
extern int thenum = -1;
struct Person {
	string name;//联系人姓名
	string sex;//联系人性别
	int age = 0;//联系人年龄
	long long phonenum = 0;//联系人电话号码
	string address;//联系人住址

};
struct Address {
	struct Person information[Max];//联系人的信息a
	int num = 0;//当前联系人个数
};
//用于打印个人信息的函数
void printperson(int num, Address person) {
	cout << "\t" << person.information[num].name << "\t" << person.information[num].sex << "\t";
	cout << person.information[num].age << "岁" << "\t" << person.information[num].phonenum << "\t";
	cout << person.information[num].address << endl;
}
//打印菜单

void showMenu() {
	cout << "**********功能菜单*************" << endl;
	cout << "******   1、添加联系人   ******" << endl;
	cout << "******   2、显示联系人   ******" << endl;
	cout << "******   3、删除联系人   ******" << endl;
	cout << "******   4、查找联系人   ******" << endl;
	cout << "******   5、修改联系人   ******" << endl;
	cout << "******   6、清空联系人   ******" << endl;
	cout << "******   0、退出通讯录   ******" << endl;
	cout << "*******************************" << endl;
}
//新增联系人调用函数
void addperson(struct Address* ads) {
	long ThePhonenumcant = 100000;
	if (ads->num > Max) {
		cout << "抱歉，通讯录已满，无法继续录入" << endl;
	}
	//输入联系人名字
	cout << "请输入联系人名字：";
	cin >> ads->information[ads->num].name;
	//输入联系人性别
	cout << "请输入联系人的性别:";
	while (true)
	{
		cin >> ads->information[ads->num].sex;
		if (ads->information[ads->num].sex == "女" || ads->information[ads->num].sex == "男") {
			break;
		}
		cout << "您输入错误，请重新输入" << endl;
		cout << "请输入联系人的性别(男或女):";
	}
	//输入联系人年龄
	cout << "请输入联系人年龄:";
	while (true)
	{
		cin >> ads->information[ads->num].age;
		if (ads->information[ads->num].age > 0 && ads->information[ads->num].age < 150) {
			break;
		}
		cout << "您输入错误，请重新输入" << endl;
		cout << "请输入联系人年龄:";
	}
	//输入联系人的电话号码
	while (true)
	{
		cout << "请输入联系人的电话号码:";
		cin >> ads->information[ads->num].phonenum;
		if (ads->information[ads->num].phonenum / ThePhonenumcant > 0) {
			break;
		}
		else {
			cout << "您输入错误，请重新输入！" << endl;
		}
	}
	//输入联系人的地址
	cout << "请输入联系人的住址:";
	cin >> ads->information[ads->num].address;
	//新增联系人人数加1
	ads->num++;
	//输出当前总联系人数
	//cout << "现在一共有" << ads->num << "个联系人" << endl;
	system("pause");
	system("cls");
}

//创建一个函数，实现显示当前的联系人
void ShowPerson(struct Address person) {
	//通过循环输出所有的联系人
	if (person.num == 0) {
		cout << "请先添加联系人" << endl;
		system("pause");
		system("cls");
	}
	int temp = 0;
	temp = person.num;
	if (temp == thenum) {
		temp--;
	}
	//循环打印联系人，逐条递出
	for (int i = 0; i < temp; i++) {
		cout << i + 1 << "\t";
		printperson(i, person);
	}
	cout << "目前总共" << person.num << "个联系人" << endl;
	if (select == 2) {
		system("pause");
		system("cls");
	}

}
//删除指定的联系人
void DelPerson(struct Address* delperson) {
	cout << "输入9527可退回" << endl;  //可退回至菜单
	cout << "请问你要删除哪一个(序号)：";
	cin >> thenum;
	while (true)
	{
		if (thenum == 9527) {
			break;
		}
		if (thenum > delperson->num || thenum == 0) {
			cout << "该联系人不存在！请重新输入：";
			cin >> thenum;
		}
		else
		{
			break;
		}
	}
	//将指定删除人的后一个联系人前移
	for (int i = 0; i < (delperson->num - thenum + 1); i++) {
		delperson->information[thenum - 1] = delperson->information[thenum];
		thenum++;
		delperson->num--;
		cout << "删除成功!" << endl;
	}
	system("pause");
	system("cls");
}
//寻找联系人调用函数
void FindPerson(Address findperson) {
	string Personname;
	cout << "输入9527可退回" << endl;
	cout << "请输入您要查找的人名：";
	cin >> Personname;
	int i = 0;
	while (true)
	{
		if (Personname == "9527") {
			system("cls");
			break;
		}
		if (findperson.num == 0) {
			system("cls");
			cout << "现在还没有联系人,请先添加联系人!" << endl << endl << endl;
			break;

		}
		if (Personname == findperson.information[i].name) {
			printperson(i, findperson);
			system("pause");
			system("cls");
			break;

		}
		i++;
		if (i == findperson.num) {
			cout << "您输入错误!请重新输入：";
			i = 0;
			cin >> Personname;
		}

	}
}
//修改指定联系人的数据
void modifyperson(Address* abs) {
	string name;
	string sex;
	int age = 0;
	string address;
	long long phonenum;
	int num = 0; //由用户选择删除的对象
	int controlnum = 0; //由用户选择需要修改的联系人部分
	if (abs->num == 0) {
		cout << "暂无联系人" << endl;
		system("pause");
		system("cls");
	}
	else {
		ShowPerson(*abs);
		cout << "键入9527可退回" << endl;
		cout << "请输入您需要修改的联系人编号:";
		while (true) {
			cin >> num;
			if (num > abs->num) {
				cout << "您输入错误，请重新输入:";
			}
			else if (num == 9527) {
				system("pause");
				system("cls");
			}
			else {
				break;
			}
		}
		printperson(num - 1, *abs);
		cout << "请问你要修改什么(1.姓名  2.性别  3.年龄  4.号码  5.地址): ";
		while (true) {
			cin >> controlnum;
			if (controlnum > 0 && controlnum < 6) {
				break;
			}
			else if (controlnum == 9527) {
				system("pause");
				system("cls");
			}
			cout << "您输入错误，请重新输入:";
		}
	}
	switch (controlnum)
	{
	case 1:
		cout << "请输入修改的姓名:";
		cin >> name;
		abs->information[num - 1].name = name;
		break;
	case 2:
		cout << "请输入修改的性别:";
		cin >> sex;
		abs->information[num - 1].sex = sex;
		break;
	case 3:
		cout << "请输入修改的年龄:";
		cin >> age;
		abs->information[num - 1].age = age;
		break;
	case 4:
		cout << "请输入修改的号码:";
		cin >> phonenum;
		abs->information[num - 1].phonenum = phonenum;
		break;
	case 5:
		cout << "请输入修改的地址:";
		cin >> address;
		abs->information[num - 1].address = address;
		break;
	}
	cout << "修改成功" << endl;
	system("cls");
}
void clearperson(Address* abs) {
	int getpersonnum = abs->num;
	for (int i = 0; i < getpersonnum; i++) {
		if (abs->num == 0) {
			break;
		}
		abs->information[abs->num - 1] = abs->information[abs->num];

	}
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
int main() {
	struct Address Addressbooks;
	Addressbooks.num = 0;//通讯录人数初始化
	while (true)
	{
		showMenu();
		cout << "请输入您想输入的值:";
		cin >> select;

		switch (select) {
		case 1:
			addperson(&Addressbooks);
			break;
		case 2:
			ShowPerson(Addressbooks);
			break;
		case 3:
			ShowPerson(Addressbooks);
			if (Addressbooks.num != 0) {
				DelPerson(&Addressbooks);
			}
			break;
		case 4:
			FindPerson(Addressbooks);
			break;
		case 5:
			modifyperson(&Addressbooks);
			break;
		case 6:
			clearperson(&Addressbooks);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;


		}
	}
}