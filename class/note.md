# 记录
## 主函数
```c
int main (int argc,char *argv[]){
    int i;
    for (i = 0;i<argc;i++){
        if (argv[i][]=='-'){
            switch(argv[i][]){
                case 'l':
                case 'r':
                case 'c':
                   align = argv[i][];
                   break;
                case 'w':
                   width = atoi(argv[i+1])
                   break;
                
                
            }
        }
        printf ("argv[%d]:%s\n",i,argv[i]);
    }
}


其中`*argv[]`相当于`argv[][]`。

在命令行输入：
```
newban.exe -f 3-d -w 40 -c hello abc
      1    2   3   4  5  6   7     8 
```
主函数就可读取命令行
		argc = 8
		
		argv[0]: newban.exe
		argv[1]: -f
		....


# 需要知识
- 结构体
- 文件打开关闭




# 打开文件
```
```








