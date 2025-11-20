// contactSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "funDeclaration.h"
#define MAX 1000
#include <string> 

// 设计联系人结构体
struct Person {
	// 姓名
	std::string m_Name;
	// 性别 1男 2女
	std::string m_Sex;
	// 年龄
	int m_Age;
	// 电话
	std::string m_Phone;
	// 住址
	std::string m_Address;
};

// 设计通讯录结构图
struct Addressbooks {
	// 通讯录中保存联系人信息的数组
	struct Person personArray[MAX];
	// 通讯录中联系人的数量
	int m_Size = 0;
};


int main() {

	// 创建一个通讯录结构的变量
	struct Addressbooks abs;
	// 新的通讯录的人员个数变量初始化为0
	abs.m_Size = 0;

	int select = 0; // Move this declaration before the while loop

	while (true) {
		
		//菜单调用
		showMenu();
		std::cout << "请输入想使用的功能：";

		std::cin >> select;
		switch (select) {
		case 1:		// 1、添加联系人
			addPerson(&abs);
			system("pause");		// 请按任意键继续
			system("cls");			// 清屏
			break;
		case 2:		// 2、显示联系人
			showPerson(&abs);
			system("pause");		// 请按任意键继续
			system("cls");			// 清屏
			break;
		case 3:		// 3、删除联系人
		{
			std::string name;
			std::cout << "请输入要删除的联系人姓名：";
			std::cin >> name;
			delPerson(&abs, isExist(&abs, name));
		}
		system("pause");		// 请按任意键继续
		system("cls");			// 清屏
			break;
		case 4:		// 4、查找联系人
			findPerson(&abs);
			system("pause");		// 请按任意键继续
			system("cls");			// 清屏
			break;
		case 5:		// 5、修改联系人
			modifyPerson(&abs);
			system("pause");		// 请按任意键继续
			system("cls");			// 清屏
			break;
		case 6:		// 6、清空联系人
			clearPerson(&abs);
			system("pause");		// 请按任意键继续
			system("cls");			// 清屏
			break;
		case 0:		// 0、退出联系人
			std::cout << "欢迎下次使用" << std::endl;
			goto end;
			break;
		default:
			std::cout << "输入有误，请重新输入->" << std::endl;
			break;
		}
	}


	// 结束
end:
	system("pause");
	return 0;
}

// showMenu函数用来显示主界面
void showMenu() {
	std::cout << "***********************" << std::endl;
	std::cout << "*****1、添加联系人*****" << std::endl;
	std::cout << "*****2、显示联系人*****" << std::endl;
	std::cout << "*****3、删除联系人*****" << std::endl;
	std::cout << "*****4、查找联系人*****" << std::endl;
	std::cout << "*****5、修改联系人*****" << std::endl;
	std::cout << "*****6、清空联系人*****" << std::endl;
	std::cout << "*****0、退出联系人*****" << std::endl;
	std::cout << "***********************" << std::endl;
}

// 功能实现1、添加联系人
void addPerson(struct Addressbooks* a) {
	if (a->m_Size == 1000) {
		std::cout << "通讯录已满，无法添加" << std::endl;
	}
	else {
		// 添加姓名
		std::cout << "请输入联系人姓名：";
		std::cin >> a->personArray[a->m_Size].m_Name;
		std::cout << "\n";

		// 添加性别
		int temporarySex = 0;
		std::cout << "请输入联系人性别（1：男、2：女）：";
// 用goto语句防止用户输入有误，若输入非1非2的数字，则回到again的位置重新输入
again:	std::cin >> temporarySex;
		if (temporarySex == 1) {
			a->personArray[a->m_Size].m_Sex = "男";
		}
		else if (temporarySex == 2) {
			a->personArray[a->m_Size].m_Sex = "女";
		}
		else {
			std::cout << "输入有误，请再次输入：";
			goto again;
		}
		std::cout << "\n";

		// 添加年龄
		std::cout << "请输入年龄：";
		std::cin >> a->personArray[a->m_Size].m_Age;
		std::cout << "\n";

		// 添加电话
		std::cout << "请输入电话：";
		std::cin >> a->personArray[a->m_Size].m_Phone;
		std::cout << "\n";

		// 添加住址
		std::cout << "请输入住址：";
		std::cin >> a->personArray[a->m_Size].m_Address;
		std::cout << "\n";

		// 更新通讯录人数
		a->m_Size++;

		std::cout << "添加成功" << std::endl;
	}
}

