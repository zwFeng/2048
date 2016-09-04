#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <windows.h>
using namespace std;
int num[4][4];
bool test();
int main() {
	char again = 'a';
	int theHighestScore; 
	FILE *fp;
	fp = fopen("E:\\record.txt", "r");
	int i = fread(&theHighestScore, sizeof(int), 1, fp);
	if (i == 0) {
		theHighestScore = 0;
	}
	fclose(fp);
	while (again != ' ') {
		bool endWay = true;
		int t = 0;
		int score = 0;
		int end = 1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num[i][j] = 0;
			}
		}
		num[rand() % 4][rand() % 4] = 2;
		while (end != 2048) {
			system("cls");
			cout << "\t\t2048" << endl;
			cout << "\t\tScore:" << score << endl;
			cout << "\t\tThe highest score:" << theHighestScore << endl;
			cout << "**********************************************" << endl;
			int x = rand() % 4;
			int y = rand() % 4;
			int n = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (num[i][j]) {
						n++;
					}
				}
			}
			if (n != 16) {
				while (num[x][y]) {
					x = rand() % 4;
					y = rand() % 4;
				}
				int ran = rand() % 5;
				if (t == 1) {
					if (ran >= 0 && ran <= 3) {
						num[x][y] = 2;
					}
					else {
						num[x][y] = 4;
					}
					t = 0;
				}
			}
			printf ("\t�������ש����ש����ש�����\n");
			for (int i = 0; i < 4; i++) {
				printf("\t��");
				for (int j = 0; j < 4; j++) {
					if (num[i][j]) {
						printf("%4d��", num[i][j]);
					}
					else {
						printf("    ��");
					}
				}
				printf("\n");
				if (i == 3) {
					printf ("\t�������ߩ����ߩ����ߩ�����\n");
				}
				else {
					printf ("\t�ǩ����贈���贈���贈����\n");
				}
			}
			char ch = _getch(); 
			if (ch == 'w') {
				for (int j = 0; j < 4; j++) {
					for (int i = 3; i >= 1; i--) {
						if (num[i][j] != 0 && num[i - 1][j] == 0) {
							num[i - 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 3; i >= 1; i--) {
						if (num[i][j] != 0 && num[i - 1][j] == 0) {
							num[i - 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 3; i >= 1; i--) {
						if (num[i][j] != 0 && num[i - 1][j] == 0) {
							num[i - 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					int flag = 0;
					for (int i = 1; i <= 3; i++) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (num[i][j] == num[i - 1][j] && num[i][j] != 0) {
							num[i - 1][j] *= 2;
							score += num[i - 1][j];
							num[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					for (int i = 3; i >= 1; i--) {
						if (num[i][j] != 0 && num[i - 1][j] == 0) {
							num[i - 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
			}
			else if (ch == 'a') {
				for (int i = 0; i < 4; i++) {
					for (int j = 3; j >= 1; j--) {
						if (num[i][j] != 0 && num[i][j - 1] == 0) {
							num[i][j - 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 3; j >= 1; j--) {
						if (num[i][j] != 0 && num[i][j - 1] == 0) {
							num[i][j - 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 3; j >= 1; j--) {
						if (num[i][j] != 0 && num[i][j - 1] == 0) {
							num[i][j - 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					int flag = 0;
					for (int j = 1; j <= 3; j++) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (num[i][j] == num[i][j - 1] && num[i][j] != 0) {
							num[i][j - 1] *= 2;
							score += num[i][j - 1];
							num[i][j] = 0;
								flag = 1;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 3; j >= 1; j--) {
						if (num[i][j] != 0 && num[i][j - 1] == 0) {
							num[i][j - 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
			}
			else if (ch == 's') {
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i <= 2; i++) {
						if (num[i][j] != 0 && num[i + 1][j] == 0) {
							num[i + 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 0; i <= 2; i++) {
						if (num[i][j] != 0 && num[i + 1][j] == 0) {
							num[i + 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 0; i <= 2; i++) {
						if (num[i][j] != 0 && num[i + 1][j] == 0) {
							num[i + 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}	
				for (int j = 0; j < 4; j++) {
					int flag = 0;
					for (int i = 2; i >= 0; i--) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (num[i][j] == num[i + 1][j] && num[i][j] != 0) {
							num[i + 1][j] *= 2;
							score += num[i + 1][j];
							num[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i <= 2; i++) {
						if (num[i][j] != 0 && num[i + 1][j] == 0) {
							num[i + 1][j] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
			}
			else if (ch == 'd') {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j <= 2; j++) {
						if (num[i][j] != 0 && num[i][j + 1] == 0) {
							num[i][j + 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 0; j <= 2; j++) {
						if (num[i][j] != 0 && num[i][j + 1] == 0) {
							num[i][j + 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 0; j <= 2; j++) {
						if (num[i][j] != 0 && num[i][j + 1] == 0) {
							num[i][j + 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					int flag = 0;
					for (int j = 2; j >= 0; j--) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (num[i][j] == num[i][j + 1] && num[i][j] != 0) {
							num[i][j + 1] *= 2;
							score += num[i][j + 1];
							num[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j <= 2; j++) {
						if (num[i][j] != 0 && num[i][j + 1] == 0) {
							num[i][j + 1] = num[i][j];
							num[i][j] = 0;
							t = 1;
						}
					}
				}
			}
			//��֤��Ϸ�Ƿ����
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					a[i][j] = num[i][j];
				}
			} 
			if (test()) {
				endWay = false;
				break;
			}
			//������֤��Ϸ�Ƿ���� 
			end = 2;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (num[i][j] >= end) {
						end = num[i][j];
					}
				}
			}
			
		}
		system("cls");
		cout << "\t\t2048" << endl;
		cout << "**********************************************" << endl;
		if (endWay) {
			cout << "You Win!" << endl;
		}
		else {
			cout << "You lose!" << endl;
		}
		cout << "Your final score:" << score << endl;
		if (score > theHighestScore) {
			theHighestScore = score;
		}
		fp = fopen("E:\\record.txt", "w");
		fwrite(&theHighestScore, sizeof(int), 1, fp);
		fclose(fp);
		cout << "Play again?(press SPACE to exit)" << endl;
		again = _getch();
	}
	system("cls");
	cout << "SEE YOU!" << endl;
	system("pause");
	return 0;
}


bool test() {
	int t = 0;
				for (int j = 0; j < 4; j++) {
					for (int i = 3; i >= 1; i--) {
						if (a[i][j] != 0 && a[i - 1][j] == 0) {
							a[i - 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 3; i >= 1; i--) {
						if (a[i][j] != 0 && a[i - 1][j] == 0) {
							a[i - 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 3; i >= 1; i--) {
						if (a[i][j] != 0 && a[i - 1][j] == 0) {
							a[i - 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					int flag = 0;
					for (int i = 1; i <= 3; i++) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (a[i][j] == a[i - 1][j] && a[i][j] != 0) {
							a[i - 1][j] *= 2;
							a[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					for (int i = 3; i >= 1; i--) {
						if (a[i][j] != 0 && a[i - 1][j] == 0) {
							a[i - 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 3; j >= 1; j--) {
						if (a[i][j] != 0 && a[i][j - 1] == 0) {
							a[i][j - 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 3; j >= 1; j--) {
						if (a[i][j] != 0 && a[i][j - 1] == 0) {
							a[i][j - 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 3; j >= 1; j--) {
						if (a[i][j] != 0 && a[i][j - 1] == 0) {
							a[i][j - 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					int flag = 0;
					for (int j = 1; j <= 3; j++) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (a[i][j] == a[i][j - 1] && a[i][j] != 0) {
							a[i][j - 1] *= 2;
							a[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 3; j >= 1; j--) {
						if (a[i][j] != 0 && a[i][j - 1] == 0) {
							a[i][j - 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i <= 2; i++) {
						if (a[i][j] != 0 && a[i + 1][j] == 0) {
							a[i + 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 0; i <= 2; i++) {
						if (a[i][j] != 0 && a[i + 1][j] == 0) {
							a[i + 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int i = 0; i <= 2; i++) {
						if (a[i][j] != 0 && a[i + 1][j] == 0) {
							a[i + 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}	
				for (int j = 0; j < 4; j++) {
					int flag = 0;
					for (int i = 2; i >= 0; i--) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (a[i][j] == a[i + 1][j] && a[i][j] != 0) {
							a[i + 1][j] *= 2;
							a[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i <= 2; i++) {
						if (a[i][j] != 0 && a[i + 1][j] == 0) {
							a[i + 1][j] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j <= 2; j++) {
						if (a[i][j] != 0 && a[i][j + 1] == 0) {
							a[i][j + 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 0; j <= 2; j++) {
						if (a[i][j] != 0 && a[i][j + 1] == 0) {
							a[i][j + 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
					for (int j = 0; j <= 2; j++) {
						if (a[i][j] != 0 && a[i][j + 1] == 0) {
							a[i][j + 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					int flag = 0;
					for (int j = 2; j >= 0; j--) {
						if (flag == 1) {
							flag = 0;
							continue;
						}
						if (a[i][j] == a[i][j + 1] && a[i][j] != 0) {
							a[i][j + 1] *= 2;
							a[i][j] = 0;
							flag = 1;
							t = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j <= 2; j++) {
						if (a[i][j] != 0 && a[i][j + 1] == 0) {
							a[i][j + 1] = a[i][j];
							a[i][j] = 0;
							t = 1;
						}
					}
				}
				if (t == 0) {
					return true;
				}
				else {
					return false;
				}
}
