#ifndef __MINIMAL_HPP
#define __MINIMAL_HPP

#include <iostream>
#include <cstring>

#define signature cout <<  GREEN <<  __PRETTY_FUNCTION__   << "\t" << __FILE__ << RESET << endl;
#define where cout <<  GREEN <<  __func__ << " @" << __LINE__  << RESET << endl;
#define abc cout <<  GREEN << "START (" << __func__ << " @" << __LINE__ << ")" << RESET << endl;
#define xyz cout <<  GREEN << "END (" << __func__ << " @" << __LINE__ << ")" << RESET << endl;
#define zout(...) {all_out (#__VA_ARGS__, __VA_ARGS__); cout <<  RED << " (" << __func__ << " @" << __LINE__ << ")" << RESET << endl;} 
#define zout2(x) cout << #x" = \n" << x <<  RED << " (" << __func__ << " @" << __LINE__ << ")" << RESET << endl;
#define jump cout << endl;
#define JUMP cout << endl << endl << endl;
//#define tab cout << "\t" ; //mauvaise idée d'appeler une macro tab. On peut vouloir appeler un tableau tab dans un programme.
#define ecris(x) cout << #x << endl;
#define debug(x) cout << CYAN << #x << " (" << __func__ << " @" << __LINE__ << ")" << RESET << endl;
#define titre(x) cout << BOLDBLUE << #x << RESET << endl;
#define green(x) cout << GREEN << #x << RESET << endl;
#define red(x) cout << RED << #x << RESET << endl;
#define yellow(x) cout << YELLOW << #x << RESET << endl;

#define grostitre(x) cout << BOLDCYAN << #x << " (" << __func__ << " @" << __LINE__ << ")" << RESET << endl;

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


using namespace std;


/** zout **/

// base case for template recursion when one argument remains
template <typename Arg1>
void all_out(const char* name, Arg1 arg1)
{
   cout << BOLDBLUE << name << " = \n" << RESET << arg1 ;
};

// recursive variadic template for multiple arguments
template <typename Arg1, typename... Args>
void all_out(const char* names, Arg1 arg1, Args... args)
{
    const char* comma = strchr(names, ',');
    cout << BOLDBLUE;
    cout.write(names, comma - names)  << " = \n" << RESET << arg1 << endl;
    all_out(comma + 1, args...);
};




#endif /* __MINIMAL_HPP */

