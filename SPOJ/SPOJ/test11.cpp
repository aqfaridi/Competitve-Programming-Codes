#include <sstream>
#include <iostream>
#include <cstring>
using namespace std;
 
int main() {
            string str="";
                int a=10;
                ostringstream convert;
                convert<<a;
                str += convert.str();

                   // str +=(string)a;
                        cout<<str;
                            
                                return 0;
}
