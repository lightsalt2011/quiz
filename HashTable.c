
#define HASHSIZE 32	//32,50,101

//������������
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

static char val_flag[HASHSIZE];//��־��ռ�ô洢��Ԫ

void ClearFlag()
{
	int i;
	
	for (i = 0;i < HASHSIZE;i++)
	{
		val_flag[i] = (HASHSIZE+1);//���־λ
	}
}

//��ϣ�������������г��ĳ����Ա���ڹ�ϣֵ�ļ���
unsigned int hash(char *s)
{
	unsigned int hashval;
	int i = 0;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s ;
	hashval = hashval % HASHSIZE; //�����±�

	while ((val_flag[hashval] != (HASHSIZE+1)) && ((i+hashval)<HASHSIZE))
	{
		i++;
		hashval = (hashval + i)%HASHSIZE;	//��ͻ�����洢��Ԫ(�±�)ƫ��
	}
	if (i<HASHSIZE)
	{
		printf("\nԪ���±�[%d]: ��ͻ������ < %d >  ",hashval,i);
		val_flag[hashval] = hashval; //��ʾ�õ�Ԫ��ռ��
		return hashval;
	}
	return -1;
}

//���ܣ�����һ��C���Թؼ��֣�������ʾ����ؼ��ֵĹ��ܼ��÷�
int main(void) 
{
  int i, size, pos;

  size = sizeof(key_input) / sizeof(key_input[0]);//����ؼ�������
 
  //�����ݴ����ϣ��
  ClearFlag();  
  //����ؼ������룬������hashֵ�洢�ؼ���ʹ�õĹ��ܷ�����key_help��
  for(i = 0;i < size; i++)
	  strcpy(key_help[  hash(key_input[i]) ], key_help_temp[i]);

  printf("\n**************************************\n");
  ClearFlag(); 
  //����ؼ������룬�������봴����ͬ��hashֵ����key_help�в��Ҷ�Ӧ�Ĺ��ܷ���
  for(i = 0; i < size; i++)
  {
    pos = hash(key_input[i]);	
    //printf("%12s  [%d]", key_help[pos], pos);
    printf("%s  ", key_help[pos]);
  }
  printf("\n\n");
  return 0;
}
