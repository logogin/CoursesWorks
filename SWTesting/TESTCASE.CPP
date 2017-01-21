/*              TestCase : argv[1]=c:\spec.txt
                           argv[2]=c:\output.txt       */
#include <iostream.h>
#include <fstream.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main (int argn,char **argv)
{
    ifstream input_file;
    ofstream output_file;

    int d1=1;
    int i=0;
    int z;
    char num[8];
    char temp=0;
    double z1;

    input_file.open(argv[1],ios::in);
    if (!input_file)
    {
        cerr<<"Can't open the file !"<<endl;
        exit(1);
    }
    output_file.open(argv[2],ios::out);
    if (!output_file)
    {
        cerr<<"Can't open the file !"<<endl;
        exit(1);
        //exit (1);
    }
    do
    {
        input_file>>num;
        if (!strcmp("int",num))                     /**  I  N  T   **/
        {
            input_file>>temp;
            output_file<<"Int "<<temp<<":"<<endl;

            while (d1)
            {
                i=0;
                temp=0;
                while (temp!=':' && temp!=']' && temp!=';')
                {
                    input_file.get(temp);
                    if (isdigit(temp))
                    {
                        num[i]=temp;
                        i++;
                    }
                }
                if (temp==';')
                    d1=0;
                if (d1)
                {
                    num[i]='\0';
                    z=atoi(num);
                    output_file<<" "<<z-1<<" "<<z<<" "<<z+1<<endl;
                }
            }
        }
        d1=1;
        if (!strcmp("char",num))                  /**  C  H  A  R  **/
        {
            input_file>>temp;
            output_file<<"Char "<<temp<<":"<<endl;
            while (d1)
            {
                temp=0;
                while (temp!=':' && temp!=']' && temp!=';')
                {
                    input_file.get(temp);
                    if (isalpha(temp))
                        output_file<<" "<<(char)(temp-1)<<" "<<temp<<" "<<(char)(temp+1)<<endl;
                }
                if (temp==';')
                    d1=0;
            }
        }
        if (!strcmp("float",num))                 /**    F  L  O  A  T    **/
        {
            input_file>>temp;
            output_file<<"Float "<<temp<<":"<<endl;
            while (d1)
            {
                i=0;
                temp=0;
                while (temp!=':' && temp!=']' && temp!=';')
                {
                    input_file.get(temp);
                    if (isdigit(temp)||temp=='.')
                    {
                        num[i]=temp;
                        i++;
                    }
                }
                if (temp==';')
                    d1=0;
                if(d1)
                {
                    num[i]='\0';
                    z1=atof(num);
                    output_file<<" "<<z1-1<<" "<<z1<<" "<<z1+1<<endl;
                }
            }
        }
        if (!strcmp("string",num))                  /**  S  T  R  I  N  G   **/
        {
            input_file>>temp;
            output_file<<"String "<<temp<<":";
            while (d1)
            {
                i=0;
                temp=0;
                while (temp!=':' && temp!=']' && temp!=';')
                {
                    input_file.get(temp);
                    if (isalpha(temp))
                    {
                        num[i]=temp;
                        i++;
                    }
                }
                if (temp==';')
                    d1=0;
                if (d1)
                {
                    num[i]='\0';
                    i=0;
                    while (num[i]!='\0')
                    {
                        num[i]-=1;
                        i++;
                    }
                    output_file<<endl<<" "<<num;
                    i=0;
                    while (num[i]!='\0')
                    {
                        num[i]+=1;
                        i++;
                    }
                    output_file<<"   "<<num;
                    i=0;
                    while (num[i]!='\0')
                    {
                        num[i]+=1;
                        i++;
                    }
                    output_file<<"   "<<num;
                }	
            }
        }
    }
    while (!input_file.eof());
    output_file<<endl;
    input_file.close();
    output_file.close();
}