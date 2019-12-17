
#include"Stuinfo.h"


void UI::Menu(){

	cout<<"******************************************"<<endl;
	cout<<"*******欢迎进入MiNi湘北高中管理系统*******"<<endl;
	cout<<"******************************************"<<endl;
	cout<<"*******1.查询信息*******"<<endl;
	cout<<"*******2.添加信息*******"<<endl;
	cout<<"*******3.修改信息*******"<<endl;
	cout<<"*******4.删除信息*******"<<endl;
	cout<<endl;
	cout<<"请输入您的选择：->      ";

}

void UI::Show(){

	for(int i=0;i<_stuinfo.size();++i){

	cout<<_stuinfo[i]<<endl;
	}


}
/////////////////////////////////////////////////////
bool UI::Search(){

	////mother fucker .... 记事本的换行读取格式问题
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
	//数据添加的时候没有在新的一行去添加
	
	string content;
	cout<<" 请输入您需要添加的完整信息：  "<<endl;
	
	//需要清空输入流
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
	cout<<"请输入需要修改的学生名字：  "<<endl;
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
	cout<<"请输入您修改后的完整数据： "<<endl;
	string part;
	string str="\n";
	getline(cin,str);
	getline(cin,part);     
	_stuinfo[i]=part;
	//将_stuinfo中的 内容覆盖原文件
	std::ofstream file(PATH.c_str(),ios::binary | ios::in );  //没有选择追加模式
	
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

	//删除指定数据项

	string name;
	string tmp;
	cout<<"请输入需要删除项的学生名字：  "<<endl;
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
	std::ofstream file(PATH.c_str(),ios::binary | ios::in );  //没有选择追加模式
    string content;
	for(int i=0;i<_stuinfo.size();++i){
		content=_stuinfo[i];
		//file.write(content.c_str(),content.size());
		file<<content<<endl;
	}

	file.close();
	return ;



}




//试一试是否不加app是覆盖模式
//记事本打开乱码
//为什么需要stu对象...
//监视窗口和实际输出结果不一致