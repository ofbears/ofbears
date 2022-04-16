#include<iostream>
#include<string>
using namespace std;
#define Max 1000  //�����ϵ����1000
extern int select = 0;//�����û�ѡ��ı���
extern int thenum = -1;
struct Person {
	string name;//��ϵ������
	string sex;//��ϵ���Ա�
	int age = 0;//��ϵ������
	long long phonenum = 0;//��ϵ�˵绰����
	string address;//��ϵ��סַ

};
struct Address {
	struct Person information[Max];//��ϵ�˵���Ϣa
	int num = 0;//��ǰ��ϵ�˸���
};
//���ڴ�ӡ������Ϣ�ĺ���
void printperson(int num, Address person) {
	cout << "\t" << person.information[num].name << "\t" << person.information[num].sex << "\t";
	cout << person.information[num].age << "��" << "\t" << person.information[num].phonenum << "\t";
	cout << person.information[num].address << endl;
}
//��ӡ�˵�

void showMenu() {
	cout << "**********���ܲ˵�*************" << endl;
	cout << "******   1�������ϵ��   ******" << endl;
	cout << "******   2����ʾ��ϵ��   ******" << endl;
	cout << "******   3��ɾ����ϵ��   ******" << endl;
	cout << "******   4��������ϵ��   ******" << endl;
	cout << "******   5���޸���ϵ��   ******" << endl;
	cout << "******   6�������ϵ��   ******" << endl;
	cout << "******   0���˳�ͨѶ¼   ******" << endl;
	cout << "*******************************" << endl;
}
//������ϵ�˵��ú���
void addperson(struct Address* ads) {
	long ThePhonenumcant = 100000;
	if (ads->num > Max) {
		cout << "��Ǹ��ͨѶ¼�������޷�����¼��" << endl;
	}
	//������ϵ������
	cout << "��������ϵ�����֣�";
	cin >> ads->information[ads->num].name;
	//������ϵ���Ա�
	cout << "��������ϵ�˵��Ա�:";
	while (true)
	{
		cin >> ads->information[ads->num].sex;
		if (ads->information[ads->num].sex == "Ů" || ads->information[ads->num].sex == "��") {
			break;
		}
		cout << "�������������������" << endl;
		cout << "��������ϵ�˵��Ա�(�л�Ů):";
	}
	//������ϵ������
	cout << "��������ϵ������:";
	while (true)
	{
		cin >> ads->information[ads->num].age;
		if (ads->information[ads->num].age > 0 && ads->information[ads->num].age < 150) {
			break;
		}
		cout << "�������������������" << endl;
		cout << "��������ϵ������:";
	}
	//������ϵ�˵ĵ绰����
	while (true)
	{
		cout << "��������ϵ�˵ĵ绰����:";
		cin >> ads->information[ads->num].phonenum;
		if (ads->information[ads->num].phonenum / ThePhonenumcant > 0) {
			break;
		}
		else {
			cout << "������������������룡" << endl;
		}
	}
	//������ϵ�˵ĵ�ַ
	cout << "��������ϵ�˵�סַ:";
	cin >> ads->information[ads->num].address;
	//������ϵ��������1
	ads->num++;
	//�����ǰ����ϵ����
	//cout << "����һ����" << ads->num << "����ϵ��" << endl;
	system("pause");
	system("cls");
}

//����һ��������ʵ����ʾ��ǰ����ϵ��
void ShowPerson(struct Address person) {
	//ͨ��ѭ��������е���ϵ��
	if (person.num == 0) {
		cout << "���������ϵ��" << endl;
		system("pause");
		system("cls");
	}
	int temp = 0;
	temp = person.num;
	if (temp == thenum) {
		temp--;
	}
	//ѭ����ӡ��ϵ�ˣ������ݳ�
	for (int i = 0; i < temp; i++) {
		cout << i + 1 << "\t";
		printperson(i, person);
	}
	cout << "Ŀǰ�ܹ�" << person.num << "����ϵ��" << endl;
	if (select == 2) {
		system("pause");
		system("cls");
	}

}
//ɾ��ָ������ϵ��
void DelPerson(struct Address* delperson) {
	cout << "����9527���˻�" << endl;  //���˻����˵�
	cout << "������Ҫɾ����һ��(���)��";
	cin >> thenum;
	while (true)
	{
		if (thenum == 9527) {
			break;
		}
		if (thenum > delperson->num || thenum == 0) {
			cout << "����ϵ�˲����ڣ����������룺";
			cin >> thenum;
		}
		else
		{
			break;
		}
	}
	//��ָ��ɾ���˵ĺ�һ����ϵ��ǰ��
	for (int i = 0; i < (delperson->num - thenum + 1); i++) {
		delperson->information[thenum - 1] = delperson->information[thenum];
		thenum++;
		delperson->num--;
		cout << "ɾ���ɹ�!" << endl;
	}
	system("pause");
	system("cls");
}
//Ѱ����ϵ�˵��ú���
void FindPerson(Address findperson) {
	string Personname;
	cout << "����9527���˻�" << endl;
	cout << "��������Ҫ���ҵ�������";
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
			cout << "���ڻ�û����ϵ��,���������ϵ��!" << endl << endl << endl;
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
			cout << "���������!���������룺";
			i = 0;
			cin >> Personname;
		}

	}
}
//�޸�ָ����ϵ�˵�����
void modifyperson(Address* abs) {
	string name;
	string sex;
	int age = 0;
	string address;
	long long phonenum;
	int num = 0; //���û�ѡ��ɾ���Ķ���
	int controlnum = 0; //���û�ѡ����Ҫ�޸ĵ���ϵ�˲���
	if (abs->num == 0) {
		cout << "������ϵ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		ShowPerson(*abs);
		cout << "����9527���˻�" << endl;
		cout << "����������Ҫ�޸ĵ���ϵ�˱��:";
		while (true) {
			cin >> num;
			if (num > abs->num) {
				cout << "�������������������:";
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
		cout << "������Ҫ�޸�ʲô(1.����  2.�Ա�  3.����  4.����  5.��ַ): ";
		while (true) {
			cin >> controlnum;
			if (controlnum > 0 && controlnum < 6) {
				break;
			}
			else if (controlnum == 9527) {
				system("pause");
				system("cls");
			}
			cout << "�������������������:";
		}
	}
	switch (controlnum)
	{
	case 1:
		cout << "�������޸ĵ�����:";
		cin >> name;
		abs->information[num - 1].name = name;
		break;
	case 2:
		cout << "�������޸ĵ��Ա�:";
		cin >> sex;
		abs->information[num - 1].sex = sex;
		break;
	case 3:
		cout << "�������޸ĵ�����:";
		cin >> age;
		abs->information[num - 1].age = age;
		break;
	case 4:
		cout << "�������޸ĵĺ���:";
		cin >> phonenum;
		abs->information[num - 1].phonenum = phonenum;
		break;
	case 5:
		cout << "�������޸ĵĵ�ַ:";
		cin >> address;
		abs->information[num - 1].address = address;
		break;
	}
	cout << "�޸ĳɹ�" << endl;
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
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
int main() {
	struct Address Addressbooks;
	Addressbooks.num = 0;//ͨѶ¼������ʼ��
	while (true)
	{
		showMenu();
		cout << "���������������ֵ:";
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;


		}
	}
}