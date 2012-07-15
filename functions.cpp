#include "header.h";
/******************************************************************************
** Checks for alignment score only in the diagonal. When a specific          **
** array location counter comes to the position where a check needs for      **
** be made for the V and W this function is called. If there is a mismatch   **
** then a score of +1 is given to a global counter. If there is a match then **
** the score is the same as the pervious alignment                           **
******************************************************************************/
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
/*****************************************************************
** Simply finds which input for V and W is the largest (length) **
*****************************************************************/
int find_longest(string v, string w){
	int longest_string=0;
 
	if (v.length()< w.length()){
		longest_string=w.length();}
	else 
		longest_string=v.length();
 return longest_string;
}

/********************************************************************************
** The big function.  Takes in the array of V and W. If W is shorter a         **
** bool is set for the special alignment situation the same goes  V.           ** 
** A global counter is used for the output of the score. First the top         **
** row is printed with the scores.  If V and W are of the same length then     **
** then scores are printed down increasing in value until the alignment        **
**check needs to be made. Once the alignment check has been completed the      **
** scores decrease by 1 from the score above the location. If the inputs are   **
** not of the same length, then once V or W which ever if shorter ends the     ** 
** alignment score increase by 1 from either the row or col depending with     **
** V or W is shorter.                                                          **
********************************************************************************/
void Matrix(char *array_v,char *array_w,string v,string w){
	// If I gave myself more time I'm sure I could cut this function in half. 
	int length_v=v.length();
    int length_w=w.length();
	int row_counter=0;	
    int count=0;
    int longest_string=0;	
	int row=0;
	int end_col_counter=0;
	int test_count=0;
	int *location = new int [longest_string];	
	int end_row_counter=0;
	bool count_arc=true;	
	bool end_aling_col=true;
	bool print_end_col=true;
	bool print_end_row=true;
	bool f=false;
	bool end_aling_row=true;	
	longest_string=find_longest(v,w);
		
	
	print_top_row(array_v,array_w, v, w);	
	cout<<"|   |";	
	if (length_v> length_w){
		test_count= length_w;		
	    print_end_row=false; } 		
	
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
		print_end_col= true;
		if (row > test_count+1 && !print_end_row){
		    end_aling_col=true;
			end_aling_row=true;	
			if (j< test_count-1){			
				count = keepscore[row-1][row_counter]+1;}
			if (j==test_count){
				print_end_col= false;
				count = keepscore[row-1][row_counter]+1;
				cout<<"*"<<count<<" |";}	

		}
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
		if (row!=1&&end_aling_col&&end_aling_row){		
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

/*************************************************************************
** The little buddy is used to print the table for the program.         **
** It’s crazy inefficient at (O)^4                                      **
*************************************************************************/
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

/********************************************************
** Takes the input and converts it to a array and also ** 
** makes all the chars lower case.                     **
********************************************************/
char string_to_array(string input, char *a){
	a[input.size()]=0;
    memcpy(a,input.c_str(),input.size());
	for(int i = 0; a[i] != '\0'; i++){
		a[i] = tolower(a[i]);}
 return *a;
}

/************************************************************
** Finds and prints and edit distance. If v and w are      **
** of different length then the difference will be a score **
**then if there is a mismatch then that will be +1 one.    **  
************************************************************/
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
	
    cout<<endl<<"Edit Distance "<<diff;

}
/************************************
** Prints out the alingment        **
************************************/
void edit_alingment(string v,string w){	
	int diff=0;
	bool length=true;
	int length_v=v.length();
	int length_w=w.length();
	
	cout<<"Alingment"<<endl;
	
	if (length_v > length_w){
		diff= length_v - length_w;}
	if (length_v < length_w){
		diff= length_w - length_v;
	    length=false;}
	  cout<< "V: ";
	for (int i=0; i !=length_v; i++){
		cout<<v[i];}
	if (!length){
		 for (int j=0; j != diff; j++){
			 cout<<"_";}}
	cout<<endl;
	cout<< "W: ";	
   for (int s=0; s !=length_w; s++){		
		cout<<w[s];}
	 if (length){
		 for (int p=0; p != diff; p++){
			  cout<<"_";}}

	}

