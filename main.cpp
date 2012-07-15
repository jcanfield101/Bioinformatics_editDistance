#include "header.h";

int main(){

string v,w;

cout<<"enter V: ";
cin>>v;
cout<<"enter W: ";
cin>>w;

char *array_v=new char[v.size()+1];
char *array_w=new char[w.size()+1];
*array_v=string_to_array(v,array_v);
*array_w=string_to_array(w,array_w);
cout<<endl;

Matrix(array_v,array_w, v,w);
cout<<endl;
edit_Distance(v,w);
cout<<endl;
system("pause");

	return 0;
}