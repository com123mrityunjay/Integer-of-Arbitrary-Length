#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* remove_leading_zeros(char* thearray)
{
	int i , c ;
	char* result = (char*)(malloc((1001)*sizeof(char)));
    int size = strlen(thearray);
    
    for (i = 0; i < size - 1; i++)
    {
        if (thearray[i] != '0')
        {
            break;
        }
    }
	c = i;
    for (i = c ; i < size; i++)
    {
    	result[i-c] = thearray[i] ;
    }
    result[size-c] = '\0';
    return (result);
}


char* intal_add(const char* intal1, const char* intal2)
{
	int length1 = strlen(intal1);
	int length2 = strlen(intal2);
	int i,max = 0;
	int carry = 0;

	if(length1 > length2)
	{
		max = length1;
	}
	else if(length1 < length2)
	{
		max = length2;
	}
	else
	{
		max = length1;
	}
	
	
	int* a = (int*) calloc(max,sizeof(int));
	int* b = (int*) calloc(max,sizeof(int));
	char* result = (char*) malloc((max+1)*(sizeof(char)));
	char* result1 = (char*) malloc((max+2)*(sizeof(char)));
	
	for(i = 0; i < strlen(intal1) ; i++)
	{
		a[i] = (int) (intal1[strlen(intal1)-1-i]- '0');
	}
	
	for(i = 0; i < strlen(intal2) ; i++)
	{
		b[i] = (int) (intal2[strlen(intal2)-1-i]- '0');
	}


	for(i = 0 ; i < max ; i++)
	{
		result[i] = (char)(((a[i] + b[i] + carry) % 10) + '0') ;
		if((a[i] + b[i] + carry) >= 10)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
	}
	
	result[max] = (char)(carry + '0');
	
	
	for(i = 0; i<=max; i++)
	{
		result1[i] = result[max-i];
	}
	result1[max+1] = '\0';
	
	result1 = remove_leading_zeros(result1);
	free(a);
	free(b);
	free (result);
	return (result1);
	
}

int intal_compare(const char* intal1, const char* intal2)
{
	int length1 = strlen(intal1);
	int length2 = strlen(intal2);
	
	int i;	
	
	if(length1 > length2)
	{
		return 1 ;
	}
	
	if(length1 < length2)
	{
		return -1;
	}
	
	for(i = 0 ; i < length1 ; i++)
	{
		if(intal1[i] > intal2[i])
		{
			return 1;
		}
		if(intal1[i] < intal2[i])
		{
			return -1;
		}
	}
	return 0;
		
}


char* intal_diff(const char* intal1, const char* intal2)
{
	int length1 = strlen(intal1);
	int length2 = strlen(intal2);
	int i,max = 0;
	if(length1 > length2)
	{
		max = length1;
	}
	else if(length1 < length2)
	{
		max = length2;
	}
	else
	{
		max = length1;
	}
	int comp;
	int* a = (int*) calloc(max,sizeof(int));
	int* b = (int*) calloc(max,sizeof(int));
	char* a1 = (char*) malloc(max*sizeof(char));
	char* b1 = (char*) malloc(max*sizeof(char));
	
	char* result = (char*) malloc((max)*(sizeof(char)));
	char* result1 = (char*) malloc((max+1)*(sizeof(char)));
	
	comp = intal_compare(intal1, intal2);
	
	if(comp == 0)
	{
		result1[0] = '0';
		result1[1] = '\0';
		return (result1);
	}
	
	if(comp == -1)
	{
		strcpy(a1,intal2);
		strcpy(b1,intal1);	
	}
	
	if(comp == 1)
	{
		strcpy(a1,intal1);
		strcpy(b1,intal2);
	}
	
	for(i = 0; i < strlen(a1) ; i++)
	{
		a[i] = (int) (a1[strlen(a1)-1-i]- '0');
	}
	
	for(i = 0; i < strlen(b1) ; i++)
	{
		b[i] = (int) (b1[strlen(b1)-1-i]- '0');
	}

	for(i = 0; i < max; i++)
	{
		if(a[i] < b[i])
		{
			a[i] = a[i] + 10;
			a[i+1] = a[i+1] - 1;
			result[i] = a[i] - b[i];
		}
		else
		{
			result[i] = a[i] - b[i];
		}
	}
	
	for(i = 0; i < max; i++)
	{
		result1[i] = (char) (result[max-1-i] + '0');
	}
	
	result1[max] = '\0';
	result1 = remove_leading_zeros(result1);
	free(a);
	free(b);
	free(a1);
	free(b1);
	free(result);
	
	return(result1);
}


