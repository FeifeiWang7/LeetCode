bool isNumber(char* s) 
{
	int fsm = -1,i;
	for(i = 0; i <= strlen(s); i++)
	{
			if(fsm == -1)
			{
				if(isspace(s[i])) fsm = 0;
				else if(s[i] == '.') fsm = 1;
				else if(s[i] == '+' || s[i] == '-') fsm = 2;
				else if(isdigit(s[i])) fsm = 3;
				else return false;
			}
			else if(fsm == 0)
			{
				if(isspace(s[i])) fsm = 0;
<<<<<<< Local Changes
                else if(s[i] == '.') fsm = 1;
                else if(s[i] == '+' || s[i] == '-') fsm = 2;
                else if(isdigit(s[i])) fms = 3;
                else return false;
                break;
			case 1: 
=======
                else if(s[i] == '.') fsm = 1;
                else if(s[i] == '+' || s[i] == '-') fsm = 2;
                else if(isdigit(s[i])) fsm = 3;
                else return false;
			}
			else if(fsm == 1)
			{
>>>>>>> External Changes
				if(isdigit(s[i])) fsm = 4;
				else return false;
			}
			else if(fsm == 2)
			{
				if(isdigit(s[i])) fsm = 3;
				else if(s[i] == '.') fsm = 1;
				else return false;
            }
            else if(fsm == 3)
            {
				if(isdigit(s[i])) fsm = 3;
				else if(s[i] == 'e') fsm = 5;
				else if(s[i] == '.') fsm = 6;
				else if(isspace(s[i])) fsm = 10;
				else if(s[i] == '\0') return true;
				else return false;
            }
            else if(fsm == 4)
            {
				if(isdigit(s[i])) fsm = 4;
				else if(s[i] == 'e') fsm = 5;
				else if(isspace(s[i])) fsm = 10;
				else if(s[i] == '\0') return true;
				else return false;
            }
            else if(fsm == 5)
            {
				if(isdigit(s[i])) fsm = 9;
				else if(s[i] == '+' || s[i] == '-') fsm = 7;
				else return false;
            }
			else if(fsm == 6)
			{
				if(isdigit(s[i])) fsm = 4;
				else if(s[i] == '\0') return true;
				else if(isspace(s[i])) fsm = 10;
				else if(s[i] == 'e') fsm = 5;
				else return false;
			}
			else if(fsm == 7)
			{
				if(isdigit(s[i])) fsm = 9;
				else return false;
			}
			else if(fsm == 9)
			{
				if(isspace(s[i])) fsm = 10;
				else if(isdigit(s[i])) fsm = 9;
				else if(s[i] == '\0') return true;
				else return false;
            }
            else if(fsm == 10)
            {
				if(isspace(s[i])) fsm = 10;
				else if(s[i] == '\0') return true;
				else return false;
            }		
	}
}
