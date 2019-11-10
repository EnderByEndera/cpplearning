/**
 * @author Chen Songyue
 * @file 2017221101017.cpp UTF-8
 * @date 2019-11-08 -- 2019-11-10
 * @version 1.2
 * @brief cpp homework 1
 * 
 * <p>
 ****************************************************************************
 * DESCRIPTION:                                                             *
 * This is the final version of my C++ homework after three days' torture   * 
 * by Address Sanitizer. lol~~~                                             *
 *                                                                          *
 * In my homework, there are only three functions copied from our teacher   *
 * Mr. Bai Zhongjian's cstring.cpp file. Others are all written by myself.  *
 * I 'm grateful to give my sincere thanks to my teacher. Thanks for your   *
 * dedicating teaching so that I can have a better understanding of         *
 * C++ language.                                                            *
 *                                                                          *
 * At last, int main() function is included in this cpp file, I don't know  *
 * how I can deal with this, so I put it underneath all the things I wrote. *
 * Hope that anyone who read this comment can understand what I mean.       *
 ****************************************************************************
 * </p>
 */

#include <iostream>

/**
 * @class cstring ~/cpp/2017221101017.cpp
 * @author Chen Songyue
 * @brief This is the cstring class for overloading
 * 
 * <br> 
 * In my version, I've created six constructors including:
 *      cstring();
 *      cstring(const cstring & cstr);
 *      cstring(char character);
 *      cstring(char* str);
 *      cstring();
 *      cstring(const char* str);
 * 
 * Moreover, I've written all the operator overloading functions which 
 * our homework asks for, including:
 *      cstring & operator+ (cstring & cstr, std::m_string str);
 *      cstring   operator+ (cstring & cstr1, cstring & cstr2);
 *      cstring & operator+ (cstring & cstr, char & character);
 *      cstring   operator+= (cstring & cstr1, cstring & cstr2);
 *      char* operator* (cstring & cstr);
 *      std::ostream & operator<< (std::ostream & os, cstring & cstr);
 * 
 * And also, destructor: 
 *      ~cstring();
 * is written below all the constructors
 * 
 * Three functions copied from cstring.cpp file are:
 *      size_t _strlen(char* s);
 *      void _strcpy(unsigned char* t, const unsigned char* s);
 *      void _copy(unsigned char* s);
 * I had to say I was really sorry for copying, but unless I had no idea 
 * how I could deal with copy operation, I would've never copied anything 
 * from others' work.
 */
class cstring
{

private:
    /**
     * @brief length of metadata in cstring
     */
    size_t *m_len;

    /**
     * @brief metadata of cstring
     */
    unsigned char *m_string;

public:
    /// I: copied function from cstring.cpp

    /**
     * @brief return length of the input char array
     * @author Bai Zhongjian
     * @param s input char array
     * @return size_t, length of the input array
     */
    size_t _strlen(char *s)
    {
        char *t = const_cast<char *>(s);
        while (*t)
            ++t;
        return t - s;
    }

    /**
     * @brief copy one m_string to another
     * @author Bai Zhongjian
     * @param t char array copied to
     * @param s char array copied from
     * @warning if length of t and s is not equal, may occur error
     */
    void _strcpy(unsigned char *t, const unsigned char *s)
    {
        while ((*t++ = *s++))
            ;
    }

    /**
     * @brief copy function to pack _strcpy func
     * @author Bai Zhongjian
     * @param s char array copied from
     * @warning m_string is renewed inside the function, might occur memory 
     *          leak if not deleted
     */
    void _copy(unsigned char *s)
    {
        m_string = new unsigned char[_strlen((char *)s) + 1];
        _strcpy(m_string, s);
    }

    /// II: constructors and destructor

    /**
     * @brief cstring constructor to create cstring class having one char
     * @author Chen Songyue
     * @param character char, metadata to store in cstring, only one char
     */
    cstring(char character)
    {
        m_string = new unsigned char[2];
        m_string[0] = character;
        m_string[1] = '\0';
        m_len = new size_t(1);
    }

    /**
     * @brief cstring constructor to create cstring class storing char[]
     * @author Chen Songyue
     * @param str char*, metadata stored in cstring class
     */
    cstring(char *str)
    {
        int &&i = 0;
        while (str[i] != '\0')
        {
            i++;
        }
        m_len = new size_t(i);
        _copy((unsigned char *)str);
    }

    /**
     * @brief cstring constructor to create cstring class storing const char[]
     * @author Chen Songyue
     * @param str const char*, metadata stored in cstring class
     */
    cstring(const char *str)
    {
        int &&i = 0;
        while (str[i] != '\0')
        {
            i++;
        }
        m_len = new size_t(i);
        _copy((unsigned char *)str);
    }

    /**
     * @brief cstring constructor to create cstring class storing null string
     * @author Chen Songyue
     * @warning may need to delete[] string first when use this constructor
     */
    cstring()
    {
        m_len = new size_t(0);
        m_string = new unsigned char[1];
        m_string[0] = '\0';
    }

