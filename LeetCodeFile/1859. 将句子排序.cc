typedef struct WordRecord
{
	char *p; //字符串指针，需要开辟数据空间
	int len; //字符串长度
}WordRecord;
char * sortSentence(char * s)
{
	//开辟10个空间，0下标不用
	WordRecord wr[10];
	int len = strlen(s);
	int i, j, maxValue, sIdx;
	i = j = maxValue = sIdx = 0;
	for (i = 0; i < len; ++i)
	{
		//寻找数字
		int sentenceIdx = s[i] - '0';
		if (sentenceIdx >= 1 && sentenceIdx <= 9)
		{
			wr[sentenceIdx].len = i - sIdx + 1;
			wr[sentenceIdx].p = (char *)malloc(sizeof(char)* wr[sentenceIdx].len);
			for (j = 0; j < wr[sentenceIdx].len - 1; j++)
			{
				wr[sentenceIdx].p[j] = s[sIdx + j];
			}
			wr[sentenceIdx].p[j] = ' ';
			sIdx = i + 2; //跳过数字和空格
			//记录单词的最大个数
			maxValue = maxValue < sentenceIdx ? sentenceIdx : maxValue;
		}
	}
	for (i = 0, j = 1; j <= maxValue; j++)
	{
		for (int k = 0; k < wr[j].len; k++)
		{
			s[i++] = wr[j].p[k];
		}
		//释放字符串空间
		free(wr[j].p);
		wr[j].p = NULL;
	}
	s[i - 1] = '\0';
	return s;
}