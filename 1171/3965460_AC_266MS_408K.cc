#include<iostream>
using namespace std;
struct Word
{
	char word[8];
	char len;
};
int  srcct[26];
int  srclen;
Word words[40000];
char trans[26];
void init()
{
	int i;
	char letter[]="qwertyuiopasdfghjklzxcvbnm";
	char digit[] ="76122541352146557637746525";
	for(i=0;i<26;++i) trans[letter[i]-'a']=digit[i]-'0';
}
inline void dealWord(char s[])
{
	int n=0;
	while(*s) 
	{
		srcct[*s -'a']++;
		++s;
		++n;
	}
	srclen=n;	
}

char tempct[26];
inline bool isValid(Word *pw)
{
	if(pw->len > srclen)return false;
	char *s=pw->word;
	char c;
	memset(tempct,0,26);
	while(*s)
	{
		c=*s-'a';
		++tempct[c];
		if(tempct[c]>srcct[c])return false;
		++s;
	}	
	return true;
}
inline bool isValidPair(Word *p1,Word *p2)
{
	if(p1->len +p2->len  > srclen)return false;
	char *s=p1->word;
	char c;
	memset(tempct,0,26);
	while(*s)
	{
		c=*s-'a';
		++tempct[c];
		if(tempct[c]>srcct[c])return false;
		++s;
	}	
	s=p2->word;
	while(*s)
	{
		c=*s-'a';
		++tempct[c];
		if(tempct[c]>srcct[c])return false;
		++s;
	}
	return true;
}
inline int  count(char *s)
{
	int sum=0;
	while(*s)
	{
		sum+=trans[*s-'a'];
		++s;
	}
	return sum;
}
void solve()
{
	int n=0,i,j,k;
	char s[10];
	init();
	scanf("%s",s);
	dealWord(s);
	while( scanf("%s",&words[n].word), strcmp(words[n].word,".")!=0)
	{
		words[n].len=strlen(words[n].word);
		if(isValid(&words[n]))
		{
			++n;
		}
	}
	int maxm=0,t;
	for(i=0;i<n;i++)
	{
		t=count(words[i].word);
		if(t>maxm) maxm=t;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
	{
		if(isValidPair(words+i,words+j))
		{
			t=count(words[i].word)+count(words[j].word);
			if(t>maxm) maxm=t;
		}
	}
	printf("%d",maxm);
}
int main()
{
	//freopen("c:/acm/pku_1171.txt","r",stdin);
  solve();
  return 0;
}