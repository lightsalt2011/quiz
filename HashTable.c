
#define HASHSIZE 32	//32,50,101

//待存入表格数据
char *key_input[] = {
		"auto",   "break",  "case",     "char",   "const",    "continue", "default",  
		"do",
		"double", "else",   "enum",     "extern", "float",    "for",      "goto",     
		"if",
		"int",    "long",   "register", "return", "short",    "signed",   "sizeof",   
		"static",
		"struct", "switch", "typedef",  "union",  "unsigned", "void",     "volatile",
		"while"
};
char *key_help_temp[] = {
		"auto function",
		"break function",
		"case function",
		"char function",
		"const function",
		"continue function",
		"default function",  
		"do function",
		"double function",
		"else function",
		"enum function",
		"extern function",
		"float function",
		"for function",
		"goto function",     
		"if function",
		"int function",
		"long function",
		"register function",
		"return function",
		"short function",
		"signed function",
		"sizeof function",   
		"static function",
		"struct function",
		"switch function",
		"typedef function",
		"union function",
		"unsigned function",
		"void function",
		"volatile function",
		"while function"
};
char key_help[HASHSIZE][100];

static char val_flag[HASHSIZE];//标志已占用存储单元

void ClearFlag()
{
	int i;
	
	for (i = 0;i < HASHSIZE;i++)
	{
		val_flag[i] = (HASHSIZE+1);//清标志位
	}
}

//哈希函数，从数据中抽出某个成员用于哈希值的计算
unsigned int hash(char *s)
{
	unsigned int hashval;
	int i = 0;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s ;
	hashval = hashval % HASHSIZE; //计算下标

	while ((val_flag[hashval] != (HASHSIZE+1)) && ((i+hashval)<HASHSIZE))
	{
		i++;
		hashval = (hashval + i)%HASHSIZE;	//冲突处理，存储单元(下标)偏移
	}
	if (i<HASHSIZE)
	{
		printf("\n元素下标[%d]: 冲突次数： < %d >  ",hashval,i);
		val_flag[hashval] = hashval; //表示该单元被占用
		return hashval;
	}
	return -1;
}

//功能：输入一个C语言关键字，快速提示这个关键字的功能及用法
int main(void) 
{
  int i, size, pos;

  size = sizeof(key_input) / sizeof(key_input[0]);//计算关键字数量
 
  //将数据存入哈希表
  ClearFlag();  
  //摸拟关键字输入，并根据hash值存储关键字使用的功能方法到key_help中
  for(i = 0;i < size; i++)
	  strcpy(key_help[  hash(key_input[i]) ], key_help_temp[i]);

  printf("\n**************************************\n");
  ClearFlag(); 
  //摸拟关键字输入，并根据与创建相同的hash值，从key_help中查找对应的功能方法
  for(i = 0; i < size; i++)
  {
    pos = hash(key_input[i]);	
    //printf("%12s  [%d]", key_help[pos], pos);
    printf("%s  ", key_help[pos]);
  }
  printf("\n\n");
  return 0;
}
