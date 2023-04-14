/* 2251647 ¹ú07 ÕÅ¿­ */
void base_print(int hang, int lie, int a[9][9]);
void search_2(int hang, int lie, int h_1, int l_1, int h_2, int l_2, int a[9][9]);
int judge(int hang, int lie, int h_1, int l_1, int h_2, int l_2, int a[9][9]);
void base_game(int hang, int lie, int a[9][9]);
int clean(int a[9][9], int hang, int lie, int* p);
int if_over(int hang, int lie, int a[9][9]);