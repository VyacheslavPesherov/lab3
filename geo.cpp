#include <iostream> 
#include <string.h>

using namespace std;

int main()
{
    const char circle[7] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int count;
    do {
        cout << "Enter number of figures" << endl;
        cin >> count;
        if (count < 1) cout << "Error! Invalid number" << endl;
    } while (count < 1);
    cin.get();
    char str[count][30];
    
    for (int i = 0; i < count; i++) {
        cout << "Enter name of figure" << endl;
	    cin.getline(str[i], 30);
	    if (strncmp(str[i], circle, 6) != 0) {
			cout << "Error! Invalid figure" << endl;
			i--;	
			continue;	
	    }
	    if (str[i][6] == '(') {
	    	bool flag = false;
	    	short spaces = 0, komma = 0;
	    	for (int j = 7; j < 30; j++) {
	    		if (str[i][j] == ')') {
					flag = true;
					break;
				}
	    		if (str[i][j] == ' ') spaces++; 
	    		if (str[i][j] == ',') komma++;
	    	}
	    	if (flag == false) {
				cout << "Error! Invalid format" << endl;
			 	i--;
			 	continue;
			}
			if (spaces != 2) {
				cout << "Error! Invalid format" << endl;
				i--;
				continue;
			}
			if (komma != 1) {
				cout << "Error! Invalid format" << endl;
				i--;
				continue;
			}
		}
		else {
			cout << "Error! Invalid format" << endl;
			i--;
		}
    }

    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ".";
        puts(str[i]);
        cout << endl;
    }
   
    cin.get();
    return 0;
}
