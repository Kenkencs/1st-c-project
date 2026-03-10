//
//  main.cpp
//  addressbook
//
//  Created by 陈宇权 on 2026/3/10.
//


/*#include <iostream>
#include <string>
using namespace std;
//定义最大人数
#define MAX 1000
//开始构造结构体，构建联系人结构体
struct person{
    string m_name;
    int m_sex ;
    int m_age;
    string m_phone;
    string m_address;
};
//构造通讯录结构体
struct addressbook{
    struct person personarr[MAX];//通讯录里面人的数组
    int m_Size = 0;//记录里面有多少人
};


//显示界面用void showMenu
//在主函数显示
//菜单
void showMenu(){
    cout<<"**********************"<<endl;
    cout<<"***** 1.添加联系人 *****"<<endl;
    cout<<"***** 2.显示联系人 *****"<<endl;
    cout<<"***** 3.删除联系人 *****"<<endl;
    cout<<"***** 4.查找联系人 *****"<<endl;
    cout<<"***** 5.修改联系人 *****"<<endl;
    cout<<"***** 6.清空联系人 *****"<<endl;
    cout<<"***** 0.退出通讯录 *****"<<endl;
    cout<<"**********************"<<endl;
    
    
}

//添加联系人
void addperson(addressbook * abs){
    if(abs->m_Size == MAX){
        cout<<"通讯录已经满,无法添加!"<<endl;
        return;
    }
    //判断结束，添加联系人
    else{
        //名字
        string name;
        cout<<"请输入姓名： "<<endl;
        cin>>name;
        abs->personarr[abs->m_Size].m_name = name ;
        
        //性别
        int sex = 0;
        cout<<"请输入性别 : "<<endl;
        cout<<"--1.男--"<<endl;
        cout<<"--2.女--"<<endl;
        cout<<"--3.NA--"<<endl;
        //设置死循环，当123，输入，否则一直死循环
        while (true){
            cin>>sex;
            if(sex<1 || sex>3){
                cout<<"请重新输入!!!!!"<<endl;
            }
            else if(sex == 1||sex==2||sex==3){
                abs->personarr[abs->m_Size].m_sex = sex ;
                break;
            }
        }
        
        //年龄, 思路和上面一样
        int age = 0;
        cout<<"请输入年龄："<<endl;
        
        while (true){
            cin >> age;
            if(age<=0||age>100){
                cout<<"请重新输入！！！！"<<endl;
            }
            else{
                abs->personarr[abs->m_Size].m_age = age ;
                break;
            }
        }
        
        //电话
        string phone;
        cout<<"请输入联系电话："<<endl;
        cin>>phone;
        abs->personarr[abs->m_Size].m_phone = phone;
        
        //地址
        string address;
        cout<<"请输入联系地址："<<endl;
        cin>>address;
        abs->personarr[abs->m_Size].m_address = address;
        
        abs->m_Size++ ;
        cout<<"添加成功！！！！！！！"<<endl;
        
        cout << "请按回车键继续...";
        
        //mac 特有特性
        cin.clear(); // 清除可能存在的输入错误标志
        cin.ignore(10000, '\n'); // 如果你前面用过 cin >> 输入过东西，把这行取消注释！(重要防坑)
        cin.get();   // 捕获用户的回车按键，起到暂停作用

            // 【Mac 完美替代 system("cls") 的写法】
        system("clear");
        //system("cls");
    }
}
//显示联系人
void showPerson(addressbook * abs){
    //判断是否为0，否则显示联系人信息
    if(abs->m_Size==0){
        cout<<"当前记录为空"<<endl;
    }
    else{
        for(int i = 0; i<abs->m_Size;i++){
            cout<<"姓名"<<abs->personarr[i].m_name<<"\t";
            cout<<"性别"<<(abs->personarr[i].m_sex==1?"男" : "女")<<"\t";
            cout<<"年龄"<<abs->personarr[i].m_age<<"\t";
            cout<<"电话"<<abs->personarr[i].m_phone<<"\t";
            cout<<"地址"<<abs->personarr[i].m_address<<endl;
            
        }
    }
    cin.clear(); // 清除可能存在的输入错误标志
    cin.ignore(10000, '\n'); // 如果你前面用过 cin >> 输入过东西，把这行取消注释！(重要防坑)
    cin.get();   // 捕获用户的回车按键，起到暂停作用

        // 【Mac 完美替代 system("cls") 的写法】
    system("clear");
    //system("cls");
}

//检查是否存在，存在中啊对应位置，不存在，返回-1
//传入地址，找人，对比名字
int isExit (addressbook *abs,string name){
    for(int i=0;i<abs->m_Size;i++){
        if(abs->personarr[i].m_name==name){
            return i;
        }
    }
    return -1 ;
}

void deletePerson(addressbook *abs){
    cout<<"请输入你想删除的人"<<endl;
    string name;
    cin>>name;
    //return == -1 : no
    //return != -1 : yes
    int ret = isExit(abs, name);
    if(ret != -1){
        //查到人删掉,洛基删除
        for(int i = ret;i<abs->m_Size-1;i++){
            abs->personarr[i]=abs->personarr[i+1];
        }
        //更新通讯录大小
        abs->m_Size--;
        cout<<"删除成功!"<<endl;
    }
    else{
        cout<<"查无此人"<<endl;
    }
    cin.clear(); // 清除可能存在的输入错误标志
    cin.ignore(10000, '\n'); // 如果你前面用过 cin >> 输入过东西，把这行取消注释！(重要防坑)
    cin.get();   // 捕获用户的回车按键，起到暂停作用

        // 【Mac 完美替代 system("cls") 的写法】
    system("clear");
    //system("cls");
}

void findPerson(addressbook *abs){
    cout<<"请输入想查找的联系人"<<endl;
    string name;
    cin>>name;
    
    //判断是否存在
    int result = isExit(abs, name);
    if (result!=-1){
        cout<<"姓名"<<abs->personarr[result].m_name<<"\t";
        cout<<"性别"<<abs->personarr[result].m_sex<<"\t";
        cout<<"年龄"<<abs->personarr[result].m_age<<"\t";
        cout<<"电话"<<abs->personarr[result].m_phone<<"\t";
        cout<<"住址"<<abs->personarr[result].m_address<<endl;
    }
    else{
        cout<<"查无此人"<<endl;
    }
    cin.clear(); // 清除可能存在的输入错误标志
    cin.ignore(10000, '\n'); // 如果你前面用过 cin >> 输入过东西，把这行取消注释！(重要防坑)
    cin.get();   // 捕获用户的回车按键，起到暂停作用

    // 【Mac 完美替代 system("cls") 的写法】
    system("clear");
    //system("cls");
}

void modifyPerson(addressbook *abs){
    cout<<"请输入你想修改的联系人"<<endl;
    string name;
    cin>>name;
    int ret = isExit(abs,name);
    
    if(ret!=-1){
        //name
        string name;
        cout<<"请输入姓名: "<<endl;
        cin>>name;
        abs->personarr[ret].m_name = name;
        
        //sex
        int sex=0;
        cout<<"请输入姓别: "<<endl;
        cout<<"--1--:男"<<endl;
        cout<<"--2--:女"<<endl;
        cout<<"--3--:NA"<<endl;
        while (true) {
            cin>>sex;
            if(sex==1||sex==2||sex==3){
                abs->personarr[ret].m_sex = sex;
                break;
            }
            cout<<"请重新输入！！"<<endl;
        }
        
        
        int age=0;
        while(true){
            cout<<"请输入年龄: "<<endl;
            cin>>age;
            if(age>=0){
                abs->personarr[ret].m_age = age;
                break;
            }
            cout<<"请重新输入！！"<<endl;
            
        }

        string phone;
        cout<<"请输入电话: "<<endl;
        cin>>phone;
        abs->personarr[ret].m_phone = phone;
        
        string address;
        cout<<"请输入地址: "<<endl;
        cin>>address;
        abs->personarr[ret].m_address = address;
        
        cout<<"修改成功～"<<endl;
    }
    else{
        cout<<"查无此人"<<endl;
    }
    cin.clear(); // 清除可能存在的输入错误标志
    cin.ignore(10000, '\n'); // 如果你前面用过 cin >> 输入过东西，把这行取消注释！(重要防坑)
    cin.get();   // 捕获用户的回车按键，起到暂停作用

    // 【Mac 完美替代 system("cls") 的写法】
    system("clear");
    //system("cls");
    
}

void clearPerson(addressbook * abs){
    abs->m_Size = 0; // 逻辑清空
    cout<<"通讯录已清空"<<endl;
    cin.clear(); // 清除可能存在的输入错误标志
    cin.ignore(10000, '\n'); // 如果你前面用过 cin >> 输入过东西，把这行取消注释！(重要防坑)
    cin.get();   // 捕获用户的回车按键，起到暂停作用

    // 【Mac 完美替代 system("cls") 的写法】
    system("clear");
    //system("cls");
}

int main(){
    
    //初始化，当前人员个数
    struct addressbook abs;
    abs.m_Size = 0;
    
    //创建用户变量
    int select = 0;
    
    //设置死循环，导致一直能显示
    while(true){
        showMenu();
        cin>>select;
        switch(select){
                //添加
            case 1:
                addperson(&abs);
                break;//利用地址传递，才可以改变是实参
                //显示
            case 2:
                showPerson(&abs);
                break;
                //删除
            case 3:
                deletePerson(&abs);
                break;
                //查找
            case 4:
                findPerson(&abs);
                break;
                //修改
            case 5:
                modifyPerson(&abs);
                break;
                //清空
            case 6:
                clearPerson(&abs);
                break;
                //退出
            case 0:
                cout<<"welcome next time"<<endl;
                //system("pause");
                return 0;
                break;
            default:
                break;
        }
    }
}*/

