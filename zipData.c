#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#include "zipData.h"

#define COUNTRY_CODE_LENGTH 3
#define POSTAL_CODE_LENGTH 21
#define PLACE_NAME_LENGTH 181
#define ADMIN_NAME1_LENGTH 101
#define ADMIN_CODE1_LENGTH 21
#define ADMIN_NAME2_LENGTH 101
#define ADMIN_CODE2_LENGTH 21
#define ADMIN_NAME3_LENGTH 101
#define ADMIN_CODE3_LENGTH 21
#define ACCURACY_LENGTH 2

void read_input_commands(char input_command_file[], char output_file[]){
  FILE* in = fopen(input_command_file, "r");
  FILE* out = fopen(output_file, "w");


  while(!feof(in)){
    char input[9];
    char data[101];
    char data_2[101];
    char data_file[101];
    fscanf(in, "%s", input);
    fgetc(in);
    if(feof(in)){
      break;
    }


    if(strcmp(input, "distance") ==  0){
      fscanf(in, "%s", data);
      fgetc(in);
      fscanf(in, "%s", data_2);
      fgetc(in);
    }else{
      fscanf(in, "%[^\n]", data);
      fgetc(in);
    }


    if(strcmp(input, "filename") == 0){
      fprintf(out, "%s ", input);
      fprintf(out, "%s\n", data);
      filename(data, out, data_file);
    }

    if(strcmp(input, "postal") == 0){
      fprintf(out, "%s ", input);
      fprintf(out, "%s\n", data);
      postal(data_file, out, data);
    }

    if(strcmp(input, "county") == 0){
      fprintf(out, "%s ", input);
      fprintf(out, "%s\n", data);
      county(data_file, out, data);
    }

    if(strcmp(input, "place") == 0){
      fprintf(out, "%s ", input);
      fprintf(out, "%s\n", data);
      place(data_file, out, data);
    }

    if(strcmp(input, "distance") == 0){
      fprintf(out, "%s ", input);
      fprintf(out, "%s\t", data);
      fprintf(out, "%s\n", data_2);
      distance(data_file, out, data, data_2);
    }
  }
  fclose(in);
  fclose(out);
}