    /**
     * @brief cstring constructor to create cstring from another cstring
     * @author Chen Songyue
     * @param cstr const cstring&, lvalue reference including metadata 
     * @warning can be only invoked when lvalue is used
     */
    cstring(const cstring &cstr)
    {
        m_len = new size_t();
        *m_len = *(cstr.m_len);
        _copy(cstr.m_string);
    }

    /**
     * @brief cstring constructor for transforming to another cstring param
     * @author Chen Songyue
     * @param cstr cstring&&, rvalue reference including metadata
     * @warning need to identify last constructor, invoked when rvalue used
     */
    cstring(cstring &&cstr)
    {
        m_string = cstr.m_string;
        m_len = cstr.m_len;
        cstr.m_len = nullptr;
        cstr.m_string = nullptr;
    }

    /**
     * @brief cstring destructor
     * @author Chen Songyue
     */
    ~cstring()
    {
        delete m_len;
        delete[] m_string;
        m_string = nullptr;
    }

    /**
     * @brief to judge whether the data stored in cstring is null or not
     * @author Chen Songyue
     * @return true if is null, false if not null
     */
    bool is_null() const
    {
        if (*m_len == 0)
        {
            return true;
        }
        else
            return false;
    }

    /**
     * @brief function returning m_string param's length
     * @author Chen Songyue
     * @return m_len straightfully
     */
    size_t size() const
    {
        return *m_len;
    }

    /**
     * @brief substr function getting sub-string from the m_string param
     * @author Chen Songyue
     * @param begin_position start char position to sub-string
     * @param char_num length of sub-string
     * @return cstring storing sub-string metadata
     */
    cstring substr(size_t &&begin_position, size_t &&char_num)
    {
        if (begin_position >= *m_len || begin_position + char_num >= *m_len)
            throw std::out_of_range("Out of Range!");
        cstring cstr;
        delete[] cstr.m_string;
        cstr.m_string = new unsigned char[char_num + 1];
        for (int i = 0; i < char_num; i++)
        {
            cstr.m_string[i] = m_string[begin_position + i];
        }
        cstr.m_string[char_num] = '\0';
        delete cstr.m_len;
        cstr.m_len = new size_t(char_num);
        return cstr;
    }

    /// III: operator overloading functions, including friend and member

    /**
     * @brief operator= to copy metadata from lvalue cstring
     * @author Chen Songyue
     * @param cstr const cstring&, lvalue reference which metadata is from
     * @return cstring anonymous rvalue storing metadata cstr has
     */
    cstring &operator=(const cstring &cstr)
    {
        delete[] m_string;
        _copy(cstr.m_string);
        *m_len = *cstr.m_len;
        return *this;
    }

    /**
     * @brief operator= to copy metadata rvalue cstring
     * @author Chen Songyue
     * @param cstr cstring&&, rvalue reference which metadata from
     * @return cstring anonymous rvalue storing metadata cstr has
     */
    cstring &operator=(cstring &&cstr)
    {
        std::swap(m_string, cstr.m_string);
        std::swap(m_len, cstr.m_len);
        return *this;
    }

    /**
     * @brief operator= to put one char to lvalue cstring
     * @author Chen Songyue
     * @param character char&, lvalue reference char which is metadata
     * @return cstring&, cstring lvalue storing input character
     */
    cstring &operator=(char &character)
    {
        delete[] m_string;
        m_string = new unsigned char[1];
        m_string[0] = character;
        *m_len = 1;
        return *this;
    }

    /**
     * @brief operator[] to return one char from cstring's metadata
     * @author Chen Songyue
     * @param char_num int, position of the character
     * @return unsigned char&, lvalue from metadata of cstring
     * @exception out_of_range raised when char_num >= cstring.len
     */
    unsigned char &operator[](int char_num) try
    {
        if (char_num >= *m_len)
            throw std::out_of_range("Out of Range");
        return m_string[char_num];
    }
    catch (const char *errmsg)
    {
        static unsigned char c;
        static unsigned char &rc = c;
        std::cout << errmsg << std::endl;
        return rc;
    }

    /**
     * @brief operator() to return checksum of one cstring
     * @author Chen Songyue
     * @return checksum of one cstring(sum of all chars from metadata in ASCII)
     */ 
    int &operator()()
    {
        int &&result = 0;
        for (int i = 0; i < *m_len; i++)
        {
            result += (int)m_string[i];
        }
        return result;
    }

    /// friend functions of operator overloading func
    friend cstring operator+(cstring &cstr, std::string str);
    friend cstring operator+(std::string str, cstring &cstr);
    friend cstring operator+(cstring &cstr1, cstring &cstr2);
    friend cstring operator+(cstring &cstr, char &character);
    friend cstring operator+=(cstring &cstr1, cstring &&cstr2);
    friend unsigned char *operator*(cstring &cstr);
    friend std::ostream &operator<<(std::ostream &os, cstring &cstr);
};

/**
 * @brief operator+ func to add another str to cstring metadata
 * @author Chen Songyue
 * @param cstr cstring on left of +
 * @param str std::string on right of +
 * @return anonymous cstring param storing metadata including all
 */ 