#include <iostream>
#include <string>
#include <limits> // 包含该库，用于处理输入缓冲区清空

using namespace std;

// 定义最大人数
#define MAX 1000

// 开始构造结构体，构建联系人结构体
struct Person {
    string m_name;
    int m_sex; // 1:男 2:女 3:NA
    int m_age;
    string m_phone;
    string m_address;
};

// 构造通讯录结构体
struct AddressBook {
    struct Person personArr[MAX]; // 通讯录里面人的数组
    int m_Size = 0; // 记录里面有多少人
};

// 【核心优化】封装清屏与暂停，保留 Mac 特性
void clearScreen() {
    cout << "请按回车键继续...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的残留数据
    cin.get();
    system("clear"); // 【Mac 完美替代 system("cls") 的写法】
}

// 【核心优化】专门用于处理数字输入的函数，防止死循环
void inputInt(int &val, int min, int max) {
    while (true) {
        if (cin >> val && val >= min && val <= max) break;
        cout << "请重新输入!!!!!" << endl;
        cin.clear(); // 清除可能存在的输入错误标志
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// 显示菜单界面
void showMenu() {
    cout << "**********************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "**********************" << endl;
}

// 添加联系人
void addPerson(AddressBook *abs) {
    if (abs->m_Size == MAX) {
        cout << "通讯录已经满,无法添加!" << endl;
        return;
    }
    // 添加联系人
    cout << "请输入姓名： " << endl;
    cin >> abs->personArr[abs->m_Size].m_name;
    
    cout << "请输入性别 (1.男 2.女 3.NA): " << endl;
    inputInt(abs->personArr[abs->m_Size].m_sex, 1, 3);
    
    cout << "请输入年龄：" << endl;
    inputInt(abs->personArr[abs->m_Size].m_age, 0, 100);
    
    cout << "请输入联系电话：" << endl;
    cin >> abs->personArr[abs->m_Size].m_phone;
    
    cout << "请输入联系地址：" << endl;
    cin >> abs->personArr[abs->m_Size].m_address;
    
    abs->m_Size++;
    cout << "添加成功！！！！!!!" << endl;
    clearScreen();
}

// 显示联系人
void showPerson(AddressBook *abs) {
    if (abs->m_Size == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "姓名:" << abs->personArr[i].m_name << "\t";
            cout << "性别:" << (abs->personArr[i].m_sex == 1 ? "男" : "女") << "\t";
            cout << "年龄:" << abs->personArr[i].m_age << "\t";
            cout << "电话:" << abs->personArr[i].m_phone << "\t";
            cout << "地址:" << abs->personArr[i].m_address << endl;
        }
    }
    clearScreen();
}

// 检查是否存在，存在返回对应位置，不存在返回-1
int isExit(AddressBook *abs, string name) {
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArr[i].m_name == name) return i;
    }
    return -1;
}

