#include <bits/stdc++.h>
#include <vector>

using namespace std;
int num_palavras=0;
class Trie {
public:
    /** Inicializando classe trie (apenas para caracteres minúsculos) */
    Trie *filhos[26];
    vector<int> index;
    string WORD;
    int words;
    /** retorna o valor do char, sendo a=; b=1; etc*/
    int value(char c){
        return c-'a';
    }
    /** iniciando Trie */
    Trie() {
        for(int i = 0; i<26; i++)
            filhos[i] = NULL;
            index.begin();
        words = 0;
    }

    /** Insere palavra na Trie */
    void insert(const string &word, int i = 0) {
        if( i>= word.size() ) {
            num_palavras++;
            index.push_back(num_palavras);
            WORD = word;
            words++;
            return;
        }
        int id = value( word[i] );
        if(filhos[id] == NULL) filhos[ id ]= new Trie();
        filhos[id]->insert(word, i+1);
    }

    /** Returns if the word is in the trie. */
    bool search(const string word, int i = 0) {
        if( i>= word.size() ) {
            return words;
        }
        int id = value( word[i] );
        if (filhos[ id ]== NULL) return 0;
        else return filhos[id]->search(word, i+1);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string word, int i = 0) {
        if( i>= word.size() ) return 1;
        int id = value( word[i] );
        if (filhos[ id ]== NULL) return 0;
        else return filhos[id]->startsWith(word, i+1);
    }
    void Index (int i = 0){
        if(filhos[i]!=NULL &&  !index.empty()){
            cout << WORD << ": ";
            for (auto n = index.begin(); n != index.end(); ++n)
                cout << *n << " ";
            cout << endl;
        }else if (filhos[i]!=NULL)
            return filhos[i]->Index();
         if(i<26)
            return Index(i+1);
    }

};

int main () {
    Trie *obj = new Trie();

    obj -> insert ("dbacaxi");
    obj -> insert ("cbk");
    obj -> insert ("dbacaxi");
    obj -> insert ("dbacaxi");

    obj->Index();

}
