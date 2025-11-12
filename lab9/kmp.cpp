#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Функция для построения массива lps (longest prefix suffix)
// lps[i] = длина самого длинного собственного префикса, который также является суффиксом для подстроки pat[0..i]
void constructLps(string &pat, vector<int> &lps) {
    
    // len хранит длину самого длинного префикса, который
    // также является суффиксом для предыдущего индекса
    int len = 0;
    
    // lps[0] всегда равен 0, так как для одного символа нет собственного префикса-суффикса
    lps[0] = 0;
    
    int i = 1;
    while (i < pat.length()) {
        
        // Если символы совпадают, увеличиваем размер lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        
        // Если символы не совпадают
        else {
            if (len != 0) {
                
                // Обновляем len до предыдущего значения lps
                // чтобы избежать избыточных сравнений
                len = lps[len - 1];
            }
            else {
                
                // Если совпадающий префикс не найден, устанавливаем lps[i] в 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Функция для поиска всех вхождений шаблона в тексте
vector<int> search(string &pat, string &txt) {
    int n = txt.length();  // длина текста
    int m = pat.length();  // длина шаблона
    
    vector<int> lps(m);    // массив для longest prefix suffix
    vector<int> res;       // результат - индексы вхождений
    
    // Строим lps массив для шаблона
    constructLps(pat, lps);
    
    // Указатели i и j для прохода по
    // тексту и шаблону соответственно
    int i = 0;  // индекс для текста
    int j = 0;  // индекс для шаблона
    
    while (i < n) {
        
        // Если символы совпадают, двигаем оба указателя вперед
        if (txt[i] == pat[j]) {
            i++;
            j++;
            
            // Если весь шаблон совпал
            // сохраняем начальный индекс в результат
            if (j == m) {
                res.push_back(i - j);
                
                // Используем LPS предыдущего индекса чтобы
                // пропустить ненужные сравнения
                j = lps[j - 1];
            }
        }
        
        // Если символы не совпадают
        else {
            
            // Используем значение lps предыдущего индекса
            // чтобы избежать избыточных сравнений
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";
    
    // Ищем все вхождения шаблона в тексте
    vector<int> res = search(pat, txt);
    
    // Выводим результаты
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    
    return 0;
}