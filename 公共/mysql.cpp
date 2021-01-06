#include <stdio.h>
#include <winsock2.h>
#include <mysql.h>
#include <iostream>
/*数据库连接用宏*/
#define HOST "localhost"
#define USERNAME "root"//账号
#define PASSWORD "496538sss"//密码
#define DATABASE "address book"//数据库

using namespace std;

void query_sql(char* sql)
{
    MYSQL my_connection; /*这是一个数据库连接*/
    int res; /*执行sql語句后的返回标志*/
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    MYSQL_FIELD *field; /*字段结构指针*/
    MYSQL_ROW result_row; /*按行返回的查询信息*/
    int row, column; /*查询返回的行数和列数*/
    int i, j;
    /*初始化mysql连接my_connection*/
    mysql_init(&my_connection);
    /*建立mysql连接*/
    if (NULL != mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD,
                                   DATABASE, 0, NULL, CLIENT_FOUND_ROWS))  /*连接成功*/
    {
        printf("数据库查询query_sql连接成功！\n");
        /*设置查询编码为gbk，以支持中文*/
        mysql_query(&my_connection, "set names gbk");
        res = mysql_query(&my_connection, sql);
        if (res)   /*执行失败*/
        {
            printf("Error： mysql_query !\n");
            /*关闭连接*/
            mysql_close(&my_connection);
        }
        else     /*现在就代表执行成功了*/
        {
            /*将查询的結果给res_ptr*/
            res_ptr = mysql_store_result(&my_connection);
            /*如果结果不为空，就把结果print*/
            if (res_ptr)
            {
                /*取得結果的行数和*/
                column = mysql_num_fields(res_ptr);
                row = mysql_num_rows(res_ptr);
                printf("查询到 %d 行 \n", row);
                /*输出結果的字段名*/
                for (i = 0; field = mysql_fetch_field(res_ptr); i++)
                    printf("%10s ", field->name);
                printf("\n");
                /*按行输出結果*/
                for (i = 1; i < row+1; i++)
                {
                    result_row = mysql_fetch_row(res_ptr);
                    for (j = 0; j < column; j++)
                        printf("%10s ", result_row[j]);
                    printf("\n");
                }
            }
            /*不要忘了关闭连接*/
            mysql_close(&my_connection);
        }
    }
    else
    {
        printf("数据库连接失败");
    }
}



void find()
{
	int fun;
		cout<<"请选择查询模式(1 姓名查找；2分类查找)："; 
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
        //a="select * from address where 姓名='";
        //d="'";
        switch (fun)
        { 
        case 1:
		    {
		    	cout<<"请输入姓名：";
		    	a="select * from address where 姓名='";
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
				cout<<"请输入分类:" ; 
				a="select * from address where 分类='";
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



void add()//     insert into address values ('09','王八','男','05367895','15232145897','北京电影学院','4562@163.com','15245879654','朋友');
{
	    //int fun;
		//cout<<"请选择查询模式(1 姓名查找；2分类查找)："; 
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
		cout<<"请分别输入(姓名，移动手机，单位，QQ,分类，注意每一项要用'',隔开)："<<"\n";
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



void my_delete()//     delete from 联系人 where 姓名='王八'
{
	    char *query;
	    int fun;
	    query="select * from address" ;
	    query_sql(query);
		cout<<"请选择删除模式(1 姓名删除；2移动手机删除)："; 
		cin>>fun;
        char *a;
        char *b;
        char *c;
        char *d;
        b=new char[50];
        //cin>>b;
        query=new char[100];
        c=new char[100];
        //a="select * from address where 姓名='";
        //d="'";
        switch (fun)
        { 
        case 1:
		    {
		    	cout<<"请输入删除目标的姓名：";
		    	a="delete from address where 姓名='";
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
				cout<<"请输入删除目标的移动手机:" ; 
				a="delete from address where 移动手机='";
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



void update()//    update address set 移动手机='666' where 姓名='111'
{
	    //int fun;
		//cout<<"请选择查询模式(1 姓名查找；2分类查找)："; 
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
		cout<<"请输入更新的对象（例如：姓名='李六'）："<<"\n";
		a="update address set ";
        d=" where ";
        //e="select * from address";
		cin>>b;//李六 
		cout<<"请输入更新的内容（例如：姓名='李六'）："<<"\n";
		cin>>g;//移动手机 
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
	//cout<<"请选择功能："; 
	int f=1;
	while(f)
	{
		cout<<"请选择功能(1 查找；2 添加；3 删除；4 更新；)：";
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
		cout<<"是否退出（0退出；1继续）" ; 
		cin>>f;
    }

}
