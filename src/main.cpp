#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}


namespace Original{
    std::vector<int> CreateFibonacciSequence( int n, int a1, int a2 ){
        std::vector<int> sequence( n );

        sequence[0] = a1;
        sequence[1] = a2;

        for( int i = 2; i < n; i++ ){
            sequence[i] = sequence[i - 1] + sequence[i - 2];
        }
    return sequence;
    }
}

int main( int argc, char** argv ){
    int n, a1, a2;
    cin >> n >> a1 >> a2;

    auto fibonacci = Original::CreateFibonacciSequence( n, a1, a2 );

    for( int i = 0; i < n; i++ ){
        cout << fibonacci[i] << flush;
        if( i != n - 1 ) cout << " " << flush;
    }
    cout << endl;
return 0;
}
