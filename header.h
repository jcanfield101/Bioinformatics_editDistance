#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

static int keepscore[100][100];	
static bool aling=true;

void edit_Distance(string v,string w);
void Matrix(char *array_v,char *array_w,string v,string w);
void print_top_row(char *array_v,char *array_w,string v,string w);
void edit_distance(string v,string w);
void edit_alingment(string v,string w);
char string_to_array(string input, char *a);
int find_longest(string v, string w);
int alings(string array_v, string array_w,int row, int count,int row_counter);
