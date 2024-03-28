#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>


void read_record(FILE* in, char country_code[], char postal_code[], char name[],
 char admin_name_1[], char admin_code_1[], char admin_name_2[], char admin_code_2[],
  char admin_name_3[], char admin_code_3[], double* latitude, double* longitude, int* accuracy);

void print_record(FILE* out, char country_code[], char postal_code[], char name[],
 char admin_name_1[], char admin_code_1[], char admin_name_2[], char admin_code_2[],
  char admin_name_3[], char admin_code_3[], double* latitude, double* longitude, int* accuracy);

void read_input_commands(char input_command_file[], char output_file[]);

void filename(char command_data[], FILE* out, char data_file[]);

void postal(char data_file[], FILE* out, char filter[]);

void county(char data_file[], FILE* out, char filter[]);

void place(char data_file[], FILE* out, char filter[]);

void distance(char data_file[], FILE* out, char filter[], char filter_2[]);