
#include "Stuinfo.h"




int main(){
	

	UI u1;
	int input;
	
do{
	u1.Menu();	
	cin>>input;
	
	switch(input){	 
	case 1: u1.Search(); break;                      //��   
	case 2: u1.Add();break;                          //��
	case 3: u1.Modify();break;                       //��
	case 4: u1.Delete();break;                       //ɾ
 	default:
		cout<<"��������ȷ��ѡ�� "<<endl;
		break;
	}
	
	cout<<endl<<endl;
	cout<<"��ܰ��ʾ�������0ֵ���Լ������в���... ..."<<endl;
	cout<<"��������������ѡ��:   ";
	cin>>input;
}while(input!=0);


	system("pause");

	return 0;
}