#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

string print_menu()
{
    cout << "Vokabeltrainer\n";
    cout << "Bitte treffe eine Auswahl:\n";
    cout << "(1) Neue Vokabel hinzufügen\n";
    cout << "(2) Vokabeltest starten\n";
    string option;
    cin >> option;
    return option;
}

vector<string> loadTxtFile(string textFile)
{
    string str;
    ifstream in(textFile);
    vector<string> newVector;

    while (getline(in, str))
    {
        if (str.size() > 0)
            newVector.push_back(str);
    }

    return newVector;
}

void save_vector_to_txt_file(string fileName, vector<string> myVector)
{
    ofstream output_file(fileName);
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(myVector.begin(), myVector.end(), output_iterator);
}

void ask_word(vector<string> voc_german, vector<string> voc_spanish)
{
    cout << "Vokabeltest wird gestartet...\n";
    int random = rand() % voc_german.size();
    string sel_elem = voc_german[random];
    string sel_translation = voc_spanish[random];
    cout << "Bitte übersetze folgendes Wort: " + sel_elem + "\n";
    string userInput;
    cin >> userInput;
    if (userInput == sel_translation)
    {
        cout << "Alles richtig!\n";
    }
    else
    {
        cout << "Leider falsch\n";
    }
}

int main()
{
    vector<string> voc_german = loadTxtFile("voc_german.txt");
    vector<string> voc_spanish = loadTxtFile("voc_spanish.txt");
    ;

    string selection = print_menu();

    if (selection == "1")
    {
        cout << "welche Vokabel (Deutsch)?";
        string german_word;
        string spanish_word;
        cin >> german_word;
        cout << "Wie lautet die Übersetzung?";
        cin >> spanish_word;
        voc_german.push_back(german_word);
        voc_spanish.push_back(spanish_word);
        cout << "Vokabel wurde hinzugefügt.\n";
        cout << "Hinzugefügte Vokabeln: " + to_string(voc_german.size());

        save_vector_to_txt_file("./voc_german.txt", voc_german);
        save_vector_to_txt_file("./voc_spanish.txt", voc_spanish);
    }
    else
    {
        int i = 0;
        while (i < 10){
            ask_word(voc_german, voc_spanish);
            i++;
        }
    }

    return 0;
}