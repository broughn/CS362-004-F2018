#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //Generate random number 0-8
    int intRand = rand() % 9;
    //Define cases based on random number generated above
    //Each case returns a different character used in testme()
    switch(intRand) {
    	case 0:
    		return '[';
    	case 1:
    		return '(';
    	case 2:
    		return '{';
    	case 3:
    		return ' ';
    	case 4:
    		return 'a';
    	case 5:
    		return 'x';
    	case 6:
    		return '}';
    	case 7:
    		return ')';
    	case 8:
    		return ']';
    }
    return ' ';
}

char *inputString()
{
	//Generate random number 0-3
    int intRand = rand() % 4;
    //Define cases based on random number generated above
    //Each case returns a different string. Case 0 is
    //the string we are looking to have returned to end the
    //test suite.
    switch(intRand) {
    	case 0:
    		return "reset";
    	case 1:
    		return "mango";
    	case 2:
    		return "radio";
    	case 3:
    		return "asset";
    }
    return "";
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