char* intal_multiply(char* intal1, char* intal2)
{
	char* temp = (char*) malloc(2*sizeof(char));
    if(*intal1=='0' || *intal2=='0')
    {
    	strcpy(temp , "0");
    	return temp;
    }
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);
    int len = len1+len2;
    int *arr = (int*)malloc(sizeof(int)*len); 
    memset(arr, 0, sizeof(int)*len); 
    for(int i=len1-1; i > -1; i--)
    {
        for(int j=len2-1; j > -1; j--)
        {
            arr[i+j+1] += (intal1[i]-'0')*(intal2[j]-'0');
        }
    } 
    for(int i=len-1; i > 0; i--) 
    {
        arr[i-1] += arr[i]/10;
        arr[i] %= 10;
    }
    char *s = (char*)malloc(sizeof(char)*(len+1)); 
    int index = 0;
    int i = 0;
    if(arr[i]==0)
    { 
    	i++;
    } 
    while(i < len)
    {
        s[index++] = arr[i++]+'0';
    }
    
    s[index] = '\0';
    
    free(temp);
    
    return s;
}

int intal_max(char **arr, int n)
{
	int i , comp = 0 ;
	char* max = arr[0];
	int c = 0;
	for( i = 1 ; i < n ; i++)
	{
		comp = intal_compare (max , arr[i]);
		if(comp == -1)
		{
			max = arr[i];
			c = i;
		}
	}
	
	return c;
}

int intal_min(char **arr, int n)
{
	int i , comp = 0 ;
	char* min = arr[0];
	int c = 0;
	for( i = 1 ; i < n ; i++)
	{
		comp = intal_compare (min , arr[i]);
		if(comp == 1)
		{
			min = arr[i];
			c = i;
		}
	}
	
	return c;
}

int intal_search(char **arr, int n, const char* key)
{
	int i , comp = 0;

	for(i = 0 ; i < n ; i++)
	{
		comp = intal_compare (key , arr[i]);
		if(comp == 0)
		{
			return i;
		}
	}
	return -1;
}

static int partition (char **arr, int low, int high) 
{ 
    char* pivot = arr[high];
    char* temp;
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if ((intal_compare(arr[j] , pivot)) == -1)
        { 
            i++;   
            temp = arr[i]; 
  			arr[i] = arr[j]; 
  			arr[j] = temp; 
        } 
    } 
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    
    return (i + 1); 
} 

