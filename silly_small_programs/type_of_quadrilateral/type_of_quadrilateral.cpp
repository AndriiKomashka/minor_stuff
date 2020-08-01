#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

float getSlope( float x1, float y1, float x2, float y2 )
{
    return x2 == x1 || y2 == y1 ?  0 : ( y2 - y1 ) / ( x2 - x1 );
}

float getDistance( float x1, float y1, float x2, float y2 )
{
    return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

vector< float > computeCircularlyOnPoints( vector< pair< int, int > > const& points, function< float ( float, float, float, float ) > func )
{
    vector< float > result;
    result.emplace_back( func( points[ 0 ].first, points[ 0 ].second, points[ 1 ].first, points[ 1 ].second ) );
    result.emplace_back( func( points[ 1 ].first, points[ 1 ].second, points[ 2 ].first, points[ 2 ].second ) );
    result.emplace_back( func( points[ 2 ].first, points[ 2 ].second, points[ 3 ].first, points[ 3 ].second ) );
    result.emplace_back( func( points[ 3 ].first, points[ 3 ].second, points[ 0 ].first, points[ 0 ].second ) );

    return result;
}

bool checkIfParallelogram( vector< pair< int, int > > const& points )
{
    vector< float > slopes( computeCircularlyOnPoints( points, getSlope ) );

    return ( slopes[ 0 ] == slopes[ 2 ] ) && ( slopes[ 1 ] == slopes[ 3 ] );
}

bool checkIfRectangle( vector< pair< int, int > > const& points )
{
    vector< float > slopes( computeCircularlyOnPoints( points, getSlope ) );

    bool isRectangle( false );

    if( 0 - slopes[ 1 ] )
        isRectangle = ( slopes[ 0 ] == ( 1 / ( 0 - slopes[ 1 ] ) ) );
    else
        isRectangle = ( slopes[ 0 ] == 0 );

    if( isRectangle )
    {
        if( 0 - slopes[ 2 ] )
            isRectangle = ( slopes[ 1 ] == ( 1 / ( 0 - slopes[ 2 ] ) ) );
        else
            isRectangle = ( slopes[ 1 ] == 0 );
    }

    return isRectangle;
}

bool checkIfRhombus( vector< pair< int, int > > const& points )
{
    vector< float > sides( computeCircularlyOnPoints( points, getDistance ) );

    return ( sides[ 0 ] == sides[ 2 ] ) && ( sides[ 1 ] == sides[ 3 ] ) && ( sides[ 0 ] == sides[ 1 ] );
}

string getQuadrilateralType( vector< pair< int, int > > const& points )
{
    const bool isParallelogram( checkIfParallelogram( points ) );

    if( isParallelogram )
    {
        const bool isRhombus( checkIfRhombus( points ) );
        const bool isRectangle( checkIfRectangle( points ) );

        if( isRhombus )
        {
            if( isRectangle )
                return "square";
            else
                return "rhombus";
        }
        else
        {
            if( isRectangle )
                return "rectangle";
            else
                return "parallelogram";
        }
    }
    else
        return "quadrilateral";
}

string getQuadrilateralTypeForPrint( vector< string > const& pointNames, string const& type )
{
    string toPrint;
    for_each( begin( pointNames ), end( pointNames ), [ &toPrint ] ( string const& name ) { toPrint += name; } );
    toPrint += " is a ";
    toPrint += type;
    toPrint += '.';

    return toPrint;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string A;
        int xA;
        int yA;
        string B;
        int xB;
        int yB;
        string C;
        int xC;
        int yC;
        string D;
        int xD;
        int yD;
        cin >> A >> xA >> yA >> B >> xB >> yB >> C >> xC >> yC >> D >> xD >> yD; cin.ignore();

        vector< string > pointNames = { A, B, C, D };
        vector< pair< int, int > > points = { make_pair( xA, yA ), make_pair( xB, yB ), make_pair( xC, yC ), make_pair( xD, yD ) };

        cerr << A << " " << xA << " " << yA << " " << B << " " << xB << " " << yB << " " << C << " " << xC << " " << yC << " " << D << " " << xD << " " << yD << endl;

        cout << getQuadrilateralTypeForPrint( pointNames, getQuadrilateralType( points ) ) << endl;
    }
}
