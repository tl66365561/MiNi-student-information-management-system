
#include "Stuinfo.h"




int main(){
	

	UI u1;
	int input;
	
do{
	u1.Menu();	
	cin>>input;
	
	switch(input){	 
	case 1: u1.Search(); break;                      //查   
	case 2: u1.Add();break;                          //添
	case 3: u1.Modify();break;                       //改
	case 4: u1.Delete();break;                       //删
 	default:
		cout<<"请输入正确的选择： "<<endl;
		break;
	}
	
	cout<<endl<<endl;
	cout<<"温馨提示：输入非0值可以继续进行操作... ..."<<endl;
	cout<<"请重新输入您的选择:   ";
	cin>>input;
}while(input!=0);


	system("pause");

	return 0;
}