static void quickSort(char **arr, int low, int high) 
{ 
    if (low < high) 
    { 
       
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


void intal_sort(char **arr, int n)
{
	quickSort(arr, 0, n-1); 
}

int intal_binsearch(char **arr, int n, const char* key)
{ 
	int l = 0 , r = n - 1;
	int m;
    while (l <= r)
    { 
        m = l + (r - l) / 2; 
        if ((intal_compare(arr[m] , key )) == 0) 
            return m; 
             
        if (intal_compare(arr[m] , key) == -1) 
            l = m + 1; 
  
        else
            r = m - 1; 
    }
    return -1; 
    
} 

char* coin_row_problem(char **arr, int n)
{
	char* result = (char*) malloc(1001*sizeof(char));
	if(n == 0)
	{
		result[0] = '0' ;
		result[1] = '\0';
		return result;
	}
	
	char* prev = "0";
	char* curr = arr[0];
	int i;
	char* s;
	char* next;
	int comp;
	for(i = 2; i <= n ; i++)
	{
		s = intal_add(prev, arr[i-1]);
		comp = intal_compare(s , curr);
		if((comp == 1) || (comp == 0))
		{
			next = s;
		}
		else
		{
			next = curr;
		}
		prev = curr;
		curr = next;
		
	}
	curr = remove_leading_zeros(curr);
	strcpy(result , curr);
	return result;

}




char* intal_pow(const char* intal1, unsigned int n)
{
	char* temp;
	char* x1;
	char* temp1 = (char*) (malloc(1001*sizeof(char)));
	strcpy(temp1 , intal1);
	char* s = (char*) (malloc(1001*sizeof(char)));
	if(n == 0)
	{
		s[0] = '1';
		s[1] = '\0';
		
		return s;
	}
	if(strcmp(temp1 , "0") == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		
		return s;
	}
	temp = intal_pow(temp1, n/2);
	if((n%2) == 0)
	{
		
		s = intal_multiply( temp , temp);
		return s;
	}
	else
	{
	
		x1 =  intal_multiply( temp , temp);
		
		s = intal_multiply(temp1 , x1);

		return s;
	}
	
	
}


char* intal_fibonacci(unsigned int n)
{
	char* sum;
	char first[1001] = "0";
	char second[1001] = "1";
	char* result = (char*) malloc(1001*sizeof(char));
	char *ptr1 = first;
	char *ptr2 = second;
	int i;
	if(n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return result;
	}
	if(n == 1)
	{
		result[0] = '1';
		result[1] = '\0';
		return result;
	}
	
	for( i = 2 ; i <= n ; i++)
	{
		sum = intal_add(ptr1 , ptr2);
		ptr1 = ptr2;
		ptr2 = sum;
	}
	strcpy(result , ptr2);
	return result;

}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
	int i;
	char **dp = (char**) malloc(k+1 * sizeof(char*));
	for( i = 0; i <= k; i++) 
	{
		dp[i] = (char*) malloc(1001 * sizeof(char));
	}
	for( i = 0 ; i <= k ; i++)
	{
		strcpy(dp[i],"0");
	}
	strcpy(dp[0], "1");
	
	int j;
	if ( k > n - k ) 
        k = n - k; 
	
	for( i = 1 ; i <=n ; i++)
	{
		
		if(i <= k)
		{
			for( j = i ; j > 0 ; j--)
			{
				strcpy(dp[j] , intal_add(dp[j] , dp[j-1]));
			}
		}
		else
		{
			for( j = k ; j > 0 ; j--)
			{
				
				strcpy(dp[j] , intal_add(dp[j] , dp[j-1]));
			}
	
		}
	}

	for(i = 0; i < k ; i++)
 	{
 		free(dp[i]);
	}
	
	return dp[k];
		
}

char* intal_factorial(unsigned int n)
{
	
	int i;
	char* prev = "1";
	
	char* curr;
	char* result  = (char*) malloc(1001*sizeof(char));
	char **s = (char**) malloc((n + 2) * sizeof(char*));
	
	if((n == 0) || (n == 1))
	{
		result[0] = '1';
		result[1] = '\0';
		
		for(i = 0; i <= n; i++) 
		{
			free(s[i]);
		}
		
		free(s);
		return result;
	}
	
	for(i = 0; i <= n; i++) 
	{
		s[i] = (char*) malloc(1001 * sizeof(char));
	}
	for( i = 2 ; i <= n ; i++)
	{
		sprintf(s[i] , "%d" , i);
		curr = intal_multiply(s[i] , prev);
		prev = curr;		
	}
	for(i = 0; i <= n; i++) 
	{
		free(s[i]);
	}
	
	free(result);
	free(s);
	return curr;
}

char* intal_mod(const char* intal1, const char* intal2)
{
	
	int i , comp , c ;
	char* s = (char*) malloc(1001*sizeof(char));
	char* s1 = (char*) malloc(2*sizeof(char));
	for( i = 0 ; i < strlen(intal2) ; i++)
	{
		s[i] = intal1[i];
	}
	s[strlen(intal2)] = '\0';
	comp = intal_compare( s , intal2 ) ;
	c = strlen(intal2) - 1; 
	if(comp == -1)
	{
		strncat(s,&(intal1[c+1]),1);
		c = strlen(intal2);
	}
	
	for( i = c ; i < strlen(intal1) - 1 ; i++)
	{
		while(intal_compare(s , intal2) > 0)
		{
			s = intal_diff( s , intal2);
		}
		s1[0] = intal1[i+1];
		s1[1] = '\0';
		
		strcat( s , s1 );
	}
	while(intal_compare( s , intal2) >= 0)
	{
		s = intal_diff( s , intal2);
	}
	free(s1);
	
	return (s);
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	char* t;
	char* r;
	char* m = (char*) malloc(1001*sizeof(char));
	char* n = (char*) malloc(1001*sizeof(char));
	
	strcpy(m , intal1);
	strcpy(n , intal2);

	char* temp1 = malloc((strlen(intal1) + 1) * sizeof(char));
	char* temp2 = malloc((strlen(intal2) + 1) * sizeof(char));
	
	if(strcmp(intal2, "0") == 0) 
	{	
		free(temp2);
		free(m);
		free(n);
  		strcpy(temp1, intal1);
  		return temp1;
	}
	
	if(strcmp(intal1, "0") == 0) 
	{	
		free(temp1);
		free(m);
		free(n);
  		strcpy(temp2, intal2);
  		return temp2;
	}
	
	if(intal_compare(intal1 , intal2) == -1)
	{
		t = m;
		m = n;
		n = t;
	}
	
	while(intal_compare( n , "0") > 0)
	{
		r = intal_mod(m , n);
		m = n;
		n = r;
	}
	free(temp1);
	free(temp2);
	return m;
}
























		
		
		
		
		
