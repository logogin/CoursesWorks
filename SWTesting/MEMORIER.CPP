#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <fstream.h>
#include <iomanip.h>
//#include <iostream.h>

#define mem_error cerr << "Cannot alocate memory !!! "

ifstream input_file; //stream of input file
fstream temp_file;   //stream of temp file
fstream data_file;   //stream of data file

const char *base_types[9] = {"char",
                             "int",
                             "enum",
                             "float",
                             "long double",
                             "long",
                             "double",
                             "OneDim",
                             "TwoDim"};

const unsigned char base_types_size[7] = {/*sizeof(char),*/ 1,
                                          /*sizeof(int),*/ 2,
                                          /*sizeof(enum),*/ 2,
                                          /*sizeof(float),*/ 4,
                                          /*sizeof(long double)*/ 10,
                                          /*sizeof(long),*/ 4,
                                          /*sizeof(double)*/ 8};

unsigned char defines_num;   //number of defined constants
unsigned char types_num = 7; //nuber of types in file

/*******Flags********/
bool free_type_data = false;
bool free_const_array = false;
bool free_values_array = false;
bool close_temp_file = false;

char **const_array; //names of defined constants
char *type_data;    //data of type with variables

unsigned int *values_array;   //values of defined constants
unsigned int arraies_size[2]; //sizes of arraies

struct types
{
    char *name;
    size_t size;
    unsigned long number;
} * types_of_file; //struct with sizes of types

/******** Writing base types to the types_of_file *******/
void write_base_types()
{
    types_of_file = (types *)realloc(types_of_file,
                                     sizeof(types) * types_num);

    if (types_of_file == NULL)
    {
        mem_error << " (types_of file)" << endl;
        getch();
        exit(1);
    }

    for (int i = 0; i < types_num; i++)
    {
        types_of_file[i].name = (char *)malloc((strlen(base_types[i]) + 1) * sizeof(char));
        if (types_of_file[i].name == NULL)
        {
            mem_error << " (types_of_file[i].name)" << endl;
            getch();
            exit(1);
        }

        strcpy(types_of_file[i].name, base_types[i]);
        types_of_file[i].size = base_types_size[i];
        types_of_file[i].number = 0;
    }
}

/****** Reading from the position in the file *********/
/****** to the terminator character           *********/
void read_statement(const char terminator)
{
    unsigned int len = 0;
    char ch;

    type_data = (char *)malloc(sizeof(char));
    do
    {
        if (close_temp_file)
            ch = data_file.get();
        else
            ch = temp_file.get();

        len++;
        type_data = (char *)realloc(type_data, (len + 1) * sizeof(char));
        if (type_data == NULL)
        {
            mem_error << " (type_data)" << endl;
            getch();
            exit(1);
        }

        free_type_data = true;
        type_data[len - 1] = ch;
    } while ((ch != terminator) && !(close_temp_file ? data_file.eof() : temp_file.eof()));
    type_data[len] = '\x0';
}

/******* Defining variables in the type_data *******/
unsigned int read_variables(char *dest, const int type_name_len,
                            const unsigned int type_num)
{
    char *presize = NULL;
    int i = type_name_len;
    unsigned int var_num = 1;
    unsigned int array_size = 1;
    unsigned int twodim;
    bool flag = false;
    bool free_flag = false;

    strnset(dest, ' ', i);
    if (strchr(dest, '(') != NULL)
        dest = strchr(dest, '{') + 1;

    while (dest[i] != ';')
    {
        if (dest[i] == ',')
            var_num++;

        if (dest[i] != ' ')
            flag = true;

        if ((dest[i] == '[') && (dest[i - 1] == ']'))
        {
            twodim = array_size;
            if (type_num)
                arraies_size[0] -=
                    (array_size * types_of_file[type_num - 1].size);
            else
                var_num -= array_size;
        }
        else
            twodim = 1;

        if ((dest[i] == '[') && (dest[i + 1] == ']'))
        {
            var_num--;
            array_size = 1;
            if (type_num != 1)
            {
                while (dest[i] != '}')
                {
                    if (dest[i] == ',')
                        array_size++;
                    i++;
                }
            }
            else
            {
                while (dest[i++] != '"')
                    ;
                while (dest[i] != '"')
                {
                    array_size++;
                    i++;
                }
            }
            if (type_num)
                arraies_size[0] +=
                    (array_size * types_of_file[type_num - 1].size);
            else
                var_num += array_size;
        }
        if (dest[i] == '[')
        {
            int begin = 0;
            if (twodim == 1)
                var_num--;

            while (dest[i] != ']')
            {
                begin++;
                presize = (char *)realloc(presize, (begin + 1) * sizeof(char));
                if (presize == NULL)
                {
                    mem_error << " (presize)" << endl;
                    getch();
                    exit(1);
                }

                free_flag = true;
                i++;
                presize[begin - 1] = dest[i];
                if (dest[i + 1] == ']')
                    i++;
            }
            presize[begin] = '\x0';
            if (!(array_size = atoi(presize)))
                for (int j = 0; j < defines_num; j++)
                    if (!strcmp(presize, const_array[j]))
                        array_size = values_array[j];

            array_size = array_size * twodim;
            if (type_num)
                arraies_size[twodim > 1 ? 1 : 0] +=
                    (array_size * types_of_file[type_num - 1].size);
            else
                var_num += array_size;
        }
        else
            i++;
    }
    if (free_flag)
        free(presize);
    return (!flag ? 0 : var_num);
}