cstring operator+(cstring &cstr, std::string str)
{
    cstring result;
    size_t length = *cstr.m_len + str.size();
    result.m_string = new unsigned char[length + 1];
    for (int i = 0; i < *cstr.m_len; i++)
    {
        result[i] = cstr[i];
    }
    for (int i = *cstr.m_len; i < length; i++)
    {
        result[i] = str[i - *cstr.m_len];
    }
    result.m_string[length] = '\0';
    *result.m_len = length;
    return result;
}

/**
 * @brief opertator+ func to add another str to cstring metadata
 * @author Chen Songyue
 * @param str std::string on left of +
 * @param cstr cstring on right of +
 * @return anonymous cstring param storing metadata including all
 */ 
cstring operator+(std::string str, cstring &cstr)
{
    cstring result;
    size_t length = *cstr.m_len + str.size();
    result.m_string = new unsigned char[length + 1];
    for (int i = 0; i < *cstr.m_len; i++)
    {
        result[i] = cstr[i];
    }
    for (int i = *cstr.m_len; i < length; i++)
    {
        result[i] = str[i - *cstr.m_len];
    }
    result.m_string[length] = '\0';
    *result.m_len = length;
    return result;
}

/**
 * @brief operator+ func to add two cstring's metadatas
 * @author Chen Songyue
 * @param cstr1 cstring on left of +
 * @param cstr2 cstring on right of +
 * @return anonymous cstring param storing metadata including all
 */ 
cstring operator+(cstring &cstr1, cstring &cstr2)
{
    cstring result;
    delete[] result.m_string;
    result.m_string = new unsigned char[*cstr1.m_len + *cstr2.m_len + 1];
    for (int i = 0; i < *cstr1.m_len; i++)
    {
        result.m_string[i] = cstr1[i];
    }
    for (int i = *cstr1.m_len; i < *cstr1.m_len + *cstr2.m_len; i++)
    {
        result.m_string[i] = cstr2[i - *cstr1.m_len];
    }
    result.m_string[*cstr1.m_len + *cstr2.m_len] = '\0';
    *result.m_len = *cstr1.m_len + *cstr2.m_len;
    return result;
}

/**
 * @brief operator+ func to add one char to one cstring
 * @author Chen Songyue
 * @param cstr cstring to be added
 * @param character one char needs to add to
 * @return anonymous cstring param storing metadata added 
 */ 
cstring operator+(cstring &cstr, char &character)
{
    cstring result;
    result.m_string = new unsigned char[*cstr.m_len + 2];
    for (int i = 0; i < *cstr.m_len; i++)
    {
        result[i] = cstr[i];
    }
    result[*cstr.m_len] = character;
    result[*cstr.m_len + 1] = '\0';
    *result.m_len = *cstr.m_len + 1;
    return result;
}

/**
 * @brief operator+= func to put two cstring together
 * @author Chen Songyue
 * @param cstr1 cstring on left of +=
 * @param cstr2 cstring on right of +=
 * @return anonymous cstring param storing metadata including all
 */ 
cstring operator+=(cstring &cstr1, cstring &&cstr2)
{
    cstring result;
    delete[] result.m_string;
    result.m_string = new unsigned char[*cstr1.m_len + *cstr2.m_len + 1];
    for (int i = 0; i < *cstr1.m_len; i++)
    {
        result.m_string[i] = cstr1[i];
    }
    for (int i = *cstr1.m_len; i < *cstr1.m_len + *cstr2.m_len; i++)
    {
        result.m_string[i] = cstr2[i - *cstr1.m_len];
    }
    result.m_string[*cstr1.m_len + *cstr2.m_len] = '\0';
    *result.m_len = *cstr1.m_len + *cstr2.m_len;
    return result;
}

/**
 * @brief operator* to return cstring's m_string pointer
 * @author Chen Songyue
 * @param cstr cstring lvalue reference, input of operator* func
 * @return unsigned char*, m_string's pointer
 * @exception if m_string == nullptr, out_of_range exception will be thrown
 */ 
unsigned char *operator*(cstring &cstr) try
{
    if (cstr.m_string == nullptr)
        throw std::out_of_range("m_string nullptr");
    else
        return cstr.m_string;
} catch (const char* errmsg) {
    unsigned char* err = new unsigned char[1];
    err[0] = '\0'; 
    std::cout << errmsg << std::endl;
    return err;
}

/**
 * @brief operator<< to put cstring's metadata into std::ostream
 * @author Chen Songyue
 * @param os ostream for cstring's metadata to store in
 * @param cstr cstring whose metadata is to be put into ostream
 * @return lvalue reference of std::ostream
 */ 
std::ostream &operator<<(std::ostream &os, cstring &cstr)
{
    os << *cstr;
    return os;
}

/// This is the test code, DO NOT DELETE OR CHANGE ANY CONTENT!!!
int main()
{
    char buf[1024];
    std::cin >> buf;
    cstring s1(buf);
    std::cin >> buf;
    cstring s2(buf);

    s1[6] = 'A';

    cstring s3 = 'B';

    s3 = (s1 + s2).substr(7, s2.size());
    std::cout << s1 << *s3 << ' ' << s3();

    return 0;
}