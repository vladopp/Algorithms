#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string message, alphabet, encrypted_message, key;
int *messageIndexes, *KeyIndexes, *EncrIndexes;
int len_alphabet, len_key, len_encr;

void swap_halves(string& str)
{
    int len=str.length();
    str = str.substr(len/2, len) + str.substr(0, len/2);
}

void indexes()
{
    KeyIndexes = new int[len_encr];
    EncrIndexes = new int[len_encr];
    messageIndexes = new int[len_encr];

    for(int i=0;i<len_encr;i++)
    {
        KeyIndexes[i] = alphabet.find(key[i]);
        EncrIndexes[i] = alphabet.find(encrypted_message[i]);

        messageIndexes[i] = EncrIndexes[i] - KeyIndexes[i];

        if(messageIndexes[i] < 0)
            messageIndexes[i] += len_alphabet;
    }
}

void crop()
{
    len_alphabet = atoi( message.substr( 0, message.find('~') ).c_str() );
    message.erase(0, message.find('~')+1);

    alphabet = message.substr(0, len_alphabet);
    message.erase(0, len_alphabet);

    len_key = atoi( message.substr( message.find('~')+1, message.length() ).c_str() );
    message.erase( message.find('~'), message.length() );

    key=message.substr(message.length()-len_key, len_key);
    message.erase(message.length()-len_key, len_key);

    encrypted_message = message;

    len_encr = encrypted_message.length();
    int Templen_key = len_key;

    while(Templen_key<len_encr)
    {
        key += key;
        Templen_key *= 2;
    }
    key.erase(len_encr, key.length());

    indexes();
}

int main()
{
    getline(cin,message);
    swap_halves(message);
    crop();

    for(int i=0; i<len_encr; i++)
    {
        cout << alphabet[messageIndexes[i]];
    }
    cout << endl;

    delete[] KeyIndexes;
    delete[] EncrIndexes;
    delete[] messageIndexes;
    return 0;
}
