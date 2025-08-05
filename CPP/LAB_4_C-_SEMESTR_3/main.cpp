#include <iostream>
#include <string>
#include <chrono>

#include "Rabin_Karp.hpp"
#include "Knuth_Morris_Pratt.hpp"
#include "Boyer_Moore.hpp"
#include "Aho-corasick.hpp"
#include "z.hpp"


using namespace std;
//int naive(string str, string substr);
void test_rb_algorithm();
void test_kmp_algorithm();
void test_bm_algorithm();
void test_ah_corasick();
void test_z_algorithm();
void show_message();

int main() {
	setlocale(LC_ALL, "Russian");
	show_message();
	int chooses;
	cin >> chooses;
	switch (chooses) {
	case 1: {test_rb_algorithm(); break; }
	case 2: {test_kmp_algorithm(); break; }
	case 3: {test_bm_algorithm(); break; }
	case 4: {test_ah_corasick(); break; }
	case 5: {test_z_algorithm(); break; }
	}
	return 0;
}


//int naive(string str, string substr) {
//	int len_substr = substr.size();
//	for (int i = 0; i < str.size(); i++) {
//		int c = 0;
//		for (int j = 0, ij = i; j < len_substr; j++, ij++) {
//			if (str[ij] == substr[j])c++;
//			else break;
//		}
//		if (len_substr == c) {
//			return i;
//		}
//	}
//	return -1;
//}

void show_message() {
	cout << "1) Rabin_Karp\n" << "2) Knuth_Morris_Pratt\n" <<
		"3) Boyer_Moore\n" << "4) Aho_corasick\n" << "5) Z_func\n\n" << ">>";
}

void test_rb_algorithm() {
	string str = "All were white men.The average age was forty - two.Many of these men had been leaders during the American Revolution.About three - fourths of them had served in Congress.Most were leaders in their states.Some were rich, but most were not.None were poor.There were no native Americans among the delegates.There were no women.There were no black men or slaves.Poor farmers were not present either.George Washington, James Madison, and Benjamin Franklin were the three important delegates to the Convention.George Washington came from Virginia.He was probably the most respected man in the country.As the commander - in - chief of the American army during the Revolution, he was  great hero to most people.Then he had retired to his plantation and would have liked to remain there.However, his friends told him he should attend the convention.They said his support was necessary to get a new constitution accepted by the people.Since Washington thought a stronger national government was necessary, he came to Philadelphia";
	string substr = "Philadelphia";
	/*string str = "Ananas Apple Ahahahaha";
	string substr = "na";*/

	auto start_time = chrono::steady_clock::now();
	vector<int> pos2 = rb_find(str, substr);
	auto end_time = chrono::steady_clock::now();
	auto elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
	cout << "Rabin-Karp algorithm ->" << elapsed_ns.count() << " ns\n";

	for (int i = 0; i < pos2.size(); i++) {
		cout << i + 1 << " position:\n";
		cout << "begin --> " << pos2[i]<< endl;
		cout << "end --> " << pos2[i] + substr.size() << endl;
	}
}


void test_kmp_algorithm() {
	string str = "abcabcdabcabdc";
	string sub_str = "abcabdc";
	cout << kmp_find(str, sub_str);
}

//"abacabadabacaba";
void test_z_algorithm() {
	system("cls");
	cout << "Введите строку для выполнения Z функции:\n\n>>";
	string str = "abacabadabacaba";
	//cin >> str;
	system("cls");
	z_program(str);

	/*cout << "Поиск подстроки в строке: \n";*/
	
}

void test_bm_algorithm() {
	string str = "All were white men.The average age was forty - two.Many of these men had been leaders during the American Revolution.About three - fourths of them had served in Congress.Most were leaders in their states.Some were rich, but most were not.None were poor.There were no native Americans among the delegates.There were no women.There were no black men or slaves.Poor farmers were not present either.George Washington, James Madison, and Benjamin Franklin were the three important delegates to the Convention.George Washington came from Virginia.He was probably the most respected man in the country.As the commander - in - chief of the American army during the Revolution, he was  great hero to most people.Then he had retired to his plantation and would have liked to remain there.However, his friends told him he should attend the convention.They said his support was necessary to get a new constitution accepted by the people.Since Washington thought a stronger national government was necessary, he came to Philadelphia";
	string substr = "Philadelphia";
	auto start_time = chrono::steady_clock::now();
	bm_find(str, substr);
	auto end_time = chrono::steady_clock::now();
	auto elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
	cout << "Boyer_Moore ->" << elapsed_ns.count() << " ns\n";
}

void test_ah_corasick() {
	Trie Trie;
	/*string str = "asdasdasdasdasdhelloasdasdasdasd";
	string substr = "hello";*/
	string str = "allwerewhitementheaverageagewasfortytwomanyofthesemenhadbeenleadersduringtheamericanrevolutionaboutthreefourthsofthemhadservedincongressmostwereleadersintheirstatessomewererichbutmostwerenotnonewerepoortherewerenonativeamericansamongthedelegatestherewerenowomentherewerenoblackmenorslavespoorfarmerswerenotpresenteithergeorgewashingtonjamesmadisonandbenjaminfranklinwerethethreeimportantdelegatestotheconventiongeorgewashingtoncamefromvirginiahewasprobablythemostrespectedmaninthecountryasthecommanderinchiefoftheamericanarmyduringtherevolutionhewasgreatherotomostpeoplethenhehadretiredtohisplantationandwouldhavelikedtoremaintherehoweverhisfriendstoldhimheshouldattendtheconventiontheysaidhissupportwasnecessarytogetanewconstitutionacceptedbythepeoplesincewashingtonthoughtastrongernationalgovernmentwasnecessaryhecametophiladelphia";
	string substr = "philadelphia";
	int ans = Trie.find_substr(str, substr);
	for (int i = ans; i < ans + substr.size(); i++) {
		cout << str[i];
	}
}