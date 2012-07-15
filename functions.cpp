#include "header.h";

int alings(string array_v, string array_w,int row, int count,int row_counter){
	
	if (array_v[row-2] != array_w[row_counter-1]){					
	    count= keepscore[row-1][row_counter-1]+1;
		keepscore[row][row_counter]=+1;
		cout<<"*"<<count<<" |";	
		aling=false;}
	if (array_v[row-2] == array_w[row_counter-1]){				
		count= keepscore[row-1][row_counter-1];
		cout<<"*"<<count<<" |";	
		aling=false; }	
	
	return count;
}


int find_longest(string v, string w){
	int longest_string=0;
 
	if (v.length()< w.length()){
		longest_string=w.length();}
	else 
		longest_string=v.length();
 return longest_string;
}


void Matrix(char *array_v,char *array_w,string v,string w){
	int length_v=v.length();
    int length_w=w.length();
	int row_counter=0;	
    int count=0;
    int longest_string=0;	
	int row=0;
	bool count_arc=true;	
	longest_string=find_longest(v,w);
	int *location = new int [longest_string];	
	int end_row_counter=0;
	bool end_aling_col=true;
	bool print_end_col=true;
	bool f=false;
	
	print_top_row(array_v,array_w, v, w);	
	cout<<"|   |";	
	for(int i=0; i!=length_v+1; i++){	
		end_row_counter++;
		if (end_row_counter-1 == length_v){
			  end_aling_col=false; }
		row++;
		count=0;
		row_counter=0;
		count_arc=true;
	for (int j=0;j < length_w+1;j++){
		aling= true;
		if(!end_aling_col){
			if (j< end_row_counter-1){		
				count = keepscore[row-1][row_counter]+1;}
			if (j> end_row_counter-2&&!f){
				print_end_col= false;
				count=alings(array_v,array_w,row,count,row_counter);				  
				  f=true;}

			if (j> end_row_counter-1){
				print_end_col= false;
				count = keepscore[row][row_counter-1]+1;
				cout<<"*"<<count<<" |";}
		}
		if (row!=1&&end_aling_col){		
			if (count_arc && row-1!=j){
				count = keepscore[row-1][row_counter]+1;}
			if (!count_arc && row-1!=j){
				count = keepscore[row-1][row_counter]-1;}
			if (row-1==j&&row>1){
				count_arc=false;			
			  count=alings(array_v,array_w,row,count,row_counter);}
	     	}
		 if (aling&&print_end_col){
			 cout<<" "<<count<<" |";}

		 keepscore[row][row_counter]=count;
		 count++;
		 row_counter++;
	}
	cout<<endl;	
	if (i!=length_v){
		cout<<"| "<<array_v[i]<<" |";} 	
    }

}

void print_top_row(char *array_v,char *array_w,string v,string w){
	int length_v=v.length();
    int length_w=w.length();	
	bool print_w=true;

		for (int i=0; i < length_w; i++){
			 if (print_w){
				 for (int i=0; i!= length_w; i++){				
					 cout<<"-------";}
				   cout<<endl;
				   cout<<"|   | "<<"  | ";
				 for (int j=0; j!= length_w; j++){				
					 cout<<array_w[j]<< " | ";}				
				  cout<<endl;
			     for (int p=0; p!= length_w; p++){		
					 cout<< "-------";}
				print_w=false;
			    }
			 }
		cout<<endl;
}


char string_to_array(string input, char *a){
	a[input.size()]=0;
    memcpy(a,input.c_str(),input.size());
	for(int i = 0; a[i] != '\0'; i++){
		a[i] = tolower(a[i]);}
 return *a;
}


void edit_Distance(string v,string w){
	int count=0;
	int diff=0;
	int length_v=v.length();
	int length_w=w.length();

	if (length_v > length_w)
		diff= length_v - length_w;
	else
	diff= length_w - length_v;

    int longest_string=find_longest(v,w)-diff;

	while (count !=longest_string){
		   if (v[count]!=w[count]){
		   diff++;}
	   count++;
     }

    cout<<endl<<"edit distance "<<diff;

}