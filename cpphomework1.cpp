 #include <iostream>

class cstring {
    private:
        int* len;
        char* string;
    public:

        /*
         * This is the constructor for cstring which needs rvalue char* constructor
         * use like this:
         * ```cpp
         * cstring* cstr = new cstring("Hello World");
         * ```
         */
        cstring(char* &&str) {
            int &&i = 0;
            while (str[i] != '\0') {
                i++;
            }
            *len = i;
            string = new char[*len];
            for (int i = 0; i < *len; i++) {
                string[i] = str[i];
            }
        }

        /**
         * This is the basic cstring constructor
         * you don't need to provide any params for this constructor
         * use like this:
         * ```cpp
         * cstring* cstr = new cstring();
         * ```
         */
        cstring() {
            *len = 0;
            string = "";
        }

        /**
         * This is the cstring destructor
         * It is invoked when one function is executed and all the params in
         * the function needs to be deleted.
         * I decided to delete all the params in the cstring
         * so that maybe cstring can be cleared
         */
        ~cstring() {
            delete string;
            delete len;
        }

        cstring(cstring &cstr) {
            
        }

};

 int main() {

 }