// 全局变量，用来保存用户的选择
int select = 0;

// showMenu函数用来显示主界面
void showMenu();

// 功能实现1、添加联系人
void addPerson(struct Addressbooks* a);

// 功能实现2、显示联系人
void showPerson(struct Addressbooks* a);

// 功能实现3(1)、判断联系人是否存在
int isExist(struct Addressbooks* a, std::string name);

// 功能实现3(2)、删除联系人
void delPerson(struct Addressbooks* a, int isExist);

// 功能实现4、查找联系人
void findPerson(struct Addressbooks* a);

// 功能实现5、修改联系人
void modifyPerson(struct Addressbooks* a);

// 功能实现6、清空联系人
void clearPerson(struct Addressbooks* a);