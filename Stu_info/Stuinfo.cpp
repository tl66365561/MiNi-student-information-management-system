
#include"Stuinfo.h"


void UI::Menu(){

	cout<<"******************************************"<<endl;
	cout<<"*******��ӭ����MiNi�汱���й���ϵͳ*******"<<endl;
	cout<<"******************************************"<<endl;
	cout<<"*******1.��ѯ��Ϣ*******"<<endl;
	cout<<"*******2.�����Ϣ*******"<<endl;
	cout<<"*******3.�޸���Ϣ*******"<<endl;
	cout<<"*******4.ɾ����Ϣ*******"<<endl;
	cout<<endl;
	cout<<"����������ѡ��->      ";

}

void UI::Show(){

	for(int i=0;i<_stuinfo.size();++i){

	cout<<_stuinfo[i]<<endl;
	}


}
/////////////////////////////////////////////////////
bool UI::Search(){

	////mother fucker .... ���±��Ļ��ж�ȡ��ʽ����
	_stuinfo.clear();
	

	ifstream in(PATH.c_str());
	if(!in.is_open()){
		return false;

	}
	string content;
	while(getline(in,content)){             

		_stuinfo.push_back(content);

	}
	

	Show();

	in.close();
	return true;

}
////////////////////////////////////////////
bool UI::Add(){
	//������ӵ�ʱ��û�����µ�һ��ȥ���
	
	string content;
	cout<<" ����������Ҫ��ӵ�������Ϣ��  "<<endl;
	
	//��Ҫ���������
	string str="\n";
	getline(cin,str);
	
	getline(cin,content);              

	std::ofstream file(PATH.c_str(),ios::binary | ios::in | ios::app);
		if(!file.is_open()){
			return false;
		}

	//string s1="\n";
	//file<<s1;
	file<<content<<endl;
	//file.write(content.c_str(),content.size());
	file.close();
	return true;
	
}
//////////////////////////////////
void UI::Modify(){

	string name;
	string tmp;
	cout<<"��������Ҫ�޸ĵ�ѧ�����֣�  "<<endl;
	cin>>name;
	size_t len=name.size();
	int i=0;
	for(;i<_stuinfo.size();++i){
		
		tmp=_stuinfo[i].substr(0,len);
		if( strcmp(tmp.c_str(),name.c_str())==0 ){
			break;
		}
		else
			continue;

	}

	tmp=_stuinfo[i];
	cout<<"���������޸ĺ���������ݣ� "<<endl;
	string part;
	string str="\n";
	getline(cin,str);
	getline(cin,part);     
	_stuinfo[i]=part;
	//��_stuinfo�е� ���ݸ���ԭ�ļ�
	std::ofstream file(PATH.c_str(),ios::binary | ios::in );  //û��ѡ��׷��ģʽ
	
	string content;
	for(int i=0;i<_stuinfo.size();++i){
		content=_stuinfo[i];
		//file.write(content.c_str(),content.size());
		file<<content<<endl;
	}

	file.close();
	return ;
}



void UI::Delete(){

	//ɾ��ָ��������

	string name;
	string tmp;
	cout<<"��������Ҫɾ�����ѧ�����֣�  "<<endl;
	cin>>name;
	size_t len=name.size();
	int i=0;
	for(;i<_stuinfo.size();++i){

		tmp=_stuinfo[i].substr(0,len);
		if( strcmp(tmp.c_str(),name.c_str())==0 ){
			break;
		}
		else
			continue;

	}

	_stuinfo[i]=" NULL   (Deleted)";
	std::ofstream file(PATH.c_str(),ios::binary | ios::in );  //û��ѡ��׷��ģʽ
    string content;
	for(int i=0;i<_stuinfo.size();++i){
		content=_stuinfo[i];
		//file.write(content.c_str(),content.size());
		file<<content<<endl;
	}

	file.close();
	return ;



}




//��һ���Ƿ񲻼�app�Ǹ���ģʽ
//���±�������
//Ϊʲô��Ҫstu����...
//���Ӵ��ں�ʵ����������һ��