/******* Defining types in the data_type *********/
unsigned int define_types(const bool multitype)
{
    int i = 0;
    unsigned int type_size = 0;
    unsigned int result = 0;
    char *next_type = NULL;
    bool flag = true;
    bool type = false;

    while (flag && i < types_num)
    {
        if (((next_type = strstr(type_data,
                                 types_of_file[i].name)) != NULL) &&
            (next_type[strlen(types_of_file[i].name)] == ' '))
        {
            type = true;
            if (!multitype)
                flag = false;

            if (multitype)
                result += read_variables(next_type,
                                         strlen(types_of_file[i].name), 0);
            else
                result += read_variables(next_type,
                                         strlen(types_of_file[i].name), i + 1);
        }
        else
            type = false;
        if (multitype)
            type_size += (result * types_of_file[i].size);
        else
            type_size += result;
        result = 0;
        if (!type)
            i++;
    }
    return type_size;
}

/******** Reading defined constants **********/
void read_defines()
{
    char st[80];
    unsigned int value;

    input_file.clear();
    input_file.seekg(0);
    while (input_file >> st)
    {
        if (!strcmp(st, "#define"))
        {
            defines_num++;
            const_array = (char **)realloc(const_array, defines_num * sizeof(char *));
            if (const_array == NULL)
            {
                mem_error << " (const_array)" << endl;
                getch();
                exit(1);
            }

            free_const_array = true;
            input_file >> st;
            input_file >> value;
            values_array = (unsigned int *)realloc(values_array,
                                                   defines_num * sizeof(unsigned int));

            if (values_array == NULL)
            {
                mem_error << " (values_array)" << endl;
                getch();
                exit(1);
            }
            free_values_array = true;
            const_array[defines_num - 1] = (char *)malloc((strlen(st) + 1) * sizeof(char));

            if (const_array[defines_num - 1] == NULL)
            {
                mem_error << " (const_array[defines_num-1])" << endl;
                getch();
                exit(1);
            }

            strcpy(const_array[defines_num - 1], st);
            values_array[defines_num - 1] = value;
        }
    }
    input_file.close();
}

/******** Reading stuctures ***********/
void read_structs()
{
    char st[80];
    char *bracket = NULL;

    temp_file.open("temp.cpp", ios::in);
    if (!temp_file)
    {
        cerr << "Cannot open file TEMP.CPP !!!" << endl;
        getch();
        exit(1);
    }

    data_file.open("temp.dat", ios::out);
    if (!data_file)
    {
        cerr << "Cannot open file TEMP.DAT !!!" << endl;
        getch();
        exit(1);
    }

    while (temp_file >> st)
    {
        if (!strcmp(st, "struct"))
        {
            temp_file >> st;
            read_statement('}');
            if ((bracket = strchr(st, '{')) != NULL)
                *bracket = '\x0';

            types_of_file = (types *)realloc(types_of_file,
                                             (types_num + 1) * sizeof(types));

            if (types_of_file == NULL)
            {
                mem_error << " (types_of_file)" << endl;
                getch();
                exit(1);
            }

            types_of_file[types_num].name = (char *)malloc((strlen(st) + 1) * sizeof(char));
            if (types_of_file[types_num].name == NULL)
            {
                mem_error << " (types_of_file[types_num].name)" << endl;
                getch();
                exit(1);
            }

            strcpy(types_of_file[types_num].name, st);

            types_of_file[types_num].size = define_types(true);
            types_of_file[types_num].number = 0;
            types_num++;
        }
        data_file << st << " ";
    }
    temp_file.close();
    close_temp_file = true;
    data_file.close();
}