void distance(char data_file[], FILE* out, char filter[], char filter_2[]){
  FILE* in = fopen(data_file, "r");
  double latitude_1 = -1;
  double longitude_1 = -1;
  double latitude_2;
  double longitude_2;
  int count_1 = 0;

    //checking file for post code 1
  while(!feof(in)){
    char country_code[COUNTRY_CODE_LENGTH] = "\0";
    char postal_code[POSTAL_CODE_LENGTH] = "\0";
    char name[PLACE_NAME_LENGTH] = "\0";
    char admin_name_1[ADMIN_NAME1_LENGTH] = "\0";
    char admin_code_1[ADMIN_CODE1_LENGTH] = "\0";
    char admin_name_2[ADMIN_NAME2_LENGTH] = "\0";
    char admin_code_2[ADMIN_CODE2_LENGTH] = "\0";
    char admin_name_3[ADMIN_NAME3_LENGTH] = "\0";
    char admin_code_3[ADMIN_CODE3_LENGTH] = "\0";
    double latitude = 0;
    double longitude = 0;
    int accuracy;
    read_record(in, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
    if((strcmp(postal_code, filter) == 0)){
      print_record(out, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
      latitude_1 = latitude;
      longitude_1 = longitude;
      count_1++;
      break;
    }
  }
  fclose(in);

  //rechecking file for post code 2
  FILE* in_2 = fopen(data_file, "r");
  int count_2 = 0;
  while(!feof(in)){
    char country_code[COUNTRY_CODE_LENGTH] = "\0";
    char postal_code[POSTAL_CODE_LENGTH] = "\0";
    char name[PLACE_NAME_LENGTH] = "\0";
    char admin_name_1[ADMIN_NAME1_LENGTH] = "\0";
    char admin_code_1[ADMIN_CODE1_LENGTH] = "\0";
    char admin_name_2[ADMIN_NAME2_LENGTH] = "\0";
    char admin_code_2[ADMIN_CODE2_LENGTH] = "\0";
    char admin_name_3[ADMIN_NAME3_LENGTH] = "\0";
    char admin_code_3[ADMIN_CODE3_LENGTH] = "\0";
    double latitude = 0;
    double longitude = 0;
    int accuracy;

    read_record(in, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
    if((strcmp(postal_code, filter_2) == 0)){// && (count_2 == 0)){

      print_record(out, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
      latitude_2 = latitude;
      longitude_2 = longitude;
      count_2++;
      break;
    }
  }
  fclose(in_2);
  //Checks if any post codes were not found
  if(count_1 == 0){
    fprintf(out, "Sorry, postal code %s was not found.\n", filter);
  }
  if(count_2 == 0){
    fprintf(out, "Sorry, postal code %s was not found.\n", filter_2);
  }

  //if both post codes found -- perform distance formula
  if(count_1 > 0 && count_2 > 0){

    double lat_1_rad = latitude_1 * M_PI/180;
    double lat_2_rad = latitude_2 * M_PI/180;
    double chng_lat = (latitude_2 - latitude_1) * M_PI/180;
    double chng_long = (longitude_2 - longitude_1) * M_PI/180;

    double a = sin(chng_lat/2) * sin(chng_lat/2) + cos(lat_1_rad) * cos(lat_2_rad) * sin(chng_long/2) * sin(chng_long/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c;

    fprintf(out, "\tDistance: %.6f km\n", d);
  }
}

void place(char data_file[], FILE* out, char filter[]){
  FILE* in = fopen(data_file, "r");
  int count = 0;
  while(!feof(in)){
    char country_code[COUNTRY_CODE_LENGTH] = "\0";
    char postal_code[POSTAL_CODE_LENGTH] = "\0";
    char name[PLACE_NAME_LENGTH] = "\0";
    char admin_name_1[ADMIN_NAME1_LENGTH] = "\0";
    char admin_code_1[ADMIN_CODE1_LENGTH] = "\0";
    char admin_name_2[ADMIN_NAME2_LENGTH] = "\0";
    char admin_code_2[ADMIN_CODE2_LENGTH] = "\0";
    char admin_name_3[ADMIN_NAME3_LENGTH] = "\0";
    char admin_code_3[ADMIN_CODE3_LENGTH] = "\0";
    double latitude = 0;
    double longitude = 0;
    int accuracy;
    read_record(in, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
    if(strstr(name, filter) != NULL){
      print_record(out, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
      count++;  
    }
  }
  if(count == 0){
    fprintf(out, "Sorry, place name %s was not found.\n", filter);
  }
  fclose(in);
}

void county(char data_file[], FILE* out, char filter[]){ 
  FILE* in = fopen(data_file, "r");
  int count = 0;
  while(!feof(in)){
  char country_code[COUNTRY_CODE_LENGTH] = "\0";
  char postal_code[POSTAL_CODE_LENGTH] = "\0";
  char name[PLACE_NAME_LENGTH] = "\0";
  char admin_name_1[ADMIN_NAME1_LENGTH] = "\0";
  char admin_code_1[ADMIN_CODE1_LENGTH] = "\0";
  char admin_name_2[ADMIN_NAME2_LENGTH] = "\0";
  char admin_code_2[ADMIN_CODE2_LENGTH] = "\0";
  char admin_name_3[ADMIN_NAME3_LENGTH] = "\0";
  char admin_code_3[ADMIN_CODE3_LENGTH] = "\0";
  double latitude = 0;
  double longitude = 0;
  int accuracy;
    read_record(in, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
    if(strstr(admin_name_2, filter) != NULL){
      print_record(out, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
      count++;  
    }
  }
  if(count == 0){
    fprintf(out, "Sorry, county %s was not found.\n", filter);
  }
  fclose(in);
}


void postal(char data_file[], FILE* out, char filter[]){  
  FILE* in = fopen(data_file, "r");
  int count = 0;
  while(!feof(in)){
    char country_code[COUNTRY_CODE_LENGTH] = "\0";
    char postal_code[POSTAL_CODE_LENGTH] = "\0";
    char name[PLACE_NAME_LENGTH] = "\0";
    char admin_name_1[ADMIN_NAME1_LENGTH] = "\0";
    char admin_code_1[ADMIN_CODE1_LENGTH] = "\0";
    char admin_name_2[ADMIN_NAME2_LENGTH] = "\0";
    char admin_code_2[ADMIN_CODE2_LENGTH] = "\0";
    char admin_name_3[ADMIN_NAME3_LENGTH] = "\0";
    char admin_code_3[ADMIN_CODE3_LENGTH] = "\0";
    double latitude = 0;
    double longitude = 0;
    int accuracy;
    read_record(in, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
    if(strcmp(postal_code, filter) == 0){
      print_record(out, country_code, postal_code, name, admin_name_1, admin_code_1, admin_name_2, admin_code_2, admin_name_3, admin_code_3, &latitude, &longitude, &accuracy);
      count++;
    }
  }
  if(count == 0){
    fprintf(out, "Sorry, postal code %s was not found.\n", filter);
  }
  fclose(in);
}

void filename(char command_data[], FILE* out, char data_file[]){
  strcpy(data_file, command_data);
  FILE* in = fopen(data_file, "r");
  //Checks if file can be opened
  if(in == NULL){
    fprintf(out, "Sorry filename %s was not found.\n", data_file);
    exit(0);
  }else{
    fclose(in);
  }
  
}

void read_record(FILE* in, char country_code[], char postal_code[], char name[], char admin_name_1[], char admin_code_1[], char admin_name_2[], char admin_code_2[], char admin_name_3[], char admin_code_3[], double* latitude, double* longitude, int* accuracy){
  fscanf(in, "%s", country_code);
  fgetc(in);
  fscanf(in, "%s", postal_code);
  fgetc(in);
  fscanf(in, "%[^\t]", name);
  fgetc(in);
  fscanf(in, "%[^\t]", admin_name_1);
  fgetc(in);
  fscanf(in, "%[^\t]", admin_code_1);
  fgetc(in);
  fscanf(in, "%[^\t]", admin_name_2);
  fgetc(in);
  fscanf(in, "%[^\t]", admin_code_2);
  fgetc(in);
  fscanf(in, "%[^\t]", admin_name_3);
  getc(in);
  fscanf(in, "%[^\t]", admin_code_3);
  fscanf(in, "%lf", latitude);
  fscanf(in, "%lf", longitude);
  fgetc(in);
  fscanf(in, "%d", accuracy);
  fgetc(in);
}
void print_record(FILE* out, char country_code[], char postal_code[], char name[], char admin_name_1[], char admin_code_1[], char admin_name_2[], char admin_code_2[], char admin_name_3[], char admin_code_3[], double* latitude, double* longitude, int* accuracy){
    
    fprintf(out, "\t%s\t", country_code);
    fprintf(out, "%s\t", postal_code);
    fprintf(out, "%s\t", name);
    fprintf(out, "%s\t", admin_name_1);
    fprintf(out, "%s\t", admin_code_1);
    fprintf(out, "%s\t", admin_name_2);
    fprintf(out, "%s\t", admin_code_2);
    fprintf(out, "%s\t", admin_name_3);
    fprintf(out, "%s\t", admin_code_3);
    fprintf(out, "%.6f\t", *latitude);
    fprintf(out, "%.6f\t", *longitude);
    fprintf(out, "%d", *accuracy);
    fprintf(out, "\n");
}


