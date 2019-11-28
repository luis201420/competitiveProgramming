#include <stdio.h>
#include <string.h>

int main()
{
	int i, t, m;
	char dna[11][61];

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		for(int j = 0; j < m; j++)
			scanf("%s",dna[j]);
		int q, mark;
		char tmp[61], ans[61];
		for(int n = 60; n >= 3; n--)
		{
			mark = 1;
			for(i = 0; i <= 60-n; i++)
			{
				q = 0;
				for(int j = i; j < i+n; j++)
					tmp[q++] = dna[0][j];
				tmp[q] = '\0';
				for(int p = 1; p < m; p++)
				{
					if(!strstr(dna[p],tmp))
						goto con1;
				}
				if(mark)
				{
					strcpy(ans,tmp);
					mark = 0;
				}
				else
					if(strcmp(tmp,ans)<0)
						strcpy(ans,tmp);
				con1:;
			}
			if(!mark)
			{
				puts(ans);
				goto con;
			}
		}
		puts("no significant commonalities");
		con:;
	}
	return 1;
}