// 删除联系人
void deletePerson(AddressBook *abs) {
    cout << "请输入你想删除的人：" << endl;
    string name; cin >> name;
    int ret = isExit(abs, name);
    if (ret != -1) {
        for (int i = ret; i < abs->m_Size - 1; i++) {
            abs->personArr[i] = abs->personArr[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功!" << endl;
    } else {
        cout << "查无此人" << endl;
    }
    clearScreen();
}

// 查找联系人
void findPerson(AddressBook *abs) {
    cout << "请输入想查找的联系人：" << endl;
    string name; cin >> name;
    int result = isExit(abs, name);
    if (result != -1) {
        cout << "姓名:" << abs->personArr[result].m_name << "\t";
        cout << "性别:" << abs->personArr[result].m_sex << "\t";
        cout << "年龄:" << abs->personArr[result].m_age << "\t";
        cout << "电话:" << abs->personArr[result].m_phone << "\t";
        cout << "住址:" << abs->personArr[result].m_address << endl;
    } else {
        cout << "查无此人" << endl;
    }
    clearScreen();
}

// 修改联系人
void modifyPerson(AddressBook *abs) {
    cout << "请输入你想修改的联系人：" << endl;
    string name; cin >> name;
    int ret = isExit(abs, name);
    if (ret != -1) {
        cout << "请输入姓名: " << endl; cin >> abs->personArr[ret].m_name;
        cout << "请输入性别(1.男 2.女 3.NA): " << endl; inputInt(abs->personArr[ret].m_sex, 1, 3);
        cout << "请输入年龄: " << endl; inputInt(abs->personArr[ret].m_age, 0, 100);
        cout << "请输入电话: " << endl; cin >> abs->personArr[ret].m_phone;
        cout << "请输入地址: " << endl; cin >> abs->personArr[ret].m_address;
        cout << "修改成功～" << endl;
    } else {
        cout << "查无此人" << endl;
    }
    clearScreen();
}

// 清空联系人
void clearPerson(AddressBook *abs) {
    abs->m_Size = 0; // 逻辑清空
    cout << "通讯录已清空" << endl;
    clearScreen();
}

int main() {
    AddressBook abs;
    abs.m_Size = 0;
    int select = 0;

    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 1: addPerson(&abs); break;
            case 2: showPerson(&abs); break;
            case 3: deletePerson(&abs); break;
            case 4: findPerson(&abs); break;
            case 5: modifyPerson(&abs); break;
            case 6: clearPerson(&abs); break;
            case 0: cout << "欢迎下次使用" << endl; return 0;
            default: system("clear"); break;
        }
    }
}