/******* Reading types from the file to the type_data ******/
void read_types()
{
    char st[80];
    char type[80];
    char test[80];
    long location;
    bool flag;

    data_file.open("temp.dat", ios::in);
    if (!data_file)
    {
        cerr << "Cannot open file TEMP.DAT !!!" << endl;
        getch();
        exit(1);
    }

    while (data_file >> st)
    {
        flag = false;
        int i = 0;
        location = data_file.tellg();
        data_file >> test;
        data_file.seekg(location);
        if (strchr(test, '(') != NULL)
        {
            read_statement(')');
            data_file >> st;
        }

        while ((!flag) && i < types_num)
        {
            if (!strcmp(st, types_of_file[i].name))
            {
                flag = true;
                read_statement(';');
                strcpy(type, st);
                strcat(type, type_data);
                strcpy(type_data, type);
                if ((i == 5) && (type_data == strstr(type_data, "long double")))
                    i = 4;
                types_of_file[i].number += define_types(false);
            }
            i++;
        }
    }
    data_file.close();
}

/****** Deleting comments **********/
void delete_comments()
{
    bool flag_com1 = false;
    bool flag_com2 = false;
    char ch;
    char test;

    while (input_file.get(ch))
    {
        test = input_file.peek();
        if ((ch == '/') && (test == '/'))
            flag_com1 = true;

        if ((ch == '\n') && flag_com1)
            flag_com1 = false;

        if ((ch == '/') && (test == '*'))
            flag_com2 = true;

        if ((ch == '*') && (test == '/'))
        {
            input_file.seekg(1, ios::cur);
            input_file.get(ch);
            flag_com2 = false;
        }

        if (!flag_com1 && !flag_com2 && !input_file.eof())
            temp_file.put(ch);
    }
    temp_file.close();
}

/****** Outputing data **********/
void output_data(const char *file_name)
{
    unsigned int max_len = 0;
    ofstream output_file(file_name, ios::trunc);
    if (!output_file)
    {
        cerr << "Cannot creat output file " << file_name << " !!!" << endl;
        getch();
        exit(1);
    }

    for (int i = 0; i < types_num; i++)
        if (strlen(types_of_file[i].name) > max_len)
            max_len = strlen(types_of_file[i].name);

    output_file << " Type name" << setw(max_len + 5) << " Size" << endl;
    for (i = 0; i < types_num; i++)
        if (types_of_file[i].number)
            output_file << setiosflags(ios::left) << setw(max_len + 10) << types_of_file[i].name << types_of_file[i].size * types_of_file[i].number << " byte(s)" << resetiosflags(ios::left) << endl;

    for (i = 0; i < 2; i++)
        if (arraies_size[i])
            output_file << setiosflags(ios::left) << setw(max_len + 10) << base_types[7 + i] << arraies_size[i] << " byte(s)" << resetiosflags(ios::left) << endl;
    output_file.close();
}

/****** Freeing global variables **********/
void free_global_pointers()
{
    if (free_const_array)
        free(const_array);

    free(types_of_file);

    if (free_values_array)
        free(values_array);
}

void main(int narg, char **argv)
{
    char cur_dir[80];
    unsigned char pos = 0;
    if (narg < 3)
    {
        cout << "Too few parametrs !!!" << endl;
        getch();
        exit(0);
    }

    if (narg > 3)
    {
        cout << "Too many parametrs !!!" << endl;
        getch();
        exit(0);
    }

    input_file.open(argv[1], ios::in);

    if (!input_file)
    {
        cerr << "File " << argv[1] << " not found !!!" << endl;
        getch();
        exit(1);
    }

    strcpy(cur_dir, argv[0]);
    for (int i = 0; i < (int)strlen(cur_dir); i++)
        if (cur_dir[i] == '\\')
            pos = i;

    cur_dir[pos] = '\x0';

    temp_file.open("temp.cpp", ios::out);

    if (!temp_file)
    {
        cerr << "Cannot create file TEMP.CPP !!!" << endl;
        getch();
        exit(1);
    }

    cout << endl;
    cout << "Processing : " << endl;
    cout << "Deleting comments..." << flush;
    delete_comments();
    cout << "Done" << endl;
    cout << "Initialization..." << flush;
    write_base_types();
    cout << "Done" << endl;
    cout << "Reading defined constants..." << flush;
    read_defines();
    cout << "Done" << endl;
    cout << "Reading structures..." << flush;
    read_structs();
    cout << "Done" << endl;
    cout << "Counting total memory..." << flush;
    read_types();
    cout << "Done" << endl;
    cout << "Output to the file " << argv[2] << "..." << flush;
    output_data(argv[2]);
    cout << "Done" << endl;
    cout << "Freeing global variables..." << flush;
    free_global_pointers();
    cout << "Done" << endl;
    cout << "Erasing template files..." << flush;
    unlink("temp.cpp");
    unlink("temp.dat");
    cout << "Done" << endl
         << endl;
    cout << "Output file is on the location " << cur_dir << endl;
    getch();
}