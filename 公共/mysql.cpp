#include <stdio.h>
#include <winsock2.h>
#include <mysql.h>
#include <iostream>
/*���ݿ������ú�*/
#define HOST "localhost"
#define USERNAME "root"//�˺�
#define PASSWORD "496538sss"//����
#define DATABASE "address book"//���ݿ�

using namespace std;

void query_sql(char* sql)
{
    MYSQL my_connection; /*����һ�����ݿ�����*/
    int res; /*ִ��sql�Z���ķ��ر�־*/
    MYSQL_RES *res_ptr; /*ָ���ѯ�����ָ��*/
    MYSQL_FIELD *field; /*�ֶνṹָ��*/
    MYSQL_ROW result_row; /*���з��صĲ�ѯ��Ϣ*/
    int row, column; /*��ѯ���ص�����������*/
    int i, j;
    /*��ʼ��mysql����my_connection*/
    mysql_init(&my_connection);
    /*����mysql����*/
    if (NULL != mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD,
                                   DATABASE, 0, NULL, CLIENT_FOUND_ROWS))  /*���ӳɹ�*/
    {
        printf("���ݿ��ѯquery_sql���ӳɹ���\n");
        /*���ò�ѯ����Ϊgbk����֧������*/
        mysql_query(&my_connection, "set names gbk");
        res = mysql_query(&my_connection, sql);
        if (res)   /*ִ��ʧ��*/
        {
            printf("Error�� mysql_query !\n");
            /*�ر�����*/
            mysql_close(&my_connection);
        }
        else     /*���ھʹ���ִ�гɹ���*/
        {
            /*����ѯ�ĽY����res_ptr*/
            res_ptr = mysql_store_result(&my_connection);
            /*��������Ϊ�գ��Ͱѽ��print*/
            if (res_ptr)
            {
                /*ȡ�ýY����������*/
                column = mysql_num_fields(res_ptr);
                row = mysql_num_rows(res_ptr);
                printf("��ѯ�� %d �� \n", row);
                /*����Y�����ֶ���*/
                for (i = 0; field = mysql_fetch_field(res_ptr); i++)
                    printf("%10s ", field->name);
                printf("\n");
                /*��������Y��*/
                for (i = 1; i < row+1; i++)
                {
                    result_row = mysql_fetch_row(res_ptr);
                    for (j = 0; j < column; j++)
                        printf("%10s ", result_row[j]);
                    printf("\n");
                }
            }
            /*��Ҫ���˹ر�����*/
            mysql_close(&my_connection);
        }
    }
    else
    {
        printf("���ݿ�����ʧ��");
    }
}



void find()
{
	int fun;
		cout<<"��ѡ���ѯģʽ(1 �������ң�2�������)��"; 
		cin>>fun;
		char *query;
        char *a;
        char *b;
        char *c;
        char *d;
        b=new char[50];
        //cin>>b;
        query=new char[100];
        c=new char[100];
        //a="select * from address where ����='";
        //d="'";
        switch (fun)
        { 
        case 1:
		    {
		    	cout<<"������������";
		    	a="select * from address where ����='";
                d="'";
			    cin>>b;
        	    strcpy(c, a);
                strcat(c, b);
                strcpy(query, c);
                strcat(query, d);
                query_sql(query);
			    break;
		    }
		case 2:
			{
				cout<<"���������:" ; 
				a="select * from address where ����='";
                d="'";
				cin>>b;
        	    strcpy(c, a);
                strcat(c, b);
                strcpy(query, c);
                strcat(query, d);
                query_sql(query);
			    break;
			}
		} 
}



void add()//     insert into address values ('09','����','��','05367895','15232145897','������ӰѧԺ','4562@163.com','15245879654','����');
{
	    //int fun;
		//cout<<"��ѡ���ѯģʽ(1 �������ң�2�������)��"; 
		//cin>>fun;
		char *query;
        char *a;
        char *b;
        char *c;
        char *d;
        char *e;
        b=new char[100];
        //cin>>b;
        query=new char[100];
        c=new char[80];
        //a="insert into address values (";
        //d="'";
		cout<<"��ֱ�����(�������ƶ��ֻ�����λ��QQ,���࣬ע��ÿһ��Ҫ��'',����)��"<<"\n";
		a="insert into address values (";
        d=")";
        e="select * from address";
		cin>>b;
        strcpy(c, a);
        strcat(c, b);
        strcpy(query, c);
        strcat(query, d);
        query_sql(query);
        query_sql(e);
        cout<<query;
}



void my_delete()//     delete from ��ϵ�� where ����='����'
{
	    char *query;
	    int fun;
	    query="select * from address" ;
	    query_sql(query);
		cout<<"��ѡ��ɾ��ģʽ(1 ����ɾ����2�ƶ��ֻ�ɾ��)��"; 
		cin>>fun;
        char *a;
        char *b;
        char *c;
        char *d;
        b=new char[50];
        //cin>>b;
        query=new char[100];
        c=new char[100];
        //a="select * from address where ����='";
        //d="'";
        switch (fun)
        { 
        case 1:
		    {
		    	cout<<"������ɾ��Ŀ���������";
		    	a="delete from address where ����='";
                d="'";
			    cin>>b;
        	    strcpy(c, a);
                strcat(c, b);
                strcpy(query, c);
                strcat(query, d);
                query_sql(query);
			    break;
		    }
		case 2:
			{
				cout<<"������ɾ��Ŀ����ƶ��ֻ�:" ; 
				a="delete from address where �ƶ��ֻ�='";
                d="'";
				cin>>b;
        	    strcpy(c, a);
                strcat(c, b);
                strcpy(query, c);
                strcat(query, d);
                query_sql(query);
			    break;
			}
        } 
        query="select * from address" ;
	    query_sql(query);
}



void update()//    update address set �ƶ��ֻ�='666' where ����='111'
{
	    //int fun;
		//cout<<"��ѡ���ѯģʽ(1 �������ң�2�������)��"; 
		//cin>>fun;
		char *query;
        char *a;
        char *b;
        char *c;
        char *d;
        char *e;
        char *g;
        char *h;
        b=new char[100];
        query=new char[100];
        c=new char[80];
        g=new char[80];
        h=new char[80];
        //a="insert into address values (";
        //d="'";
        e="select * from address";
        query_sql(e);
		cout<<"��������µĶ������磺����='����'����"<<"\n";
		a="update address set ";
        d=" where ";
        //e="select * from address";
		cin>>b;//���� 
		cout<<"��������µ����ݣ����磺����='����'����"<<"\n";
		cin>>g;//�ƶ��ֻ� 
        strcpy(c, a);
        strcat(c, g);
        strcpy(h, c);
        strcat(h, d);
        strcpy(query, h);
        strcat(query, b);
        query_sql(query);
        query_sql(e);
        cout<<query;
}



int main()
{
	//cout<<"��ѡ���ܣ�"; 
	int f=1;
	while(f)
	{
		cout<<"��ѡ����(1 ���ң�2 ��ӣ�3 ɾ����4 ���£�)��";
		int menu;
		cin>>menu;
		switch (menu)
		{
			case 1:
				{
					find();break;
				}
			case 2:
				{
					add();break; 
				}
			case 3:
				{
					my_delete();break;
				}
			case 4:
				{
					update();break;
				}
		}
		cout<<"�Ƿ��˳���0�˳���1������" ; 
		cin>>f;
    }

}
