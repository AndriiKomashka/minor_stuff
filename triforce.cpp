#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();

    string currentLine;
    for( int line = 0; line < N; ++line )
    {
        currentLine.clear();
        
        if( !line )
            currentLine = ".";

        for( int i = 0; i < N * 2 - 1 - line; ++i )
            currentLine += ' ';

        if( !line )
            currentLine = currentLine.substr( 0, currentLine.size() - 1 );

        for( int i = 0; i < line * 2 + 1; ++i )
            currentLine += '*';

        cout << currentLine << endl;
    }

    for( int line = 0; line < N; ++line )
    {
        currentLine.clear();

        for( int i = 0; i < N - 1 - line; ++i )
            currentLine += ' ';

        for( int i = 0; i < line * 2 + 1; ++i )
            currentLine += '*';

        for( int i = 0; i < N * 2 - 1 - line * 2; ++i )
            currentLine += ' ';

        for( int i = 0; i < line * 2 + 1; ++i )
            currentLine += '*';

        cout << currentLine << endl;
    }
}
