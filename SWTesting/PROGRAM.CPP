/*        Program : argv[1]=c:\output.txt
                  argv[2]=c:\result.txt	          */

#include <iostream.h>
#include <fstream.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const int ileft[4]={110,120,456,578};
const int iright[4]={170,200,678,987};
const char cleft[4]={'b','g','p','r'};
const char cright[4]={'y','l','w','x'};
const double fleft[4]={2.56,6.87,1.5,0.25};
const double fright[4]={9.8,9.4,5.6,0.9};
const char *sleft[4]={"abc","klm","efg","ijkl"};
const char *sright[4]={"xyz","pqr","mno","nopq"};

void main (int argn,char **argv)
{
    ifstream input_file;
    ofstream output_file;

    int d1=1;
    int i=0;
    int j=0;
    int z;
    int n=0;
    int jf=0;
    int nf=0;
    int jc=0;
    int nc=0;
    int js=0;
    int ns=0;
    char num[8];
    char temp=0;
    double z1=0;

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
    }
    do
    {
        input_file.get(temp);
        if (isdigit(temp)||temp=='-')
        {
            i=0;
            d1=1;
            while (temp!=' ' && temp!='\n')
            {
                num[i]=temp;
                i++;
                input_file.get(temp);
                if (temp=='.')
                d1=0;
            }
            num[i]='\0';
            if (d1)
            {
                z=atoi(num);
                if (z>=ileft[n] && z<=iright[n])
                    output_file<<"   "<<z<<" O.K."<<endl;
                else
                    output_file<<"   "<<z<<" ERROR"<<endl;
                j++;
                if (j==6)
                {
                    n++;
                    j=0;
                }
            }
            else
            {
                z1=atof(num);
                if (z1>=fleft[nf] && z1<=fright[nf])
                    output_file<<"   "<<z1<<" O.K."<<endl;
                else
                    output_file<<"   "<<z1<<" ERROR"<<endl;
                jf++;
                if (jf==6)
                {
                    nf++;
                    jf=0;
                }
            }
        }
        else
            flot:
        if (isalpha(temp))
        {
            i=0;
            while (temp!=' ' && temp!='\n')
            {
               num[i]=temp;
               i++;
               input_file.get(temp);
            }
            num[i]='\0';
            if (!strcmp("Int",num))
                output_file<<"Int:"<<endl;
            if (!strcmp("Char",num))
            {
                output_file<<endl<<"Char:"<<endl;
                do
                {
                    input_file.get(temp);
                    while (islower(temp))
                    {
                        if (temp>=cleft[nc] && temp<=cright[nc])
                            output_file<<"   "<<(char)temp<<" O.K."<<endl;
                        else
                            output_file<<"   "<<(char)temp<<" ERROR"<<endl;
                        jc++;
                        if (jc==6)
                        {
                            nc++;
                            jc=0;
                        }
                        input_file.get(temp);
                    }
                }
                while (temp!='F');
                 goto flot;
            }
            if (!strcmp("Float",num))
                output_file<<endl<<"Float:"<<endl;
            if (!strcmp("String",num))
            {
                output_file<<endl<<"String:"<<endl;
                input_file.get(temp);
                d1=1;
                do
                {
                    temp=0;
                    i=0;
                    while (temp!=' ' && temp!='\n')
                    {
                        input_file.get(temp);
                        if (temp==';')
                            d1=0;
                        if (d1)
                        {
                            num[i]=temp;
                            i++;
                        }
                        else
                            break;
                    }
                    if (d1)
                    {
                        num[i-1]='\0';
                        if (strcmp("",num))
                        {
                            if (strcmp(num,sleft[ns])>=0 && strcmp(num,sright[ns])<=0)
                                output_file<<"   "<<num<<" O.K."<<endl;
                            else
                                output_file<<"   "<<num<<" ERROR"<<endl;
                            js++;
                            if (js==6)
                            {
                                ns++;
                                js=0;
                            }
                        }
                    }
                }
                while (temp!=';');
            }
        }
    }
    while (!input_file.eof());
    input_file.close();
    output_file.close();
}