// 功能实现2、显示联系人
void showPerson(struct Addressbooks* a) {
	// 判断如果当前通讯录人数为0，则提示记录为空
	// 若当前通讯录人数不为0，则显示通讯录信息
	if (a->m_Size == 0) {
		std::cout << "当前通讯录为空，请添加信息后再查询" << std::endl;
	}
	else {
		for (int i = 0; i < a->m_Size; ++i) {
			std::cout << "姓名：" << a->personArray[i].m_Name << "\t\t";
			std::cout << "性别：" << a->personArray[i].m_Sex << "\t\t";
			std::cout << "年龄：" << a->personArray[i].m_Age << "\t\t";
			std::cout << "电话：" << a->personArray[i].m_Phone << "\t\t";
			std::cout << "住址：" << a->personArray[i].m_Address << std::endl;
		}
	}
}

// 功能实现3(1)、判断联系人是否存在
int isExist(struct Addressbooks* a, std::string name) {
	// 检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
	// 参数1：通讯录		参数2：对比姓名
	for (int i = 0; i < a->m_Size; i++) {
		// 找到用户输入的姓名了
		if (a->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

// 功能实现3(2)、删除联系人
void delPerson(struct Addressbooks* a, int isExist) {
	// 先判断联系人是否存在，得到存在的结果后，从当前位置开始到数组结束，将每一位都覆盖上后一位的信息，实现当前位被删除，后面所有位前移
	if (isExist == -1) {
		std::cout << "查无此人" << std::endl;
	}
	else {
		for (int i = isExist; i < a->m_Size; i++) {
			a->personArray[i] = a->personArray[i + 1];
		}
		a->m_Size--;
	}
}

// 功能实现4、查找联系人
void findPerson(struct Addressbooks* a) {
	// 先做判断联系人是否存在
	std::string tem_Name;
	std::cout << "请输入联系人姓名：";
	std::cin >> tem_Name;
	if (isExist(a, tem_Name) == -1) {		// 没找到
		std::cout << "查无此人" << std::endl;
	}
	else {
		for (int i = 0; i < a->m_Size; ++i) {		// 找到了
			if (a->personArray[i].m_Name == tem_Name) {
				std::cout << "姓名：" << a->personArray[i].m_Name << std::endl;
				std::cout << "性别：" << a->personArray[i].m_Sex << std::endl;
				std::cout << "年龄：" << a->personArray[i].m_Age << std::endl;
				std::cout << "电话：" << a->personArray[i].m_Phone << std::endl;
				std::cout << "住址：" << a->personArray[i].m_Address << std::endl;
				std::cout << std::endl;
			}
		}
	
	}
}

// 功能实现5、修改联系人
void modifyPerson(struct Addressbooks* a) {
	// 先做判断联系人是否存在
	std::string tem_Name;
	std::cout << "请输入要修改的联系人姓名：";
	std::cin >> tem_Name;
	if (isExist(a, tem_Name) == -1) {
		std::cout << "查无此人" << std::endl;
	}
	else {
		for (int i = 0; i < a->m_Size; i++) {
			if (a->personArray[i].m_Name == tem_Name) {
				std::cout << "请输入要修改的姓名：";		// 修改姓名
				std::cin >> a->personArray[i].m_Name;

				std::cout << "请输入要修改的性别(1：男、2：女)：";		// 修改性别
				int temporarySex;
again:			std::cin >> temporarySex;
				if (temporarySex == 1) {
					a->personArray[i].m_Sex = "男";
				}
				else if (temporarySex == 2) {
					a->personArray[i].m_Sex = "女";
				}
				else {
					std::cout << "输入有误，请再次输入：";
					goto again;
				}

				std::cout << "请输入要修改的年龄：";		// 修改年龄
				std::cin >> a->personArray[i].m_Age;

				std::cout << "请输入要修改的电话：";		// 修改电话
				std::cin >> a->personArray[i].m_Phone;

				std::cout << "请输入要修改的地址：";		// 修改地址
				std::cin >> a->personArray[i].m_Address;
			}
		}
		std::cout << "修改成功" << std::endl;
	}
}

// 功能实现6、清空联系人
void clearPerson(struct Addressbooks* a) {
	// 先判断通讯录是否为空，若为空，则提示用户：“通讯录已经为空”。
	if (a->m_Size == 0) {
		std::cout << "通讯录已经为空" << std::endl;
	}
	else {
		std::cout << "确认删除全部联系人？（Y/N）：";		// 提供一层保险，让用户确认全部删除
		char b;
		std::cin >> b;
		if (b == 'y' || b == 'Y') {
			for (int i = 0; i < a->m_Size; i++) {
				// 使得现有数据全部清零
				a->personArray[i].m_Name = "0";
				a->personArray[i].m_Sex = "0";
				a->personArray[i].m_Age = 0;
				a->personArray[i].m_Phone = "0";
				a->personArray[i].m_Address = "0";
			}
			// 归零通讯录人数
			a->m_Size = 0;
		}
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
