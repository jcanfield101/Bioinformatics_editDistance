/*******************************************************************
** Name:      Jonathan Canfield									  **
** Professor: Christa McCarthy									  **
** project:   Edit Distance Calculator Project					  **	
** Class:     CPSC 485											  **
** Due:       4/24/2012											  **
*******************************************************************/
#include "header.h";

int main(){

string v,w;
char run_again='y';
while (run_again== 'y') {
cout<<"enter V: ";
cin>>v;
cout<<"enter W: ";
cin>>w;
//making string input size dynamic
char *array_v=new char[v.size()+1];
char *array_w=new char[w.size()+1];
*array_v=string_to_array(v,array_v);
*array_w=string_to_array(w,array_w);
cout<<endl;

Matrix(array_v,array_w, v,w);
cout<<endl;
edit_Distance(v,w);
cout<<endl;
edit_alingment(v, w);
cout<<endl;
cout<<"run again? (y or n) ";
cin >> run_again;
}
system("pause");

	return 0;
}